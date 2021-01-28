#include "facial_recognition.h"

void Detection(Mat& inputimage, CascadeClassifier &for_face, CascadeClassifier &for_eyes){

vector<Rect>faces,eyes;

Mat outputimage;

//outputimage.size() = 640 x 480
cv::resize(inputimage, outputimage, outputimage.size(),1, 1);

//Detects faces
for_face.detectMultiScale(inputimage, faces);

//faces.size() = Number of faces on the video or webcam
 for ( size_t i = 0; i < faces.size(); i++ )
    {
        // Color of the rectangle, in BGR format
        Scalar facecolor = Scalar(0, 255, 0);

        //Draws a rectangle, 3 is the intensity of the rectangle color
        rectangle( inputimage, cvPoint(cvRound(faces[i].x), cvRound(faces[i].y)),
                    cvPoint(cvRound((faces[i].x + faces[i].width)),
                    cvRound((faces[i].y + faces[i].height))), facecolor, 3);

        Mat ROI = outputimage(faces[i]);
        Point center;
        int radius;

        // color for the circles, Blue
        Scalar eyescolor = Scalar(255, 0, 0);

        for_eyes.detectMultiScale(ROI, eyes);

        // Draw circles around your eyes
        for ( size_t j = 0; j < eyes.size(); j++ )
        {

            center.x = cvRound((faces[i].x + eyes[j].x + eyes[j].width*0.5));
            center.y = cvRound((faces[i].y + eyes[j].y + eyes[j].height*0.5));
            radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
            circle( inputimage, center, radius, eyescolor, 3);
        }
    }

    imshow( "Detecting...", inputimage );
    waitKey(1);
}


