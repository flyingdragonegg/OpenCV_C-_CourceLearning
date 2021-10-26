#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/////////////// Color Detection //////////////////////
/////////// �����ض������������////////////////////


void main() {

	Mat img;
	Mat imgHSV, mask;
	int hmin = 0, smin = 0, vmin = 0;
	int hmax = 179, smax = 255, vmax = 255;

	VideoCapture cap(0);

	//cvtColor(img, imgHSV, COLOR_BGR2HSV);//��img��ͼƬת��ΪHSVģʽ
	//����û�г��׸㶮ɫ�౥�ͶȺ�ȡֵ�������ݵĹ�ϵ
	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);

	while (true) {


		cap.read(img);
		cvtColor(img, imgHSV, COLOR_BGR2HSV);
		/*
			Scalar����������ȡ���ص���Ϣ���࣬����һ��lower�����ȡɫ��h�����Ͷ�s����ȡֵv����Сֵ
			�ڶ���һ��upper����ͬ��
		*/

		//Scalar�����ص����ֵ��Ϣ
		Scalar lower(hmin, smin, vmin);//ɫ�ࣨhue minimum����Сֵ�����Ͷȣ�saturation����Сֵ��ȡֵ��value����Сֵ
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);//��ͬ��ɫ��ͬ�ɹ��Ӧ��ͬ�����������һ������ֵ������ֵ������������һ������mask

		cout << "(" << hmin << "," << smin << "," << vmax << "," << hmax << "," << smax << "," << vmax << ")" << endl;

		//imshow("Image", img);
		//imshow("Image shapes", img1);
		imshow("Image HSV", imgHSV);
		imshow("Image mask", mask);
		waitKey(1);
	}
}