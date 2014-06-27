// ���������� ��� ������ � ������������� (OpenCV)
#include <opencv\cv.h>
#include <opencv\highgui.h>

// ����������� ����������
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <Windows.h>

// ���������� OpenMP ��� �����������������
#include <omp.h>

// ���������� ��� ��������� �������
#include <time.h>

#pragma once

using namespace System;

// �����, ����������� ��� �������������� �����������, ������������ �������, �������� ��������� � ���� �����������
ref class SemCalcImages : System::Object
{
public:
	// ����������� ������� ��������� (������, �������� ������ ���� ������)
	static SemCalcImages^ GetInstance();
	void ResetInstance();
	// �������� ����������� ��� ����������� ��������������
	void loadImage(String^ _fileName);
	// ������ ��������� �������� ���������
	void setD(float _d);
	void setW(float _w);
	void setK(float _k);
	void setGamma(float _gamma);
	void setRo(float _ro);
	void setC(float _c);
	void setU(float _u);
	void setV(float _v);
	void setScanMode(int _scanMode);
	// ������ ��������� ����������
	float getD();
	float getW();
	float getK();
	float getGamma();
	float getRo();
	float getC();
	float getU();
	float getV();
	int getScanMode();
	// ����� �����
	bool calculate(IplImage* _dst, System::Windows::Forms::ProgressBar^ _processingBar, System::Windows::Forms::Label^ _labelTime);
	int sign(int _in);
	// ���������� �����������
	void preparingAnImage();
	// ����� � ��� ��������
	void logSettings();
	// ����� ������� ������� � pictureBox
	void getProfile(System::Windows::Forms::PictureBox^ _picBox);	

	// ������ �� ����������, �������� �������� 3� ��������� ����������� � ��������������� 3� ���������
	IplImage* m_src;
	IplImage* m_rslCp;
	IplImage* m_rslPp;

protected:
	// �����������
	SemCalcImages(void);
	SemCalcImages(String^ _fileName);
	// ����������
	~SemCalcImages();

private:
	// ��� ������� ��� ������������� �������������� �������
	void clip(); // �������� ������� �� �������� [-1; 1] � ���������� ��������������� �����������
	void dontClip(); // �� �������� �������, ����������� ���������� ��� ��������������� �������
	// ��������� ���
	void saveLog();

	// ������ �� ������ ������
	static SemCalcImages^ m_instanse;	
	// ��� �������� �����
	String^ m_nameImage;
	// ���������� ��� �������� ����������, ������, ����� � �����
	unsigned int mse_w;
	unsigned int sec_w;
	unsigned int min_w;
	unsigned int hou_w;
	// ��������� ���������
	float m_d;
	float m_w;
	float m_k;
	float m_gamma;
	float m_ro;
	float m_c;
	float m_u;
	float m_v;
	// ����� ������ �����������
	int m_threshold;
	// ������ �� �������� �����������, ��������������� � 1 ��������� (� ��������� ������)
	IplImage* m_graySrc;
	IplImage* m_grayDst; // �������� ��������� ��� ��������� ����������� �������� (�� �������� ����������� ������)
	// ������ � ������ ��������� �����������
	int m_heightImage;
	int m_widthImage;
	// ��������������� �������
	double *preView;
	int *colorRange;
	// ��������� ���������� ��� �����
	float* z;
	// ����� ������������ �����
	int m_scanModes; // 0 - ����������� ������, 1 - inphase, 2 - reactive
	bool isCrop;
	// �������� ���������� ��� ������� �����
	FILE* logOut;
};
