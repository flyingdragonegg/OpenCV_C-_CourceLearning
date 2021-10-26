#include <opencv2/imgcodecs.hpp>//ӳ���ļ�
#include <opencv2/highgui.hpp>//gui,ͼ���û�����
#include <opencv2/imgproc.hpp>//ͼ�����ļ�
#include <iostream>//����������ļ�

using namespace cv;
using namespace std;//�ļ�������ҪԤ�����֣���Ҫһ����ʽ�������������ռ伤�������÷�

/////////////// Resize and Crop //////////////////////

void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);//��ȡ���������Ӧ�ĵ�ַ
	Mat imgResize,imgCrop;

	cout << img.size() << endl;//��ǰͼƬ�ĳߴ�
	//resize(img, imgresize, Size(640, 480));//����ͼƬ�ߴ�����±�����
	resize(img, imgResize, Size(), 0.5, 0.5);//�ȱ�������

	Rect roi(100, 100, 350, 250);//ǰ����ͼƬ��������Ļ�ϵ�λ�ã������ǲü��Ĳ���
	imgCrop = img(roi);

	imshow("Image", img);//չʾ���������ͼƬ
	imshow("Image Resize", imgResize);
	imshow("Image Crop", imgCrop);
	
	waitKey(0);//�����ͼƬ�����Զ��رգ������ӳ�
}