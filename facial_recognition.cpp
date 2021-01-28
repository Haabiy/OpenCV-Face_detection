#include "facial_recognition.h"

void Detect_face(Mat& image, CascadeClassifier &forface, CascadeClassifier &nested, double &scale ){

vector<Rect>faces;

Mat outputimage, inputimage;
inputimage=image;

double fx = 1/scale;

cv::resize(inputimage, outputimage,outputimage.size(),fx,fx);

// from the opencv data
double scaleFactor = 1.1;
int minNeighbors = 3;
int flags=0;

//Detects faces
forface.detectMultiScale(inputimage, faces,scaleFactor, minNeighbors, flags, Size(5, 5));

//faces.size() = Number of faces on the video or webcam
 for ( size_t i = 0; i < faces.size(); i++ )
    {
        Rect rec = faces[i];
        // Color of the rectangle
        Scalar facecolor = Scalar(0, 255, 0);

        //Draws a rectangle
        rectangle( image, cvPoint(cvRound(rec.x*scale), cvRound(rec.y*scale)),
                    cvPoint(cvRound((rec.x + rec.width-1)*scale),
                    cvRound((rec.y + rec.height-1)*scale)), facecolor, 3, 8, 0);


        vector<Rect> nestedObjs;
        Mat smallImgROI;
        smallImgROI = outputimage(rec);
        int radius;
        // color for the circles
        Scalar eyescolor = Scalar(255, 0, 0);

        nested.detectMultiScale( smallImgROI, nestedObjs, 1.1, 2, 0 , Size(3, 3) );
        Point center;

        // Draw circles around your eyes
        for ( size_t j = 0; j < nestedObjs.size(); j++ )
        {
            Rect nrec = nestedObjs[j];
            center.x = cvRound((rec.x + nrec.x + nrec.width*0.5)*scale);
            center.y = cvRound((rec.y + nrec.y + nrec.height*0.5)*scale);
            radius = cvRound((nrec.width + nrec.height)*0.25*scale);
            circle( image, center, radius, eyescolor, 3, 8, 0 );

        }
    }

    imshow( "Face-Detection", image );
    waitKey(1);
}


