#include <opencv2/imgcodecs.hpp>//映像文件
#include <opencv2/highgui.hpp>//gui,图形用户界面
#include <opencv2/imgproc.hpp>//图像处理文件
#include <iostream>//输入输出流文件

using namespace cv;
using namespace std;//文件不仅需要预处理部分，还要一个正式定义它的命名空间激活它的用法

/////////////// Resize and Crop //////////////////////

void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);//读取这个变量对应的地址
	Mat imgResize,imgCrop;

	cout << img.size() << endl;//当前图片的尺寸
	//resize(img, imgresize, Size(640, 480));//重置图片尺寸存在新变量中
	resize(img, imgResize, Size(), 0.5, 0.5);//等比例缩放

	Rect roi(100, 100, 350, 250);//前俩是图片出现再屏幕上的位置，后俩是裁剪的部分
	imgCrop = img(roi);

	imshow("Image", img);//展示这个变量的图片
	imshow("Image Resize", imgResize);
	imshow("Image Crop", imgCrop);
	
	waitKey(0);//让这个图片不会自动关闭，给予延迟
}