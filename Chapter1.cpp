#include <opencv2/imgcodecs.hpp>//ӳ���ļ�
#include <opencv2/highgui.hpp>//gui,ͼ���û�����
#include <opencv2/imgproc.hpp>//ͼ�����ļ�
#include <iostream>//����������ļ�

using namespace cv;
using namespace std;//�ļ�������ҪԤ�����֣���Ҫһ����ʽ�������������ռ伤�������÷�

///////////////// Images //////////////////////

//void main() {
//	string path = "Resources/test.png";
//	Mat img = imread(path);//��ȡ���������Ӧ�ĵ�ַ
//	imshow("Image", img);//չʾ���������ͼƬ
//	waitKey(0);//�����ͼƬ�����Զ��رգ������ӳ�
//}

/////////////////// Video //////////////////////
//void main() {
//
//	string path = "Resources/test_video.mp4";
//	VideoCapture cap(path);
//	Mat img;//��Ҫ���˱�����θ�ֵ��Ҳ����ÿ֡ͼƬ�����԰�����ѭ��������
//
//	while (true) {
//		//Mat img = imread(path);//��ȡ���������Ӧ�ĵ�ַ
//		//imshow("Image", img);//չʾ���������ͼƬ
//		cap.read(img);//��cap����������ȡ����洢��img��
//		imshow("image", img);//չʾ��ǰ֡ͼƬ
//		waitKey(20);//�����ͼƬ�����Զ��رգ������ӳ�20����
//	}
//}

///////////////// Webcam //////////////////////
void main() {

	string path = "Resources/test_video.mp4";
	VideoCapture cap(path);//�Լ���������ͷĬ��IDΪ0
	Mat img;//��Ҫ���˱�����θ�ֵ��Ҳ����ÿ֡ͼƬ�����԰�����ѭ��������

	while (true) {
		//Mat img = imread(path);//��ȡ���������Ӧ�ĵ�ַ
		//imshow("Image", img);//չʾ���������ͼƬ
		cap.read(img);//��cap����������ȡ����洢��img��
		imshow("image", img);//չʾ��ǰ֡ͼƬ
		waitKey(20);//�����ͼƬ�����Զ��رգ������ӳ�20����
	}
}//һ����˵����ֻ����Ƶ����������ͷ���ֶ�ȡ��ƵԴ