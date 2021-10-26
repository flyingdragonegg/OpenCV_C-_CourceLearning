#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/////////////// Color Detection //////////////////////
/////////// 创建特定对象对象检测器////////////////////


void main() {

	string path = "Resources/lambo.png";
	string path1 = "Resources/shapes.png";
	Mat img = imread(path);
	Mat img1 = imread(path1);
	Mat imgHSV, mask;
	int hmin = 0, smin = 110, vmin = 153;
	int hmax = 19, smax = 240, vmax = 255;

	cvtColor(img, imgHSV, COLOR_BGR2HSV);//将img的图片转换为HSV模式
	//这里没有彻底搞懂色相饱和度和取值三者数据的关系
	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);

	while (true) {
		
		/*
			Scalar类是用来存取像素点信息的类，定义一个lower对象存取色相h，饱和度s，和取值v的最小值
			在定义一个upper对象同理
		*/

		//Scalar是像素点的数值信息
		Scalar lower(hmin, smin, vmin);//色相（hue minimum）最小值，饱和度（saturation）最小值，取值（value）最小值
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);//不同颜色不同采光对应不同结果，所以有一个上限值和下限值，最后输出的是一个遮罩mask

		//imshow("Image", img);
		//imshow("Image shapes", img1);
		imshow("Image HSV", imgHSV);
		imshow("Image mask", mask);
		waitKey(1);
	}
}