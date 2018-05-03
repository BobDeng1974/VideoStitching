#include "cv.h"
#include "cxcore.h"
#include "highgui.h"
#include <iostream>

using namespace std;
int main()
{
	CvCapture* capture1=cvCreateCameraCapture(1);
	CvVideoWriter* video1=NULL;
	IplImage* frame1=NULL;
	int n1;

	if(!capture1) //������ܴ�����ͷ��������
	{
		cout<<"Can not open the camera."<<endl;
		return -1;
	}
	else
	{
		frame1=cvQueryFrame(capture1); //����ȡ������ͷ�е�һ֡
		int width=frame1->width;
		int height=frame1->height;
		video1=cvCreateVideoWriter("camera1.avi", CV_FOURCC('X', 'V', 'I', 'D'), 25,cvSize(width,height)); //����CvVideoWriter���󲢷���ռ�
		//������ļ���Ϊcamera.avi������Ҫ�����г���ʱѡ�񣬴�С��������ͷ��Ƶ�Ĵ�С��֡Ƶ����32
		if(video1) //����ܴ���CvVideoWriter����������ɹ�
		{
			cout<<"VideoWriter has created."<<endl;
		}

		cvNamedWindow("Camera Video1",1); //�½�һ������

		while(1) // ����ѭ��1000���Զ�ֹͣ¼ȡ
		{
			frame1=cvQueryFrame(capture1); //��CvCapture�л��һ֡
			
			if(!frame1)
			{
				cout<<"Can not get frame from the capture."<<endl;
				break;
			}
			n1=cvWriteFrame(video1,frame1); //�ж��Ƿ�д��ɹ���������ص���1����ʾд��ɹ�
			
			cout<<n1<<" "<<endl;
			cvShowImage("Camera Video1",frame1); //��ʾ��Ƶ���ݵ�ͼƬ
			
			
			if(cvWaitKey(2)>0) 
				break; //�����ڰ�������˳�
		}
		
		cvReleaseVideoWriter(&video1);
		
		cvReleaseCapture(&capture1);
		
		cvDestroyWindow("Camera Video1");
		
	}
	return 0;
}