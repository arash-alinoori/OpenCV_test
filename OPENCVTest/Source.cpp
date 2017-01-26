#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>;
#include <cmath>;
#include <math.h>
#include <vector>

using namespace cv;
using namespace std;

///// Global variables
//Mat src, erosion_dst, dilation_dst;
//
//int erosion_elem = 0;
//int erosion_size = 0;
//int const max_elem = 2;
//int const max_kernel_size = 21;
//
///** Function Headers */
void CutImage(Mat RohImg);

/**
* @function main
*/
int main(int, char** argv)
{
	/// Load an image
	Mat src;
	Mat dst;
	int cuty, cutx;

	src = imread("D:/My Activities/C++/test/OPENCV15/OPENCVTest/data/test2.bmp");
	if (src.empty())
		{ return -1; }

	/// Create windows
	namedWindow("demo", WINDOW_AUTOSIZE);

	/// Create Trackbar
	//createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Demo", &erosion_elem, max_elem, CutImage);
	//createTrackbar("Kernel size:\n 2n +1", "Demo",&erosion_size, max_kernel_size, CutImage);

	CutImage(src);

	waitKey(0);
	return 0;
}

void CutImage(Mat RohImg)
{
	Mat dst;
	Mat img1, img2, img3, img4;
	Mat a, b, c;
	Mat p, q, albedo;
	
	int y = RohImg.rows;
	int x = RohImg.cols;
	cout << "x=" << x << "\n" << "y=" << y << endl;
	
	Rect ROI1(0, 0, x/4, y);
	Rect ROI2(x/4, 0, x/4, y);
	Rect ROI3(x/2, 0, x/4, y);
	Rect ROI4(3*x/4, 0, x/4, y);
	cout << "ROI1=" << ROI1 << "\n" << "ROI2=" << ROI2 << endl;
	cout << "ROI3=" << ROI3 << "\n" << "ROI4=" << ROI4 << endl;

	img1 = RohImg(ROI1);
	img2 = RohImg(ROI2);
	img3 = RohImg(ROI3);
	img4 = RohImg(ROI4);

	//addWeighted(img1, 0.5,  img2, 0.5, a);// +img3 + img4;
	//b = 0.5 * (img1 + img2 + img3 + img4);
	//c = 0.3 * (img1 + img2 + img3 + img4);
	
	//albedo = sqrt(a + b);
	vector<float> array1(img1.cols * img1.rows);
	vector<float> array2(img2.cols * img2.rows);
	vector<float> array3(img3.cols * img3.rows);
	vector<float> array4(img4.cols * img4.rows);

	if (RohImg.isContinuous())
	{
		array1.assign(img1.datastart, img1.dataend);
		array2.assign(img2.datastart, img2.dataend);
		array3.assign(img3.datastart, img3.dataend);
		array4.assign(img4.datastart, img4.dataend);
	}
		
	dst = RohImg(ROI2);
	
	//imshow("demo", array1);
};
