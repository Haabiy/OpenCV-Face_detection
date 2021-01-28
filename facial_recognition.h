#ifndef FACIAL_RECOGNITION_H
#define FACIAL_RECOGNITION_H

#include <iostream>
#include<vector>

#include <objdetect.hpp>
#include <highgui.hpp>
#include <imgproc.hpp>
#include <core//types_c.h>

using namespace cv;
using namespace std;

void Detect_face(Mat &image, cv::CascadeClassifier& forface, cv::CascadeClassifier &nested, double &scale );

#endif
