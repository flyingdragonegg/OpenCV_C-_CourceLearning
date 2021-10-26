#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/////////////// Warp Images //////////////////////

void main() {

	string path = "Resources/cards.jpg";
	Mat img = imread(path);
	Mat matrix, imgWarp;
	float w = 250, h = 350;

	Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} };//扭曲的四个点位置
	/*---------------左上角，右上角宽为牌宽，左下角，右下角*/
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };//扭曲的四个点目的地位置

	matrix = getPerspectiveTransform(src, dst);//这个mat对象存放从src转移到dst对象像素图的信息
	warpPerspective(img, imgWarp, matrix, Point(w, h));//定义矩阵的宽高

	for (int i = 0; i < 4; i++)//把您截取图片部分四个特征点标注出来
	{
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
	}

	imshow("Image", img);
	imshow("Image Warp", imgWarp);
	waitKey(0);

}