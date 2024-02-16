//Attitude estimation algorithm


//Declaration of libraries
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <limits>

//Declaration of Data struct
struct Data {
    std::string timestamp;
    double x_axis;
    double y_axis;
    double z_axis;
};

int main() {
    //Creating minimum and maximum roll and pitch variables
    double min_roll = std::numeric_limits<double>::max();
    double max_roll = std::numeric_limits<double>::min();
    double min_pitch = std::numeric_limits<double>::max();
    double max_pitch = std::numeric_limits<double>::min();

    //Opening the data file
    std::ifstream input_file("attitude_exam.log");
    if (!input_file.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    //Creating the output file
    std::ofstream output_file("estimations.txt");
    if (!output_file.is_open()) {
        std::cerr << "Error creating the output file." << std::endl;
        return 2;
    }

    //Repeating the data extraction for every line of the file
    std::string line;
    while (std::getline(input_file, line)) {
        std::stringstream ss(line);
        std::string value;

        Data file_data;

        //Extracts the data into variables with the delimiter ";"
        //The axis values are converted to the double format, this type was chosen for its decimal precision and math compability
        std::getline(ss, file_data.timestamp, ';');
        std::getline(ss, value, ';');
        file_data.x_axis = std::stod(value);
        std::getline(ss, value, ';');
        file_data.y_axis = std::stod(value);
        std::getline(ss, value, ';');
        file_data.z_axis = std::stod(value);

        //Calculations according to aerospace rotation sequence
        double pitch = atan2(-file_data.x_axis, sqrt(file_data.y_axis * file_data.y_axis + file_data.z_axis * file_data.z_axis));
        double roll = atan2(file_data.y_axis, file_data.z_axis);

        //Conversion of the results units from radians to degrees;
        double pitch_degrees = pitch * 180.0 / M_PI;
        double roll_degrees = roll * 180.0 / M_PI;

        //Check if the current roll and pitch are smaller than the minimum or greater than the maximum, and if is true, updates its value
        if (roll_degrees < min_roll) {
        min_roll = roll_degrees;
        }
        if (roll_degrees > max_roll) {
            max_roll = roll_degrees;
        }
        if (pitch_degrees < min_pitch) {
            min_pitch = pitch_degrees;
        }
        if (pitch_degrees > max_pitch) {
            max_pitch = pitch_degrees;
        }

        //Writes the results in the output file separated by ";", with names and units
        output_file << "Pitch: " << pitch_degrees << "°; Roll: " << roll_degrees << "°; Timestamp: " << file_data.timestamp << " ms" << std::endl;

    }

    output_file << "Minimum roll: " << min_roll << " °" << std::endl;
    output_file << "Maximum roll: " << max_roll << " °" << std::endl;
    output_file << "Minimum pitch: " << min_pitch << " °" << std::endl;
    output_file << "Maximum pitch: " << max_pitch << " °" << std::endl;

    input_file.close();
    output_file.close();

    return 0;
}
