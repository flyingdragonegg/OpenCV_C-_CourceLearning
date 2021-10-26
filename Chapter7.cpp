#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/////////////// Shapes Detection //////////////////////

/// <summary>
/// 1.��������ҵ������״�ı�Ե���Ϳ����ҵ��ߵ���״-->����ʹ�õķ�����֮ǰ��Canny��Ե��ⷨ
/// 2.
/// </summary>
/// <param name="imgDil"></param>
/// <param name="img"></param>

void getContours(Mat imgDil, Mat img) {

	vector<vector<Point>> contours;//��һ����һ��ͼԴ���ܲ������������ڶ�����ָÿ���������ɶ��Point����Ԫ���γ�
	vector<Vec4i> hierarchy;//Vec4i��opencv���е��������ͣ���ʾ�����ڵ����ݽṹ���ĸ�����

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);//�����ѡ������ģʽ�Ļ���ֻ�᷵������ߵĵ������� ���е����������ᱻ���Ե�
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
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);//conPoly��������ĵ㼯����ǰ�㼯������С����ָ���㼯�ġ�����������һ������Ρ������ǻ�û����ֻ�ǰ�ֵ������˱�����
			cout << conPoly[i].size() << endl;//n��λ����n��������
			boundRect[i] = boundingRect(conPoly[i]);//����һ���߽���������ȡ����������������

			int objCor = (int)conPoly[i].size();//�����ˣ���ͬ�ĵ�ߴ���ͬ����״

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
	Mat kernel = getStructuringElement(MORPH_RECT, Size(10, 10));//�趨һ���ںˣ����Ľṹ����װ�������ں˵���״�ʹ�С
	dilate(imgCanny, imgDil, kernel);

	getContours(imgDil, img);

	imshow("Image", img);
	//imshow(��Image Gray��, imgGray);
	//imshow(��Image Blur��, imgBlur);
	//imshow("Image Canny", imgCanny);
	//imshow("Image Dil", imgDil);

	waitKey(0);

}