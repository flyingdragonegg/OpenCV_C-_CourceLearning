#include <opencv2/imgcodecs.hpp>//ӳ���ļ�
#include <opencv2/highgui.hpp>//gui,ͼ���û�����
#include <opencv2/imgproc.hpp>//ͼ�����ļ�
#include <iostream>//����������ļ�

using namespace cv;
using namespace std;//�ļ�������ҪԤ�����֣���Ҫһ����ʽ�������������ռ伤�������÷�

/////////////// Basic Function //////////////////////

void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);//��ȡ���������Ӧ�ĵ�ַ
	Mat imgGray,imgBlur,imgCanny,imgDil,imgErode;
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);
	Canny(img, imgCanny, 50, 150);//ʹ�ÿ����Ե��ⷨ�����ҵ�ͼƬ�ı�Ե���ص㣬��ֵԽСԽ����

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));//�������ɶ��ֻ֪�������������ں�
	dilate(imgCanny, imgDil, kernel);//����
	erode(imgDil, imgErode, kernel);//��ʴĿǰ��ͼƬ����ž��Ǽ��ٱ�Ե���

	imshow("Image", img);//չʾ���������ͼƬ
	imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image imgDil", imgDil);
	imshow("Image imgErode", imgErode);
	waitKey(0);//�����ͼƬ�����Զ��رգ������ӳ�
}

