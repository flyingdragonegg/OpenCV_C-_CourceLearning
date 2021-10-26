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

	Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} };//Ť�����ĸ���λ��
	/*---------------���Ͻǣ����Ͻǿ�Ϊ�ƿ������½ǣ����½�*/
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };//Ť�����ĸ���Ŀ�ĵ�λ��

	matrix = getPerspectiveTransform(src, dst);//���mat�����Ŵ�srcת�Ƶ�dst��������ͼ����Ϣ
	warpPerspective(img, imgWarp, matrix, Point(w, h));//�������Ŀ���

	for (int i = 0; i < 4; i++)//������ȡͼƬ�����ĸ��������ע����
	{
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
	}

	imshow("Image", img);
	imshow("Image Warp", imgWarp);
	waitKey(0);

}