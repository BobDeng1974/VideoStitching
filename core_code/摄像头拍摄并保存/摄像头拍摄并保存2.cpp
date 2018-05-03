#include "cv.h"
#include "cxcore.h"
#include "highgui.h"
#include <iostream>

using namespace std;
int main()
{
	CvCapture* capture1=cvCreateCameraCapture(1);
	CvCapture* capture2=cvCreateCameraCapture(2);
	CvVideoWriter* video1=NULL;
	CvVideoWriter* video2=NULL;
	IplImage* frame1=NULL;
	IplImage* frame2=NULL;
	int n1,n2;
	if(!capture1&&!capture2) //������ܴ�����ͷ��������
	{
		cout<<"Can not open the camera."<<endl;
		return -1;
	}
	else
	{
		frame1=cvQueryFrame(capture1); //����ȡ������ͷ�е�һ֡
		frame2=cvQueryFrame(capture2); //����ȡ������ͷ�е�һ֡
		int width=min(frame1->width,frame2->width);
		int height=min(frame1->height,frame2->height);
		video1=cvCreateVideoWriter("camera1.avi", CV_FOURCC('X', 'V', 'I', 'D'), 25,cvSize(width,height)); //����CvVideoWriter���󲢷���ռ�
		video2=cvCreateVideoWriter("camera2.avi", CV_FOURCC('X', 'V', 'I', 'D'), 25,cvSize(width,height)); //����CvVideoWriter���󲢷���ռ�
		//������ļ���Ϊcamera.avi������Ҫ�����г���ʱѡ�񣬴�С��������ͷ��Ƶ�Ĵ�С��֡Ƶ����32
		if(video1&&video2) //����ܴ���CvVideoWriter����������ɹ�
		{
			cout<<"VideoWriter has created."<<endl;
		}

		cvNamedWindow("Camera Video1",1); //�½�һ������
		cvNamedWindow("Camera Video2",1); //�½�һ������
		//int i = 0;
		while(1) // ����ѭ��1000���Զ�ֹͣ¼ȡ
		{
			frame1=cvQueryFrame(capture1); //��CvCapture�л��һ֡
			frame2=cvQueryFrame(capture2); //��CvCapture�л��һ֡
			if(!frame1&&!frame2)
			{
				cout<<"Can not get frame from the capture."<<endl;
				break;
			}
			n1=cvWriteFrame(video1,frame1); //�ж��Ƿ�д��ɹ���������ص���1����ʾд��ɹ�
			n2=cvWriteFrame(video2,frame2); //�ж��Ƿ�д��ɹ���������ص���1����ʾд��ɹ�
			cout<<n1<<" "<<n2<<endl;
			cvShowImage("Camera Video1",frame1); //��ʾ��Ƶ���ݵ�ͼƬ
			cvShowImage("Camera Video2",frame2); //��ʾ��Ƶ���ݵ�ͼƬ
			//i++;
			
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