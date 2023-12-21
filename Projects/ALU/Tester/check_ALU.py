import json
import os

out = ""

# from MSB to LSB
def get_number_from_binary_array(B):
    global out
    ans = 0
    for b in B:
        if(b>1 or b<0):
            out += 'Invalid Input'
            return -1
        ans *= 2
        ans += b
    return ans

def get_rows_of_truth_table(data):
    # Split the data into lines and remove leading/trailing whitespaces
    lines = [line.strip() for line in data.strip().split('\n')]

    # Extract the column names from the first line
    column_names = lines[0].split()

    # Initialize an empty list to store the dictionaries
    result = []

    # Process each data line and create a dictionary for each row
    for line in lines[1:]:
        values = line.split()
        row_dict = {column_names[i]: int(value) for i, value in enumerate(values)}
        result.append(row_dict)

    return result

def check_attribute_present(row, attr):
    global out
    if(attr not in row):
        out += '\nSorry! '+attr+ ' is not specified for this row'
        out += json.dumps(row,ndent=6)
        return False
    return True


def check_row(row, n_bits=4, n_control_bits=3):
    global out
    cs = []
    a = []
    b = []
    s = []
    if not check_attribute_present(row, 'Cout'):
        return 0
    s.append(row['Cout'])
    mx = max(n_bits, n_control_bits)
    for i in range(mx-1, -1, -1):
        if(i < n_control_bits):
            id = 'cs'+str(i)
            if not check_attribute_present(row, id):
                return 0
            cs.append(row[id])
        if(i < n_bits):

            id = 'A'+str(i)
            if not check_attribute_present(row, id):
                return 0
            a.append(row[id])

            id = 'B'+str(i)
            if not check_attribute_present(row, id):
                return 0
            b.append(row[id])

            id = 'S'+str(i)
            if not check_attribute_present(row, id):
                return 0
            s.append(row[id])

    control = get_number_from_binary_array(cs)
    A = get_number_from_binary_array(a)
    B = get_number_from_binary_array(b)
    S = get_number_from_binary_array(s)
    
    #out += control, A, B, )
    
    Y = 0
    
    if(control == 0):
        Y = A + 2**n_bits - 1
    if(control == 1):
        Y = A + 2**n_bits - B - 1
    if(control == 2):
        Y = A + 2**n_bits - 1
    if(control == 3):
        Y = 2**n_bits - A
    if(control == 4):
        Y = A + 2**n_bits - B
    if(control == 5):
        Y = A & B
    if(control == 6):
        Y = A ^ B
    if(control == 7):
        Y = A ^ B
    
    state = 1

    messages = []

    # moment of truth
    if(Y != S):
        messages.append('\nOutput Decimal Value (with considering Cout) should be ' + str(Y) + ', but output is '+ str(S) + '\n')
        # out += 'Cout = ', row[Cout'])
        state = -1

    # testing flags
    if(('C' in row) and row['C'] != row['Cout']):
        messages.append('\nCarry Flag is incorrect!')
        state = -1

    if(('S' in row) and row['S'] != row['S'+str(n_bits-1)]):
        messages.append('\nSign Flag is incorrect!')
        state = -1
    
    Z_expected = 1
    for i in range(n_bits):
        if(row['S'+str(i)] == 1):
            Z_expected = 0
    
    if(('Z' in row) and row['Z'] != Z_expected):
        messages.append('\nZero Flag is incorrect!')
        state = -1
    
    if('V' in row):
        if(control in [5,6,7]):
            if(row['C'] == 1 or row['V'] == 1):
                messages.append('\nOverflow Flag incorrect.\nC and V should be cleared (0) after AND/OR/XOR operation.')
        else:
            signed_A = A
            if(row['A'+str(n_bits-1)] == 1): # negative, so it is 2's complement
                signed_A = 2**n_bits - A
            
            signed_B = B
            if(row['B'+str(n_bits-1)] == 1): # negative, so it is 2's complement
                signed_B = 2**n_bits - B 

            A = signed_A
            B = signed_B

            if(control == 0):
                Y = A + 2**n_bits - 1
            if(control == 1):
                Y = A + 2**n_bits - B - 1
            if(control == 2):
                Y = A + 2**n_bits - 1
            if(control == 3):
                Y = 2**n_bits - A
            if(control == 4):
                Y = A + 2**n_bits - B

            overflowed = 0

            if((Y > 2**(n_bits-1)-1) or (Y < -2**(n_bits-1))):
                overflowed = 1
            
            if(row['V'] != overflowed):
                messages.append('Overflow bit incorrect')

    if(state == -1):
        out += '\n\nOops! Wrong output for control = '+str( control)+ ', A = '+ str(A)+ ', B = '+ str(B)
        for message in messages:
            out += message
    
    return state
    
# remove any last newline(if any) from txt file  
def read_truth_table(filename):
    with open(filename) as f:
        data = f.read()
    return data

script_directory = os.path.dirname(os.path.abspath(__file__))
file_path = os.path.join(script_directory, "truth_table.txt")

data = read_truth_table(file_path)
result = get_rows_of_truth_table(data)

#out += json.dumps(resut,indent=4))
#out += len(result))

errors = 0
corrupted = 0

for row in result:
    ret = check_row(row)
    if(ret == -1):
        errors += 1
    if(ret == 0):
        corrupted += 1
out += "\n"
if(errors == 0 and corrupted == 0):
    out += 'Congrats! All rows of the truth table are correct!'
if(corrupted != 0):
    out += 'Sorry! '+str(corrupted)+ ' rows of the truth table are corrupted. Maybe this is due to anomalous naming convention.\n'
    out += 'The followed convention:\n\nControl bits = cs0, cs1, cs2\nA = A0, A1 etc\nB = B0, B1 etc\nS = S0, S1 etc\nCout = Cout '
    if(errors == 0):
        out += '\n\nBut non-corupted rows are all correct!'
if(errors != 0):
    out += 'Sorry! '+str(errors)+ ' rows of the truth table are incorrect.'
out += "\n"

report_path = os.path.join(script_directory, "report.txt")

with open(report_path, "w") as f:
    f.write(out)