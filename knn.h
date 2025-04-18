#pragma once
#include <vector>
#include "Vector.h"

std::vector<size_t> knn(const std::vector<Vector> &trainData, const Vector &testData, int k);


unsigned int knn_predict(const std::pair<std::vector<Vector>, std::vector<Vector>> trainData, 
                          const Vector &testData, int k);

std::vector<unsigned int> knn_wrap(const std::pair<std::vector<Vector>, std::vector<Vector>> trainData, 
                          const std::vector<Vector> &testData, int k);