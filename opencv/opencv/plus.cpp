#include <opencv\cv.h>
#include <opencv\highgui.h>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <Windows.h>
#include <iostream>

using namespace std;
using namespace cv;
void goevent(int x, int y);
void windowcapture();
Mat hwnd2mat(HWND hwnd)
{
	HDC hwindowDC, hwindowCompatibleDC;


	int height, width, srcheight, srcwidth;
	HBITMAP hbwindow;
	Mat src;
	BITMAPINFOHEADER  bi;


	hwindowDC = GetDC(hwnd);
	hwindowCompatibleDC = CreateCompatibleDC(hwindowDC);
	SetStretchBltMode(hwindowCompatibleDC, COLORONCOLOR);


	RECT windowsize;    // get the height and width of the screen
	GetClientRect(hwnd, &windowsize);


	srcheight = windowsize.bottom;
	srcwidth = windowsize.right;
	height = windowsize.bottom / 1;  //change this to whatever size you want to resize to
	width = windowsize.right / 1;


	src.create(height, width, CV_8UC4);


	// create a bitmap
	hbwindow = CreateCompatibleBitmap(hwindowDC, width, height);
	bi.biSize = sizeof(BITMAPINFOHEADER);    //http://msdn.microsoft.com/en-us/library/windows/window/dd183402%28v=vs.85%29.aspx
	bi.biWidth = width;
	bi.biHeight = -height;  //this is the line that makes it draw upside down or not
	bi.biPlanes = 1;
	bi.biBitCount = 32;
	bi.biCompression = BI_RGB;
	bi.biSizeImage = 0;
	bi.biXPelsPerMeter = 0;
	bi.biYPelsPerMeter = 0;
	bi.biClrUsed = 0;
	bi.biClrImportant = 0;


	// use the previously created device context with the bitmap
	SelectObject(hwindowCompatibleDC, hbwindow);
	// copy from the window device context to the bitmap device context
	StretchBlt(hwindowCompatibleDC, 0, 0, width, height, hwindowDC, 0, 0, srcwidth, srcheight, SRCCOPY); //change SRCCOPY to NOTSRCCOPY for wacky colors !
	GetDIBits(hwindowCompatibleDC, hbwindow, 0, height, src.data, (BITMAPINFO *)&bi, DIB_RGB_COLORS);  //copy from hwindowCompatibleDC to hbwindow


																									   // avoid memory leak
	DeleteObject(hbwindow);
	DeleteDC(hwindowCompatibleDC);
	ReleaseDC(hwnd, hwindowDC);


	return src;
}
void Show(char *str, IplImage *img)
{
	cvNamedWindow(str, 1);
	cvShowImage(str, img);
}

void templatmatching()
{
	double min, max;
	CvPoint left_top;
	double windowmultiply = 1.25;
	IplImage *A = cvLoadImage("copy.jpg", -1); // å��(A)�� ���� �а�
	IplImage *B = cvLoadImage("copys.jpg", -1); // �������÷�(B)�� �д´�.
	IplImage* C = cvCreateImage(cvSize(A->width - B->width + 1, A->height - B->height + 1), IPL_DEPTH_32F, 1); // �������� ���� �̹���(C)

	cvMatchTemplate(A, B, C, CV_TM_CCOEFF_NORMED); // �������� ���Ͽ� C �� �׸���.
	cvMinMaxLoc(C, &min, &max, NULL, &left_top); // �������� �ִ밪�� ���� ��ġ ã��  ?????
	cvRectangle(A, left_top, cvPoint(left_top.x + B->width, left_top.y + B->height), CV_RGB(255, 0, 0)); // ã�� ��ü�� ������� �׸���.
	if (max > 0.9) {
		printf("x = %d, y = %d �ִ� %lf", left_top.x, left_top.y, max);

		goevent((left_top.x+(B->width)/2)/windowmultiply, (left_top.y+(B->height)/2) / windowmultiply); // ??????
		
		Show("T9-result", A); // ��� ����
							  //Show("T9-sample", B); // �������÷�(B) ����
							  //Show("C", C);   // ������ �̹��� ����
		cvWaitKey(0);

		// ��� �̹��� ������
		cvReleaseImage(&A);
		cvReleaseImage(&B);
		cvReleaseImage(&C);
		// ��� ������ ����
		cvDestroyAllWindows();
	}
	else {
		windowcapture();
		templatmatching();
	}
	
}


void goevent(int x, int y) {
	SetCursorPos(x, y);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
};



int main(int argc, char **argv)
{
	HWND hWnd = GetConsoleWindow();
	windowcapture();
	templatmatching();
	ShowWindow(hWnd,SW_SHOW);

	cvWaitKey(0);

	return 0;

}
void windowcapture() {
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
	Sleep(100);
	HWND hwndDesktop = GetDesktopWindow();

	int key = 0;


	Mat src = hwnd2mat(hwndDesktop);
	//imshow("output", src);
	imwrite("copy.jpg", src);

}