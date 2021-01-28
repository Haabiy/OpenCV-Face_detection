#include "dispvid.h"

void dispvid(){

VideoCapture video(CAP_ANY );

    if(!video.isOpened()){

        cerr<<"Error starting video..."<<endl;
        exit(1);
    }

CascadeClassifier cascade, nestedCascade;
double scale=1;

//Change paths before execution
nestedCascade.load( "C:\\Users\\abiyh\\Desktop\\opencv\\source\\opencv-4.5.0\\data\\haarcascades\\haarcascade_eye.xml" ) ;
cascade.load( "C:\\Users\\abiyh\\Desktop\\opencv\\build\\install\\etc\\haarcascades\\haarcascade_frontalface_default.xml" ) ;

    for(;;){
        // create a frame and let read() read it
        Mat frame;
        video.read(frame);
        Detect_face(frame,cascade, nestedCascade, scale);

    }


}
