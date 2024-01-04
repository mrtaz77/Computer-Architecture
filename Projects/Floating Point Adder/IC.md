# Modules
1. [32 bit right shift with empty](#32-bit-right-shift-with-empty)
2. [20 to 32 bit Extractor With MSB Set](#20-to-32-bit-extender-with-msb-set)

## 32 bit right shift with empty
|IC|Function|Number OF ICs|Slots Used|Cost Explanation|
|-|-|-|-|-|
|744075|Triple-3-input-OR|1|Full|Checking whether difference of exponents > 31|
|32 bit right shifter|-|1|-|Shift smaller exponent right|
|32 bit 2 to 1 MUX|-|1|-|Choose the right shifted result or reset it|
||__Total__|__3__|||

## 20 to 32 bit Extender With MSB Set
No IC needed.