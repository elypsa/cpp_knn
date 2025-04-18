#pragma once
#include <vector>
#include <string>
#include "Vector.h"


class CSVReader {
    public:
        // Constructor to initialize the filename
        explicit CSVReader(const std::string& filename); 
    
        // Function to read the CSV file and store rows as vectors of floats
        std::vector<Vector> readCSV();
    
    private:
        std::string filename;
    
        // Helper function to parse a single line into a vector of floats
        Vector parseLine(const std::string& line);
};