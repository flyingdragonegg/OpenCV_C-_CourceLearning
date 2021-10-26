#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/////////////// Shapes Detection //////////////////////

/// <summary>
/// 1.如果我们找到这个形状的边缘，就可以找到边的形状-->我们使用的方法是之前的Canny边缘检测法
/// 2.
/// </summary>
/// <param name="imgDil"></param>
/// <param name="img"></param>

void getContours(Mat imgDil, Mat img) {

	vector<vector<Point>> contours;//第一层是一个图源里能测出多个轮廓，第二层是指每个轮廓都由多个Point坐标元素形成
	vector<Vec4i> hierarchy;//Vec4i是opencv特有的数据类型，表示容器内的数据结构是四个整型

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);//如果你选择这种模式的话，只会返回最外边的的轮廓， 所有的子轮廓都会被忽略掉
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		cout << area << endl;
		string objectType;

		if (area > 1000)
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);//conPoly数组输出的点集，当前点集是能最小包容指定点集的。画出来即是一个多边形。（但是还没画，只是把值赋予给了变量）
			cout << conPoly[i].size() << endl;//n点位就有n条连接线
			boundRect[i] = boundingRect(conPoly[i]);//定义一个边界框变量来存取这组多边形数据数据

			int objCor = (int)conPoly[i].size();//分类了，不同的点边代表不同的形状

			if (objCor == 3) { objectType = "Tri"; }
			else if (objCor == 4)
			{
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
				cout << aspRatio << endl;
				if (aspRatio > 0.95 && aspRatio < 1.05) { objectType = "Square"; }
				else { objectType = "Rect"; }
			}
			else if (objCor > 4) { objectType = "Circle"; }

			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			putText(img, objectType, { boundRect[i].x,(boundRect[i].y)-5 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 2);
		}
	}
}

void main() {

	string path = "Resources/shapes.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

	// Preprocessing
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(10, 10));//设定一个内核，它的结构里面装着它的内核的形状和大小
	dilate(imgCanny, imgDil, kernel);

	getContours(imgDil, img);

	imshow("Image", img);
	//imshow(“Image Gray”, imgGray);
	//imshow(“Image Blur”, imgBlur);
	//imshow("Image Canny", imgCanny);
	//imshow("Image Dil", imgDil);

	waitKey(0);

}