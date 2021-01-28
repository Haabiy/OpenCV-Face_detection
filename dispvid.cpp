#include "dispvid.h"

void dispvid(){

//object creation
VideoCapture video(CAP_ANY );

    if(!video.isOpened()){

        //reports an error
        cerr<<"Error starting video..."<<endl;
        exit(1);
    }


CascadeClassifier ffaces, eyes;


//Change the paths before execution
ffaces.load( "C:\\Users\\abiyh\\Desktop\\opencv\\build\\install\\etc\\haarcascades\\haarcascade_frontalface_default.xml" ) ;
eyes.load( "C:\\Users\\abiyh\\Desktop\\opencv\\source\\opencv-4.5.0\\data\\haarcascades\\haarcascade_eye.xml" ) ;

    for(;;){
        // create a frame and let read() read it
        Mat frame;
        video.read(frame);
        Detection(frame,ffaces, eyes);

    }


}
