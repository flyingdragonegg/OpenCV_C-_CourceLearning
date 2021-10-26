#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>//ʹ���ǿ����ü����ļ�
#include <iostream>

using namespace cv;
using namespace std;

/////////////// Faces Detection //////////////////////

void main() {

	string path = "Resources/test.png";
	Mat img = imread(path);
	resize(img, img, Size(), 0.5, 0.5);

	CascadeClassifier faceCascade;//��д����������
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");

	//����沿�����ļ��Ѿ����سɹ����Ͳ�������仰
	if (faceCascade.empty()) { cout << "XML file not loaded" << endl; }

	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1/*��������*/, 10/*��С�ھ�*/);//�������������߶ȷ���

	for (int i = 0; i < faces.size(); i++)
	{
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
	}

	imshow("Image", img);
	waitKey(0);
}