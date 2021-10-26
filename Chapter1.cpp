#include <opencv2/imgcodecs.hpp>//映像文件
#include <opencv2/highgui.hpp>//gui,图形用户界面
#include <opencv2/imgproc.hpp>//图像处理文件
#include <iostream>//输入输出流文件

using namespace cv;
using namespace std;//文件不仅需要预处理部分，还要一个正式定义它的命名空间激活它的用法

///////////////// Images //////////////////////

//void main() {
//	string path = "Resources/test.png";
//	Mat img = imread(path);//读取这个变量对应的地址
//	imshow("Image", img);//展示这个变量的图片
//	waitKey(0);//让这个图片不会自动关闭，给予延迟
//}

/////////////////// Video //////////////////////
//void main() {
//
//	string path = "Resources/test_video.mp4";
//	VideoCapture cap(path);
//	Mat img;//需要给此变量多次赋值，也就是每帧图片。所以把它放循环外声明
//
//	while (true) {
//		//Mat img = imread(path);//读取这个变量对应的地址
//		//imshow("Image", img);//展示这个变量的图片
//		cap.read(img);//从cap这个对象里读取对象存储在img里
//		imshow("image", img);//展示当前帧图片
//		waitKey(20);//让这个图片不会自动关闭，给予延迟20毫秒
//	}
//}

///////////////// Webcam //////////////////////
void main() {

	string path = "Resources/test_video.mp4";
	VideoCapture cap(path);//自己电脑摄像头默认ID为0
	Mat img;//需要给此变量多次赋值，也就是每帧图片。所以把它放循环外声明

	while (true) {
		//Mat img = imread(path);//读取这个变量对应的地址
		//imshow("Image", img);//展示这个变量的图片
		cap.read(img);//从cap这个对象里读取对象存储在img里
		imshow("image", img);//展示当前帧图片
		waitKey(20);//让这个图片不会自动关闭，给予延迟20毫秒
	}
}//一般来说我们只有视频和网络摄像头两种读取视频源