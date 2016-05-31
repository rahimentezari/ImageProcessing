#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<fstream>
#include <sstream>

using namespace std;
using namespace cv;



int main()
{
	ifstream inFile("yaw_4_a.txt");
	  if (!inFile)
	  {
			cerr << "File yaw_1_a.txt not found." << endl;
			return -1;
	  }
	  ofstream outFile("degree-yaw-a-4.txt");

	  string line;
	  while (getline(inFile, line))
	  {
			if (line.empty()) continue;

			// Using istringstream to read the line into integers.
			istringstream iss(line);
			int degree = 0, next = 0;
			while (iss >> next) degree += next;
			cout << degree << endl;
			if (-45 <degree && degree < -30)
			{
				degree = -45;
				outFile << degree << endl;
			}
			else if(-30 <= degree && degree <-15)
				{
					degree = -30;
					outFile << degree << endl;
				}
			else if(-15 <= degree && degree < 0)
				{
					degree = -15;
					outFile << degree << endl;
				}

			else if(0 <= degree && degree < 15)
				{
					degree = 0;
				    outFile << degree << endl;
				}
			else if(15 <= degree && degree <30)
				{
					degree = 15;
					outFile << degree << endl;
				}
			else if(30 <= degree && degree <45)
				{
					degree = 30;
					outFile << degree << endl;
				}
			else if(45 <= degree && degree <60)
				{
					degree = 45;
					outFile << degree << endl;
				}
	  }

	  inFile.close();
	  outFile.close();
	  return 0;
}


