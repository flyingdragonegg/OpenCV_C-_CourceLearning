#include <opencv2/imgcodecs.hpp>//映像文件
#include <opencv2/highgui.hpp>//gui,图形用户界面
#include <opencv2/imgproc.hpp>//图像处理文件
#include <iostream>//输入输出流文件

using namespace cv;
using namespace std;//文件不仅需要预处理部分，还要一个正式定义它的命名空间激活它的用法

////////////// Draw Shapes and Text //////////////////////

void main() {

	// Blank Image
	/*------大小，大小，定义装颜色的壳，定义壳子里填充的色白色*/
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));//定义一个图源基本属性

	/*-----图源，新图坐标原点，半径，颜色，填充方式-----------*/
	circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);//画圆圈
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);//长方体
	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);//画线

	putText(img, "Murtaza’s Workshop", Point(137, 262), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 69, 255), 2);//加入文字

	imshow("Image", img);
	waitKey(0);
}