#include "Vector.h"
#include <iostream>
#include <vector>

Vector::Vector(size_t size) : data(size, 0.0f) {}
Vector::Vector(const std::vector<float> &values) : data(values) {}

void Vector::set(size_t index, float value)
{
    if (index < data.size())
    {
        data[index] = value;
    }
    else
    {
        std::cerr << "Error: Index out of bounds" << std::endl;
    }
}

// Function to get a value at a specific index
float Vector::get(size_t index) const
{
    if (index < data.size())
    {
        return data[index];
    }
    else
    {
        std::cerr << "Error: Index out of bounds" << std::endl;
        return 0.0f; // Default value for out-of-bounds access
    }
}

// plus operator between two vectors
Vector Vector::operator+(const Vector &other) const
{
    if (data.size() != other.data.size())
    {
        std::cerr << "Error: Vectors must be of the same size" << std::endl;
        return Vector(0); // Return an empty vector on error
    }
    Vector result(data.size());
    for (size_t i = 0; i < data.size(); ++i)
    {
        result.set(i, data[i] + other.get(i));
    }
    return result;
}

// euclidean distance between two vectors
float Vector::euclideanDistance(const Vector &other) const
{
    if (data.size() != other.data.size())
    {
        throw std::invalid_argument("Vectors must be of the same size");
    }
    float sum = 0.0f;
    for (size_t i = 0; i < data.size(); ++i)
    {
        float diff = data[i] - other.data[i];
        sum += diff * diff;
    }
    return std::sqrt(sum);
}

float Vector::mean() const
{
    float sum = 0.0f;
    for (const auto &value : data)
    {
        sum += value;
    }
    return sum / data.size();
}