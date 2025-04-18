#include "CSVReader.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "Vector.h"

CSVReader::CSVReader(const std::string &filename) : filename(filename) {}

// Function to read the CSV file and store rows as vectors of floats
std::vector<Vector> CSVReader::readCSV()
{
    std::vector<Vector> data;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return data;
    }

    std::string line;
    while (std::getline(file, line))
    {
        Vector row = parseLine(line);
        data.push_back(row);
    }

    file.close();
    return data;
}

// Helper function to parse a single line into a vector of floats
Vector CSVReader::parseLine(const std::string &line)
{
    std::vector<float> row;
    std::stringstream ss(line);
    std::string value;

    while (std::getline(ss, value, ','))
    { // Split by comma
        try
        {
            row.push_back(std::stof(value)); // Convert string to float
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: Invalid float value in line: " << line << std::endl;
            row.push_back(0.0f); // Default value for invalid entries
        }
    };

    return Vector(row);
}
