#ifndef INFERENCE_H
#define INFERENCE_H

#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <random>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

struct Detection {
    float confidence;
    cv::Rect box;
    cv::Scalar color;
};

class Inference {
public:
    Inference(const std::string& onnxModelPath, const cv::Size& modelInputShape, const std::string& classesTxtFile, const bool& runWithCuda);

    std::vector<Detection> runInference(const cv::Mat& input);

private:
    void loadOnnxNetwork();
    cv::Mat formatToSquare(const cv::Mat& source);

    std::string modelPath;
    cv::Size modelShape;
    std::string classesPath;
    bool cudaEnabled;

    cv::dnn::Net net;

    bool letterBoxForSquare = true;
    float modelScoreThreshold = 0.5f;
    float modelNMSThreshold = 0.4f;
    float modelConfidenceThreshold = 0.5f;
};

#endif
