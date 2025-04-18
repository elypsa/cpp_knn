#pragma once
#include <vector>

class Vector {
    public:
        // Constructor to initialize the vector with a given size or values
        explicit Vector(size_t size);
        explicit Vector(const std::vector<float>& values);

    
        // Function to set a value at a specific index
        void set(size_t index, float value);

        // Function to get a value at a specific index
        float get(size_t index) const;

        // plus operator between two vectors
        Vector operator+(const Vector& other) const;

        // euclidean distance between two vectors
        float euclideanDistance(const Vector& other) const;

        float mean() const;
    
    private:
        std::vector<float> data;  // Internal storage for the vector
};