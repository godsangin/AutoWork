/*#include <opencv\cv.h>
#include <opencv\highgui.h>

void Show(char *str, IplImage *img)
{
    cvNamedWindow( str, 1);
    cvShowImage( str, img );
}

void main()
{
	double min, max;
	CvPoint left_top;
	IplImage *A = cvLoadImage("copy.jpg", -1); // 책상(A)을 먼저 읽고
	IplImage *B = cvLoadImage("copys.jpg", -1); // 스테이플러(B)를 읽는다.
	IplImage* C = cvCreateImage(cvSize(A->width - B->width + 1, A->height - B->height + 1), IPL_DEPTH_32F, 1); // 상관계수를 구할 이미지(C)

	cvMatchTemplate(A, B, C, CV_TM_CCOEFF_NORMED); // 상관계수를 구하여 C 에 그린다.
	cvMinMaxLoc(C, &min, &max, NULL, &left_top); // 상관계수가 최대값을 값는 위치 찾기 
	cvRectangle(A, left_top, cvPoint(left_top.x + B->width, left_top.y + B->height), CV_RGB(255, 0, 0)); // 찾은 물체에 사격형을 그린다.
	printf("x = %d, y = %d", left_top.x, left_top.y);

	Show("T9-result", A); // 결과 보기
	Show("T9-sample", B); // 스테이플러(B) 보기
	Show("C", C);   // 상관계수 이미지 보기
	cvWaitKey(0);

	// 모든 이미지 릴리즈
	cvReleaseImage(&A);
	cvReleaseImage(&B);
	cvReleaseImage(&C);

	// 모든 윈도우 제거
	cvDestroyAllWindows();
}*/