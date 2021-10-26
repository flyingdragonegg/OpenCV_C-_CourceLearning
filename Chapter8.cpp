#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>//使我们可以用级联文件
#include <iostream>

using namespace cv;
using namespace std;

/////////////// Faces Detection //////////////////////

void main() {

	string path = "Resources/test.png";
	Mat img = imread(path);
	resize(img, img, Size(), 0.5, 0.5);

	CascadeClassifier faceCascade;//编写级联分类器
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");

	//如果面部级联文件已经加载成功，就不会有这句话
	if (faceCascade.empty()) { cout << "XML file not loaded" << endl; }

	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1/*比例因子*/, 10/*最小邻居*/);//人脸级联点检测多尺度方法

	for (int i = 0; i < faces.size(); i++)
	{
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
	}

	imshow("Image", img);
	waitKey(0);
}