#include <opencv2/imgcodecs.hpp>//映像文件
#include <opencv2/highgui.hpp>//gui,图形用户界面
#include <opencv2/imgproc.hpp>//图像处理文件
#include <iostream>//输入输出流文件

using namespace cv;
using namespace std;//文件不仅需要预处理部分，还要一个正式定义它的命名空间激活它的用法

/////////////// Basic Function //////////////////////

void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);//读取这个变量对应的地址
	Mat imgGray,imgBlur,imgCanny,imgDil,imgErode;
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);
	Canny(img, imgCanny, 50, 150);//使用坎尼边缘检测法可以找到图片的边缘像素点，阈值越小越精密

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));//不清楚是啥，只知道它可以膨胀内核
	dilate(imgCanny, imgDil, kernel);//膨胀
	erode(imgDil, imgErode, kernel);//侵蚀目前的图片，大概就是减少边缘厚度

	imshow("Image", img);//展示这个变量的图片
	imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image imgDil", imgDil);
	imshow("Image imgErode", imgErode);
	waitKey(0);//让这个图片不会自动关闭，给予延迟
}

