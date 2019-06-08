#include<iostream>
#include<cstdint>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include<string>


using namespace std;
using namespace cv;


int h_min = 0, h_max = 25;
int s_min = 40, s_max = 135;
int v_min = 67, v_max = 140;

const int maxValue = 255;

void on_lowH_trackbar(int pos, void *);
void on_highH_trackbar(int pos, void *);
void on_lowS_trackbar(int pos, void *);
void on_highS_trackbar(int pos, void *);
void on_lowV_trackbar(int pos, void *);
void on_highV_trackbar(int pos, void *);
void aplica(Mat& M, string janela);

int main()
{
	Mat img, img_hsv, img_threshold;
	string janela1 = "UFR - Universidade Federal de Rondonopolis";
	string janela2 = "HSV - Imagem Segmentada";
	string janelaTrackbar = "HSV - Controle de Valores";

	//img = imread("UFR1.jpg");
	img = imread("UFR2.jpg");
	namedWindow(janela1);
	namedWindow(janela2);
	namedWindow(janelaTrackbar);
	
	createTrackbar("H_Min", janelaTrackbar, &h_min, maxValue,on_lowH_trackbar);
	createTrackbar("H_Max", janelaTrackbar, &h_max, maxValue, on_highH_trackbar);

	createTrackbar("S_Min", janelaTrackbar, &s_min, maxValue, on_lowS_trackbar);
	createTrackbar("S_Max", janelaTrackbar, &s_max, maxValue, on_highS_trackbar);

	createTrackbar("V_Min", janelaTrackbar, &v_min, maxValue, on_lowV_trackbar);
	createTrackbar("V_Max", janelaTrackbar, &v_max, maxValue, on_highV_trackbar);
	
	while (true)
	{
		cvtColor(img, img_hsv, COLOR_BGR2HSV);
		inRange(img_hsv, Scalar(h_min, s_min, v_min), Scalar(h_max, s_max, v_max), img_threshold);

		imshow(janela1, img);
		imshow(janela2, img_threshold);


		if (waitKey(10) == 27)
			break;
	}

	return 0;
}


void on_lowH_trackbar(int pos, void *)
{
	h_min = min(h_min, h_max - 1);
	setTrackbarPos("H_Min", "aux", h_min);
}
void on_highH_trackbar(int pos, void *)
{
	h_max = max(h_max, h_min + 1);
	setTrackbarPos("H_Max", "aux", h_max);
}

void on_lowS_trackbar(int pos, void *)
{
	s_min = min(s_min, s_max - 1);
	setTrackbarPos("S_Min", "aux", s_min);
}
void on_highS_trackbar(int pos, void *)
{
	s_max = max(s_max, s_min + 1);
	setTrackbarPos("S_Max", "aux", s_max);
}

void on_lowV_trackbar(int pos, void *)
{
	v_min = min(v_min, v_max - 1);
	setTrackbarPos("V_Min", "aux", v_min);
}
void on_highV_trackbar(int pos, void *)
{
	v_max = max(v_max, v_min + 1);
	setTrackbarPos("V_Max", "aux", v_max);
}
