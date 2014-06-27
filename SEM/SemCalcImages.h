// Библиотеки для работы с изображениями (OpenCV)
#include <opencv\cv.h>
#include <opencv\highgui.h>

// Стандартные библиотеки
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <Windows.h>

// Библиотека OpenMP для распараллеливания
#include <omp.h>

// Библиотека для засекания времени
#include <time.h>

#pragma once

using namespace System;

// Класс, выполняющий все преобразования изображения, производящий расчеты, хранящий настройки и сами изображения
ref class SemCalcImages : System::Object
{
public:
	// Стандартные функции синглтона (класса, имеющего только один объект)
	static SemCalcImages^ GetInstance();
	void ResetInstance();
	// Загрузка изображения для дальнейшего преобразования
	void loadImage(String^ _fileName);
	// Методы установки значений парамтров
	void setD(float _d);
	void setW(float _w);
	void setK(float _k);
	void setGamma(float _gamma);
	void setRo(float _ro);
	void setC(float _c);
	void setU(float _u);
	void setV(float _v);
	void setScanMode(int _scanMode);
	// Методы получения параметров
	float getD();
	float getW();
	float getK();
	float getGamma();
	float getRo();
	float getC();
	float getU();
	float getV();
	int getScanMode();
	// Метод счета
	bool calculate(IplImage* _dst, System::Windows::Forms::ProgressBar^ _processingBar, System::Windows::Forms::Label^ _labelTime);
	int sign(int _in);
	// Подготовка изображения
	void preparingAnImage();
	// Вывод в лог настроек
	void logSettings();
	// Вывод графика профила в pictureBox
	void getProfile(System::Windows::Forms::PictureBox^ _picBox);	

	// Ссылки на переменные, хранящие исходное 3х канальное изображение и преобразованные 3х канальные
	IplImage* m_src;
	IplImage* m_rslCp;
	IplImage* m_rslPp;

protected:
	// Конструктор
	SemCalcImages(void);
	SemCalcImages(String^ _fileName);
	// Деструктор
	~SemCalcImages();

private:
	// Две функции для интерпритации результирующей матрицы
	void clip(); // Обрезать матрицу до пределов [-1; 1] и подсчитать соответствующее изображение
	void dontClip(); // Не обрезать матрицу, изображение подстроить под соответствующие значния
	// Сохранить лог
	void saveLog();

	// Ссылка на объект класса
	static SemCalcImages^ m_instanse;	
	// Имя текущего файла
	String^ m_nameImage;
	// Переменные для хранения милисекунд, секунд, минут и часов
	unsigned int mse_w;
	unsigned int sec_w;
	unsigned int min_w;
	unsigned int hou_w;
	// Параметры настройки
	float m_d;
	float m_w;
	float m_k;
	float m_gamma;
	float m_ro;
	float m_c;
	float m_u;
	float m_v;
	// Порог серого изображения
	int m_threshold;
	// Ссылка на исходное изображение, преобразованное в 1 канальное (в градациях серого)
	IplImage* m_graySrc;
	IplImage* m_grayDst; // Значения храняться для последних проведенных расчетов (до расчетов изображение пустое)
	// Длинна и ширина исходного изображения
	int m_heightImage;
	int m_widthImage;
	// Вспомогательные массивы
	double *preView;
	int *colorRange;
	// Временные переменные для счета
	float* z;
	// Режим пульсирующей пробы
	int m_scanModes; // 0 - амплитудный сигнал, 1 - inphase, 2 - reactive
	bool isCrop;
	// Файловая переменная для ведения логов
	FILE* logOut;
};
