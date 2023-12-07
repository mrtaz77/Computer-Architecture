import xml.etree.ElementTree as ET
import os

def parse_circ_file(file_path):
    tree = ET.parse(file_path)
    root = tree.getroot()

    wires_source_and_dest = []

    for wire_elem in root.iter('wire'):
        from_coord = wire_elem.get('from')[1:-1].split(',')
        to_coord = wire_elem.get('to')[1:-1].split(',')

        wires_source_and_dest.append((int(from_coord[0]), int(from_coord[1])))
        wires_source_and_dest.append((int(to_coord[0]), int(to_coord[1])))

    # print(wires_source_and_dest)

    return wires_source_and_dest

def count_wires(file_path):
    wires_source_and_dest = parse_circ_file(file_path)
    
    pair_count = {}
    
    for pair in wires_source_and_dest:
        if pair in pair_count:
            pair_count[pair] += 1
        else:
            pair_count[pair] = 1

    unique_count = sum(1 for count in pair_count.values() if count == 1)
    
    return unique_count // 2

# the file must be present in current directory
file_name = "final ALU.circ"

script_directory = os.path.dirname(os.path.abspath(__file__))
file_path = os.path.join(script_directory, file_name)
print(f"Number of wires : "+str(count_wires(file_path)))
