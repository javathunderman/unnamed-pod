To simplify the accessing of values from the FPGA, they will be cached and updated periodically. This set of python scripts
creates the header file for the cache based on the input bit file and then will create the methods for interfacing through
the cache. This provides abstraction from session management and addresses while also managing FPGA access and session 
tracking.

### Usage
1. Write LabView FPGA Code
2. Compile to Produce Bitfile
3. Run the NI C API generator on the Bitfile to get the C header.
4. Run the ```fpga_api_gen.py``` python script and select the generated header and then the bitfile.
5. The FPGA cache code will now be generated.


Documentation happens here!
