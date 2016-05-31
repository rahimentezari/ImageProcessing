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

char * filename = new char[100];
Mat featuresUnclustered;
Mat descriptor;
Mat input;
SiftDescriptorExtractor detector;
cv::Mat output;
Mat subImg;
int SWno ;

int main( int argc, char** argv )
{

    Mat img;
	VideoCapture cap;
	for(int i=0;i<1771;i++)
	{
		SWno =0 ;
		if(i%1771==0)cap =VideoCapture("/media/rahim/01D051E78FFCF7C0/Lab/Dataset/EyeHead/HPEG/HPEG/session_a/videos/faces/%05d.jpg");
		Mat img;
		cap >> img;

	    int rowsOrg = img.rows;
	    int colsOrg = img.cols;
	    cout << "rowsOrg = " << rowsOrg << "   " ;
	    cout << "colsOrg = " << colsOrg << " " << endl;
	    cout << "Entering Sliding Window Loop " << endl;
	    for(int r=0; r<rowsOrg-1; r=r+4)
	    {
	    	cout << "Row = " << r << endl;

		    for(int c=0; c<colsOrg-1; c=c+4)
		    {
		    	//cout << "c = " << c << endl;
		    	cout << "Row = " << r << "   "<< "Col = " << c << endl;

		    	if (c+8 <colsOrg+1 &&  r+8 <rowsOrg+1)
		    	{
		    		subImg = img(cv::Range(c, c+8), cv::Range(r, r+8));
		    	}
		    	vector<KeyPoint> keypoints ;
				detector.detect(subImg, keypoints);

				cv::drawKeypoints(subImg, keypoints, output);
			    char *imageName = "image";
			 	char *jpgN = ".jpg";

			 	stringstream s1;
			 	stringstream s2;
			 	stringstream s3;
			 	s3 << i;
			 	s1 << imageName << c ;
				s2 << "-" << r ;
				s1 << s2.str();
				s3 << s1.str();
				s3 << jpgN;
			 	cv::imwrite (s3.str(), output);

			 	detector.compute(subImg, keypoints,descriptor);
				featuresUnclustered.push_back(descriptor);


				SWno++;
				cout << "SWno = " << SWno << endl;
				cout << "Image Number =" << i << endl;

		    }
	    }
	cout << "\n image number: " << i;
	}
	printf("Clustering...");
	int dictionarySize=200;
	TermCriteria tc(CV_TERMCRIT_ITER,500,0.001);
	int retries=1;
	int flags=KMEANS_PP_CENTERS;
	BOWKMeansTrainer bowTrainer(dictionarySize,tc,retries,flags);
	Mat dictionary=bowTrainer.cluster(featuresUnclustered);
	FileStorage fs("dictionary-SlidingW.yml", FileStorage::WRITE);
	fs << "vocabulary" << dictionary;
	fs.release();

	cout << "\n Center of Clusters are Found!: " ;

	return 0;
}


