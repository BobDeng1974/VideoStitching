#include "cv.h"
#include "cxcore.h"
#include "highgui.h"
#include "opencv2/stitching/stitcher.hpp"
#include <iostream>


using namespace std;
using namespace cv;
int main()
{
	Mat pano;
	vector<Mat> imgs;
	CvCapture* capture1=cvCreateCameraCapture(1);
	CvCapture* capture2=cvCreateCameraCapture(2);
	CvVideoWriter* video1=NULL;
	CvVideoWriter* video2=NULL;
	IplImage* frame1=NULL;
	IplImage* frame2=NULL;

	if(!capture1&&!capture2) //������ܴ�����ͷ��������
	{
		cout<<"Can not open the camera."<<endl;
		return -1;
	}
	else
	{
		frame1=cvQueryFrame(capture1); //����ȡ������ͷ�е�һ֡
		frame2=cvQueryFrame(capture2);
		//�����ԣ���ͷ�ĳ�����640*480��ȡ����һ������
		int width=frame1->width;
		int height=frame1->height;
		cout<<width<<"  "<<height<<endl;
		
		if(video1&&video2) //����ܴ���CvVideoWriter����������ɹ�
		{
			cout<<"VideoWriter has created."<<endl;
		}

		cvNamedWindow("Camera Video1",1); //�½�һ������
		cvNamedWindow("Camera Video2",1); //�½�һ������

		while(1) 
		{
			
			frame1=cvQueryFrame(capture1); //��CvCapture�л��һ֡
			frame2=cvQueryFrame(capture2); //��CvCapture�л��һ֡
			if(!frame1&&!frame2)
			{
				cout<<"Can not get frame from the capture."<<endl;
				break;
			}

			cvShowImage("Camera Video1",frame1); //��ʾ��Ƶ���ݵ�ͼƬ
			cvShowImage("Camera Video2",frame2); //��ʾ��Ƶ���ݵ�ͼƬ
			
			
			if(cvWaitKey(2)>0) 
				break; //�����ڰ�������˳�

		}
		
		cvReleaseVideoWriter(&video1);
		cvReleaseVideoWriter(&video2);
		cvReleaseCapture(&capture1);
		cvReleaseCapture(&capture2);
		cvDestroyWindow("Camera Video1");
		cvDestroyWindow("Camera Video2");
	}
	return 0;
}