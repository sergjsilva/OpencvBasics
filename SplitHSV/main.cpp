#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
	Mat img = imread("koala.jpg", CV_LOAD_IMAGE_COLOR);
	Mat imgHSV;
	vector<Mat> channels;

	// Resize Image
	float factor = 0.45;
	int newWidth = (int)((float)factor*img.cols);
	int newHeight = (int)((float)factor * img.rows);
	resize(img, img, Size(newWidth, newHeight));
	
	// Convert to HSV
	cvtColor(img, imgHSV, CV_BGR2HSV);
	
	// Split HSV
	split(imgHSV, channels);
	Mat hueChannel = channels[0];
	Mat saturationChannel = channels[1];
	Mat valueChannel = channels[2];

	namedWindow("Hue");
	namedWindow("Saturation");
	namedWindow("Value");
	imshow("Hue", hueChannel);
	imshow("Saturation", saturationChannel);
	imshow("Value", valueChannel);

	waitKey();
	return 0;
}
