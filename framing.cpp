//#include "opencv2/videoio/videoio.hpp"
//#include "opencv2/video/video.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace cv;
char filename[80];

int main(){
cv::Mat frame;
cv::VideoCapture cap("/home/deep/rahim/Dataset/Eyediap/Data-Gaze/EYEDIAP1/1_A_CS_M/rgb_hd.mov");
/*
while(cap >> frame){
   if(frame.empty()){
      break;
   }
   counter++;
}
*/
if(!cap.isOpened()) cout << "Error can't find the file"<<endl;
else cout << "done";


int i=0;
while(1){
if(cap.read(frame))
	imshow("",frame);
    sprintf(filename,"/home/deep/rahim/Dataset/Eyediap/Data-Gaze/frames/EYEDIAP1/1_A_CS_M/hd/%05d.bmp",i);
    if (frame.empty()) break;
    else imwrite( filename,frame);
    cv::waitKey(33);
    i++;
}


return 0;
     }


