# Attitude Estimation

This C++ program can open a log file with data from a MMA8451 accelerometer and estimate the roll and pitch angles from the sensor readings, creating an output file with the estimations for all the readings and minimum and maximum values for pitch and roll.

# Implementation

The first step to solve this task was to carefully read all the documentation and understand what was being asked. Once it was done, the following step was to list everything the program needed to do and separate that into smaller tasks (open a file, read and parse the data, calculate the estimation and generating an output file). With the requirements defined, the environment was prepared and then began the implementation of the code. When all the steps were working, the process of refinement, code improvement, and documentation was initiated.

The code is relatively simple and can be segmented in smaller parts:

Declaration of libraries used in the code, fundamental to the use of the console inputs and outputs, files and strings manipulation and math operations;
Declaration of Data struct, to facilitate the organization and formatation of the data from the log file, with each line correponding to one struct instance;
Opening of the input file and creation of the output file;
Extration of the data from the file into variables;
Calculations according to aerospace rotation sequence to estimate roll and pitch;
Conversion of the results units from radians to degrees;
Writing of the results on the output file and ending of the program.

# Instructions

To compile and run this program, all you need to do is clone this repository, compile the program in a C++ compiler and run, providing the path to the log file. If any problem happen while opening the database, the program will warn. In case of problems with the path while trying to open the database file, try to put the file in the same folder as the program.

This program expects to receive the data in the format "time_stamp_ms; accel_x_axis; accel_y_axis; accel_z_axis". If the database file is in other format, you can change the program to receive the variables in a diferent order or type.

The final results are displayed in the degrees unit. If the desired unit is radians, you can simply remove the two lines that convert the data unit from radians to degrees.

C++ compiler and basic libraries are required.
