#include "mainwindow.h"
#include "opencv2/highgui.hpp"
#include <QApplication>
#include "opencv2/core/core.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/types_c.h"
#include <opencv2/gapi/own/mat.hpp>
#include <opencv2/core/mat.hpp>
#include "inference.h"
#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <QtGlobal>
#include <QLabel>


using namespace cv;
QImage Mat2QImage(const cv::Mat& mat) {
    // Convert the Mat to the appropriate QImage format
    if (mat.type() == CV_8UC1) {
        // Grayscale image
        QImage img(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Grayscale8);
        return img.copy();
    } else if (mat.type() == CV_8UC3) {
        // Color image
        QImage img(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return img.rgbSwapped(); // Convert BGR to RGB
    } else if (mat.type() == CV_8UC4) {
        // Alpha channel image
        QImage img(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return img.copy();
    } else {
        // Unsupported format
        return QImage();
    }
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Inference inference("path/to/your/model.onnx", cv::Size(640, 640), "", true);

    // Load an input image
    cv::Mat inputImage =  cv::imread("path/to/your/photo.jpg");
    if (inputImage.empty()) {
        std::cerr << "Error: Could not open or find the image!" << std::endl;
        return -1;
    }

    // Run inference
    std::vector<Detection> detections = inference.runInference(inputImage);

    // Check if detections are being made
    if (detections.empty()) {
        std::cout << "No detections were made." << std::endl;
    }
    else {
        std::cout << "Detections were made: " << detections.size() << std::endl;
    }

    // Process the detections
    for (const auto& detection : detections) {
        std::cout << "Confidence: " << detection.confidence << std::endl;
        cv::rectangle(inputImage, detection.box, detection.color, 2);
    }

    // Save or display the image with detections
    //cv::imwrite("output.jpg", inputImage);
    // cv::imshow("Detections", inputImage);
    QImage qImg = Mat2QImage(inputImage);
    QLabel label;
    label.setPixmap(QPixmap::fromImage(qImg));
    label.setWindowTitle("Detections");
    label.show();
    cv::waitKey(0);
    return a.exec();
}
