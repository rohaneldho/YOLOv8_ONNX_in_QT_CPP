# YOLOv8 ONNX Integration with Qt - README

## Overview

This project demonstrates how to integrate a YOLOv8 model, converted to ONNX format, into a Qt application. The application performs object detection on images using the ONNX model and displays the results in a Qt GUI by converting `cv::Mat` images to `QImage`.

## Prerequisites

1. **Qt**: Ensure you have Qt installed.
2. **OpenCV**: Ensure you have OpenCV installed for image processing.
3. **Python (for model export)**: Ensure you have Python installed to convert the YOLOv8 model to ONNX.

## Steps to Set Up

### 1. Convert YOLOv8 Model to ONNX

First, you need to convert your YOLOv8 model to ONNX format. Use the following Python code snippet:

```python
# Assuming you have the YOLOv8 model loaded as `model`
model.export(format="onnx")
```

This will generate a `.onnx` file for your model. Place this file in the project directory or provide the appropriate path in your Qt application.

### 2. Set Up Qt Project

1. **Create a New Qt Project**: Open Qt Creator and create a new Qt Widgets Application project.
2. **Choose QMake option**
3. **KIT/Compiler**: use only MSVC using MINGW will give ERROR due to opencv otherwise use "opencv for mingw" download to work but no guarantees

### 2. Add OpenCV

1. **Install OpenCV**: Ensure OpenCV is installed on your system.
2. **Include OpenCV in the Project**: 
   - Add OpenCV include directories and libraries to your `.pro` file.
   - Make sure your project is configured to link against OpenCV.

### 3. Project Directory Structure

Ensure your project directory looks like this:

```
YourProject/
├── models/
│   └── yolov8.onnx
├── images/
│   └── input_image.jpg
├── src/
│   ├── main.cpp
│   ├── mainwindow.cpp
│   ├── mainwindow.h
│   └── mainwindow.ui
└── YourProject.pro
```

- **models/**: Contains the YOLOv8 ONNX model.
- **images/**: Contains input images for inference.
- **src/**: Contains the main application source code and UI files.
- **include/**: Contains ONNX Runtime header files.
- **libs/**: Contains ONNX Runtime libraries.

### 5. Implement Inference and Display Logic

1. **Perform Inference**: Implement the logic to perform inference on input images using the ONNX model.
2. **Display Results**: Convert the `cv::Mat` images to `QImage` and display them in the Qt application.

### 6. Build and Run the Project

1. **Build**: Compile your project in Qt Creator.
2. **Run**: Execute the application. It should load the ONNX model, perform object detection on the input image, and display the results in the GUI.

## Notes

- Ensure all dependencies are correctly linked and included.
- Modify the code and UI files as needed to adapt to your specific requirements.

## Troubleshooting

- **Model Path Issues**: Double-check the model and image paths in your code.
- **OpenCV Issues**: Verify OpenCV is correctly linked and included in your project.

## Contributing

Feel free to fork this repository and submit pull requests. For major changes, please open an issue first to discuss what you would like to change.

---

Enjoy building your object detection application with YOLOv8 and ONNX in Qt! If you encounter any issues, please refer to the ONNX Runtime documentation, Qt documentation, and OpenCV documentation for additional support.
