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

//char * filename = new char[100];
//Mat featuresUnclustered;
//Mat descriptor;
//Mat input;
//cv::Mat output;
//Mat subImg;
//int SWno ;
//char * filename = new char[100];
char filename[80];

int main(){
cv::Mat frame;
//VideoCapture cap;
cv::VideoCapture cap("/home/deep/rahim/Dataset/Eyediap/Data-Gaze/EYEDIAP1/1_A_CS_M/rgb_vga.avi");
if(!cap.isOpened()) cout << "Error can't find the file"<<endl;
else cout << "done";


int i=0;
while(1){
if(cap.read(frame))
	imshow("",frame);
    sprintf(filename,"/home/deep/cuda-workspace/framing/frames/%05d.jpg",i);
    imwrite( filename,frame);
    cv::waitKey(33);
    i++;
}


return 0;
     }


