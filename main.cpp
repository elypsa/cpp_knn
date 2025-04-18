#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Vector.h"
#include "CSVReader.h"
#include "knn.h"

int main()
{
    // Read the CSV files
    CSVReader reader("features.csv");
    std::vector<Vector> features = reader.readCSV();

    CSVReader reader2("classes.csv");
    std::vector<Vector> classes = reader2.readCSV();

    std::vector<Vector> trainFeatures;
    trainFeatures.assign(features.begin(), features.begin() + 400);
    std::vector<Vector> trainClasses;
    trainClasses.assign(classes.begin(), classes.begin() + 400);
    std::pair<std::vector<Vector>, std::vector<Vector>> trainData = {trainFeatures, trainClasses};

    std::vector<Vector> testFeatures;
    testFeatures.assign(features.begin() + 400, features.end());
    std::vector<Vector> testClasses;
    testClasses.assign(classes.begin() + 400, classes.end());
    std::pair<std::vector<Vector>, std::vector<Vector>> testData = {testFeatures, testClasses};

    // Perform KNN classification
    std::vector<unsigned int> predictions = knn_wrap(trainData, testFeatures, 10);
    for (size_t i = 0; i < predictions.size(); ++i)
    {
        std::cout << "Predicted: " << predictions[i] << ", Actual: " << testClasses[i].get(0) << std::endl;
    }

    // Calculate accuracy
    int correct = 0;
    for (size_t i = 0; i < predictions.size(); ++i)
    {
        if (predictions[i] == testClasses[i].get(0))
        {
            correct++;
        }
    }
    float accuracy = static_cast<float>(correct) / predictions.size();
    std::cout << "Accuracy: " << accuracy * 100 << "%" << std::endl;

    return 0;
}