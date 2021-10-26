#include <opencv2/imgcodecs.hpp>//ӳ���ļ�
#include <opencv2/highgui.hpp>//gui,ͼ���û�����
#include <opencv2/imgproc.hpp>//ͼ�����ļ�
#include <iostream>//����������ļ�

using namespace cv;
using namespace std;//�ļ�������ҪԤ�����֣���Ҫһ����ʽ�������������ռ伤�������÷�

////////////// Draw Shapes and Text //////////////////////

void main() {

	// Blank Image
	/*------��С����С������װ��ɫ�Ŀǣ��������������ɫ��ɫ*/
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));//����һ��ͼԴ��������

	/*-----ͼԴ����ͼ����ԭ�㣬�뾶����ɫ����䷽ʽ-----------*/
	circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);//��ԲȦ
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);//������
	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);//����

	putText(img, "Murtaza��s Workshop", Point(137, 262), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 69, 255), 2);//��������

	imshow("Image", img);
	waitKey(0);
}