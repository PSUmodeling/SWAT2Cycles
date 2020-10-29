# SWAT2Cycles

SWAT2Cycles is a Python script that converts SWAT management files into Cycles operation files.

Contact: Yuning Shi [(Send Email)](mailto:yshi@psu.edu)

## INSTRUCTION

1. Prerequisites

   SWAT2Cycles script requires Python 3.x with Pandas and Numpy packages.

2. Prepare your SWAT management file

   Please save your SWAT scheduled management operations into a comma delimited file.
   A sample scheduled management operation file (`mgt2.csv`) can be found in the `data` directory.

   The code requires SWAT plant, tillage, and fertilizer databases (`plant.dat`, `till.dat`, and `fert.dat`), which are provided.

3. Convert management file

   You can specify multiple HRUs using an HRU list file:

   ```python
   python3 ./swat2cycles.py [-l HRU_LIST_FILE] [-f SWAT_MGT_FILE]
   ```

   or specify one HRU using:

   ```python
   python3 ./swat2cycles.py [-s SUBBASIN] [-u HRU] [-f SWAT_MGT_FILE]
   ```

   Note that the script will look for the SWAT management file in the `data` directory.

   An example HRU list file (`list.txt`) is provided.

   The converted Cycles operation files are named as SBxHRUy[LANDUSE], where `x` is the sub-basin index, `y` is the HRU index, and `LANDUSE` is the name of land use in the chosen HRU.
