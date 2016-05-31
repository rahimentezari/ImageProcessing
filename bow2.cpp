
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
using namespace cv;
Mat dictionary;
SiftDescriptorExtractor Detector;
VideoCapture cap;
Mat img;
int main(int argc, char*argv[])
{


	for(int i=1;i<186;i++)
	{
		FileStorage fs("/home/rahim/workspace/BOW2/dictionary-SlidingW.yml", FileStorage::READ);
		fs["vocabulary"] >> dictionary;
		fs.release();
		Ptr<DescriptorMatcher> matcher(new FlannBasedMatcher);
		Ptr<FeatureDetector> detector(new SiftFeatureDetector());
		Ptr<DescriptorExtractor> extractor(new SiftDescriptorExtractor);
		BOWImgDescriptorExtractor bowDE(extractor,matcher);
		bowDE.setVocabulary(dictionary);
		char * filename = new char[100];
		char * imageTag = new char[10];
		FileStorage fs1("descriptorSW-a-9.yml", FileStorage::APPEND);
	    sprintf(filename,"/media/rahim/01D051E78FFCF7C0/Lab/Dataset/EyeHead/HPEG/HPEG/session_a/videos/face-s-a/9/%05d.jpg",i);
	    img = imread(filename, CV_LOAD_IMAGE_GRAYSCALE); //Load as grayscale

	    int rowsOrg = img.rows;
	    int colsOrg = img.cols;
	    //cout << "rowsOrg = " << rowsOrg << "   " ;
	    //cout << "colsOrg = " << colsOrg << " " << endl;
		//cout << "img = "<< endl << " "  << img << endl << endl;
		vector<KeyPoint> keypoints;
		Detector.detect(img,keypoints);
		Mat bowDescriptor;
		bowDE.compute(img,keypoints,bowDescriptor);
		FILE * pfile = fopen("SW-a-9.csv","a");
		for(int c=0;c<bowDescriptor.cols;c++)
		{
		    if(c!=(bowDescriptor.cols-1))
		        fprintf(pfile,"%f,",bowDescriptor.at<float>(0,c));
		    else
		        fprintf(pfile,"%f\n",bowDescriptor.at<float>(0,c));
		}
		sprintf(imageTag,"img1");
		fs1 << imageTag << bowDescriptor;
		fs1.release();
		cout << "\n image number: " << i << endl;
	}
}


