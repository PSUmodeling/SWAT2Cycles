
SWAT2Cycles
===========

SWAT2Cycles is the code to convert SWAT management file into Cycles operation file.

Contact: Yuning Shi [(Send Email)](mailto:yshi@psu.edu)


INSTRUCTION:
------------

1. Prepare your SWAT management file

   Please save your SWAT scheduled management operations into a comma delimited file.
   A sample scheduled management operation file (`mgt.txt`) can be found in the `data` directory.
  
   The code requires SWAT plant, tillage, and fertilizer database (`plant.dat`, `till.dat`, and `fert.dat`), which are provided.
  
2. Install the code.

   Download the code from [the release page](https://github.com/shiyuning/SWAT2Cycles/releases).
   Put the code in your work directory and type `make`.

3. Convert management file

   To convert management opeartions within a certain subbasin and HRU, the syntax is
  
   ```shell
   $ ./swat2cycles [management_file] [subbasin] [hru]
   ```
  
   The converted Cycles operation file is named as sbXXXhruYYY, where XXX is the subbasin index and YYY is the HRU index.

   **EXAMPLE:**
    
   If you want to convert the operations within Subbasin 1, HRU 1 in the `mgt.txt`, you do

   ```shell
   $ ./swat2cycles data/mgt.txt 1 1
   ```
