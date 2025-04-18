#include "knn.h"

std::vector<size_t> knn(const std::vector<Vector> &trainData, const Vector &testData, int k)
{

    std::vector<std::pair<float, unsigned int>> distances;
    for (unsigned int i = 0; i < trainData.size(); ++i)
    {
        float distance = testData.euclideanDistance(trainData[i]);
        distances.push_back(std::make_pair(distance, i));
    }
    std::sort(distances.begin(), distances.end());
    std::vector<size_t> neighbors;
    for (int i = 0; i < k; ++i)
    {
        neighbors.push_back(distances[i].second);
    }

    return neighbors;
}

unsigned int knn_predict(const std::pair<std::vector<Vector>, std::vector<Vector>> trainData, 
                          const Vector &testData, int k)
{
    std::vector<size_t> neighbors = knn(trainData.first, testData, k);

    // Voting
    Vector votes(neighbors.size());
    for (size_t i = 0; i < neighbors.size(); ++i)
    {
        votes.set(i, trainData.second[neighbors[i]].get(0));    
    }

    // Find the most common class
    votes.mean();
    if (votes.mean() > 0.5)
    {
        return 1; // Class 1
    }
    else
    {
        return 0; // Class 0
    }
}

std::vector<unsigned int> knn_wrap(const std::pair<std::vector<Vector>, std::vector<Vector>> trainData, 
                          const std::vector<Vector> &testData, int k)
{
    std::vector<unsigned int> predictions;
    for (const auto &test : testData)
    {
        predictions.push_back(knn_predict(trainData, test, k));
    }
    return predictions;
}