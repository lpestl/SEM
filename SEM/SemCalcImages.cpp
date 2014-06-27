#include "SemCalcImages.h"

void SemCalcImages::saveLog() {
	fclose(logOut);
	logOut = fopen("log.log", "a+");
}

// Конструктор по умолчанию
SemCalcImages::SemCalcImages()
{
	logOut = fopen("log.log", "a+");
	fprintf(logOut, "\n############################################\n[%s] Run application", DateTime::Now.ToString());
	saveLog();

	m_src = NULL;
	m_rslCp = NULL;
	m_rslPp = NULL;

	mse_w = 0;
	sec_w = 0;
	min_w = 0;
	hou_w = 0;

	// Значения по умолчанию
	m_w = 1;
	m_k = 1;
	m_d = 1;
	m_v = 1;
	m_u = 1;
	m_scanModes = 0;
	m_gamma = 1;
	m_ro = 1;
	m_c = 1;

	isCrop = true;

	m_threshold = 127;
	
	preparingAnImage();
}

// Конструктор с параметром
SemCalcImages::SemCalcImages(String^ _fileName) {
	logOut = fopen("log.log", "a+");
	fprintf(logOut, "\n############################################\n[%s] Run application", DateTime::Now.ToString());
	saveLog();

	// Сохранить имя файла и полный путь
	m_nameImage = _fileName;
	
	// Очистка памяти для изображений
	m_src = NULL;
	m_rslCp = NULL;
	m_rslPp = NULL;

	// Обнуление переменных таймера
	mse_w = 0;
	sec_w = 0;
	min_w = 0;
	hou_w = 0;

	// Значения по умолчанию
	m_w = 1;
	m_k = 1;
	m_d = 1;
	m_v = 1;
	m_u = 1;
	m_scanModes = 0;
	m_gamma = 1;
	m_ro = 1;
	m_c = 1;

	isCrop = true;

	m_threshold = 127;

	// Преобразование стандартной строки к символьному массиву
	using namespace System::Runtime::InteropServices;
	const char *filen = (const char*)(void*)Marshal::StringToHGlobalAnsi(_fileName);
	// Загрузка исходного изображение
	m_src = cvLoadImage(filen);

	// Копирование исходного изображения в результирующие
	m_rslCp = cvCloneImage(m_src);
	m_rslPp = cvCloneImage(m_src);

	// Подготовка изображения
	preparingAnImage();	
}

// Деструктор
SemCalcImages::~SemCalcImages() {
	//cvReleaseImage(&m_src);
	//cvReleaseImage(&m_rsl);
	fprintf(logOut, "\n__________________________________\n[%s] Application close\n", DateTime::Now.ToString());
	fclose(logOut);
}

// Пулучить ссылку на объект класса
SemCalcImages^ SemCalcImages::GetInstance() {
	if (!SemCalcImages::m_instanse) SemCalcImages::m_instanse = gcnew SemCalcImages();
	return m_instanse;
}

// Удалить объект
void SemCalcImages::ResetInstance() {
	delete m_instanse;
}

// Загрузка изображения
void SemCalcImages::loadImage(String^ _fileName) {
	fprintf(logOut, "\n[%s] ##### %s #####", DateTime::Now.ToString(), _fileName);
	saveLog();
	
	// Сохранить имя файла и полный путь
	m_nameImage = _fileName;

	// Очистка памяти для изображений
	m_src = NULL;
	m_rslCp = NULL;
	m_rslPp = NULL;

	// Обнуление переменных таймера
	mse_w = 0;
	sec_w = 0;
	min_w = 0;
	hou_w = 0;

	// Значения по умолчанию
	m_w = 1;
	m_k = 1;
	m_d = 1;
	m_v = 1;
	m_u = 1;
	m_scanModes = 0;
	m_gamma = 1;
	m_ro = 1;
	m_c = 1;

	isCrop = true;

	// Преобразование стандартной строки к символьному массиву
	using namespace System::Runtime::InteropServices;
	const char *filen = (const char*)(void*)Marshal::StringToHGlobalAnsi(_fileName);
	// Загрузка исходного изображение
	m_src = cvLoadImage(filen);
	
	// Копирование исходного изображения
	m_rslCp = cvCloneImage(m_src);
	m_rslPp = cvCloneImage(m_src);

	// Подготовка изображения
	preparingAnImage();
}

void SemCalcImages::preparingAnImage() {
	// Очистка памяти
	m_graySrc = NULL;
	m_grayDst = NULL;

	m_heightImage = 0;
	m_widthImage = 0;

	// Приводим изображение к черно-юелому виду
	if (m_src != NULL) {
		m_graySrc = cvCreateImage(cvGetSize(m_src), m_src->depth, 1);
		cvCvtColor(m_src, m_graySrc, CV_BGR2GRAY);

		// Создаем пустое промежуточное изображение
		m_grayDst = cvCreateImage(cvGetSize(m_src), m_src->depth, 1);

		m_heightImage = m_grayDst->height;
		m_widthImage = m_grayDst->width;
	}

	// Вспомогательные массивы
	delete[] preView;
	preView = NULL;

	delete[] colorRange;
	colorRange = NULL;

	delete[] z;
	z = NULL;

	preView = new double[m_heightImage * m_widthImage];
	colorRange = new int[m_heightImage * m_widthImage];
	z = new float[255];

	system("cls");

	// Вывод матрицы изображения по цветам
	printf("Origin image matrix:\n");
	fprintf(logOut, "\nOrigin image matrix:\n");

	for (int i = 0; i < m_heightImage; i++) {
		uchar* ptr = (uchar*)(m_graySrc->imageData + i * m_graySrc->widthStep);
		for (int j = 0; j < m_widthImage; j++) {
			colorRange[i*m_widthImage + j] = 0;
			if ((int)ptr[j] == 255) {
				colorRange[i*m_widthImage + j] = 1;
			}
			if ((int)ptr[j] == 0) {
				colorRange[i*m_widthImage + j] = -1;
			}
			preView[i*m_widthImage + j] = colorRange[i*m_widthImage + j];
			printf("%3d ", (int)ptr[j]);
			fprintf(logOut, "%4d ", (int)ptr[j]);
		}
		printf("\n");
		fprintf(logOut, "\n");
	}
	saveLog();

	// Вывод матрицы ранга цвета в диапазоне от -1 до 1
	printf("\nColor range[-1;1] matrix:\n");
	fprintf(logOut, "\nColor range[-1;1] matrix:\n");
	for (int i = 0; i < m_heightImage; i++) {
		for (int j = 0; j < m_widthImage; j++) {
			printf("%2d ", colorRange[i*m_widthImage + j]);
			fprintf(logOut, "%2d ", colorRange[i*m_widthImage + j]);
		}
		printf("\n");
		fprintf(logOut, "\n");
	}
	saveLog();
}

// Методы установки значений парамтров
void SemCalcImages::setD(float _d) { m_d = _d; }
void SemCalcImages::setW(float _w) { m_w = _w; }
void SemCalcImages::setK(float _k) { m_k = _k; }
void SemCalcImages::setGamma(float _gamma) { m_gamma = _gamma; }
void SemCalcImages::setRo(float _ro) { m_ro = _ro; }
void SemCalcImages::setC(float _c) { m_c = _c; }
void SemCalcImages::setU(float _u) { m_u = _u; }
void SemCalcImages::setV(float _v) { m_v = _v; }
void SemCalcImages::setScanMode(int _scanMode) { m_scanModes = _scanMode; }
// Методы получения параметров
float SemCalcImages::getD() { return m_d; }
float SemCalcImages::getW() { return m_w; }
float SemCalcImages::getK() { return m_k; }
float SemCalcImages::getGamma() { return m_gamma; }
float SemCalcImages::getRo() { return m_ro; }
float SemCalcImages::getC() { return m_c; }
float SemCalcImages::getU() { return m_u; }
float SemCalcImages::getV() { return m_v; }
int SemCalcImages::getScanMode() { return m_scanModes; }

// Функция подсчета изображения
bool SemCalcImages::calculate(IplImage* _dst, System::Windows::Forms::ProgressBar^ _processingBar, System::Windows::Forms::Label^ _labelTime) {
	// Засекаем время старта
	unsigned int m_currTime = clock();
	unsigned int m_readTime;

	// Вспомогательные переменные
	double S = 0;
	float delgam = 2;
	float W = 2 * m_w;
	long double M_PI = acos((long double)-1);
	double constP = (-1) * (double)(W * delgam) / (4 * (double)M_PI * m_k);

	float x, y, dz, B1, B2, Rad;
	double S1, S2;
	int znak;

	std::complex<double> ii(0, 1);

	double kv;

	// Обнуление линии загрузки
	_processingBar->Maximum = m_heightImage * m_widthImage * m_heightImage * m_widthImage;
	_processingBar->Value = 0;
	_processingBar->Visible = true;

	printf("___________________________\nImage is working...\nResult matrix:\n");
	fprintf(logOut, "\nResul matrix:\n[%s] ", DateTime::Now.ToString());
	saveLog();

	// Использование дерективы OpenMP для параллельного 
	// выполнения цикла на нескольких ядрах процессора
#pragma omp parallel for

	// Цикл по строкам
	for (int i = 0; i < m_heightImage; i++) {
		// Получение пикселей по строкам конечного изображения в градациях серого
		//uchar* ptr = (uchar*)(m_grayDst->imageData + i * m_grayDst->widthStep);
		// Цикл по столбцам
		for (int j = 0; j < m_widthImage; j++) {
			for (int p = 0; p < m_heightImage; p++) {
				for (int q = 0; q < m_widthImage; q++) {
					// Обновление линии загрузки
					_processingBar->Value++;

					// Подсчет времени выполнения 
					m_readTime = (clock() - m_currTime) / 1000;
					mse_w = (clock() - m_currTime) % 1000;
					sec_w = m_readTime % 60;
					min_w = (m_readTime / 60) % 60;
					hou_w = ((m_readTime / 60) / 60);
					_labelTime->Text = "" + hou_w + ":" + min_w + ":" + sec_w + " (" + mse_w + " ms)";
					_labelTime->Update();

					if ((q < (m_widthImage - 1)) && (colorRange[p*m_widthImage + q] != colorRange[p*m_widthImage + q + 1])) {
						x = q - j + (float)1 / 2;
						y = (float)(p - i);

						if (colorRange[p*m_widthImage + q] == 1) {
							znak = -1;
						}
						else {
							znak = 1;
						}

						S1 = 0;
						dz = m_d / 255;

						for (int t = 0; t < 255; t++) {
							z[t] = m_d*t / 255;
							B1 = -exp(-m_v*(x + sqrt(x*x + y*y + z[t] * z[t])) / 2);
							B2 = 2 * sqrt(x*x + y*y + z[t] * z[t])* sqrt(x*x + y*y + z[t] * z[t])* sqrt(x*x + y*y + z[t] * z[t]);

							if (m_u == 1)
								S1 = S1 + (constP*znak*B1*(2 * x + m_v*(x*x + y*y + z[t] * z[t]) + m_v*x*sqrt(x*x + y*y + z[t] * z[t])) / B2)*dz;

							if (m_u == 0){
								kv = sqrt((float)m_v / 2);
								Rad = sqrt(x*x + y*y + z[t] * z[t]);

								switch (m_scanModes)
								{
								case 0:
									S1 = S1 + std::abs((double)(constP*znak*x)*((double)1 + kv * ((double)1 + ii))*((double)Rad*exp(-Rad*kv*((double)1 + ii)) / (double)B2))*dz;
									break;
								case 1:
									S1 = S1 + std::real((double)(constP*znak*x)*((double)1 + kv * ((double)1 + ii))*((double)Rad*exp(-Rad*kv*((double)1 + ii)) / (double)B2))*dz;
									break;
								case 2:
									S1 = S1 + std::imag((double)(constP*znak*x)*((double)1 + kv * ((double)1 + ii))*((double)Rad*exp(-Rad*kv*((double)1 + ii)) / (double)B2))*dz;
									break;
								default:
									S1 = S1 + 0;
									break;
								}								
							}
						}
						S = S + S1;
					}

					if ((p < (m_heightImage - 1)) && (colorRange[p*m_widthImage + q] != colorRange[(p + 1)*m_widthImage + q])) {
						x = (float)(q - j);
						y = p - i + (float)1 / 2;

						if (colorRange[p*m_widthImage + q] == -1)
							znak = 1;
						else
							znak = -1;

						S2 = 0;
						dz = m_d / 255;

						for (int t = 0; t < 255; t++) {
							z[t] = m_d*t / 255;
							B1 = -exp(-m_v*(x + sqrt(x*x + y*y + z[t] * z[t])) / 2);
							B2 = 2 * pow((x*x + y*y + z[t] * z[t]), ((float)3 / 2));

							if (m_u == 1)
								S2 = S2 + (constP*B1*znak*(2 * y + m_v*y*sqrt(x*x + y*y + z[t] * z[t])) / B2)*dz;

							if (m_u == 0) {
								kv = sqrt(m_v / 2);
								Rad = sqrt(x*x + y*y + z[t] * z[t]);

								switch (m_scanModes)
								{
								case 0:
									S2 = S2 + std::abs((double)(constP*znak*y)*((double)1 + kv*((double)1 + ii))*((double)Rad*exp(-Rad*kv*((double)1 + ii)) / (double)B2))*dz;
									break;
								case 1:
									S2 = S2 + std::real((double)(constP*znak*y)*((double)1 + kv*((double)1 + ii))*((double)Rad*exp(-Rad*kv*((double)1 + ii)) / (double)B2))*dz; 
									break;
								case 2:
									S2 = S2 + std::imag((double)(constP*znak*y)*((double)1 + kv*((double)1 + ii))*((double)Rad*exp(-Rad*kv*((double)1 + ii)) / (double)B2))*dz;
									break;
								default:
									S2 = S2 + 0;
									break;
								}								
							}
						}
						S = S + S2;
					}
				}
			}
			
			preView[i*m_widthImage + j] = S + sign(colorRange[i*m_widthImage + j]);
						
			// Вывод результирующей матрицы
			printf("%2.4f ", preView[i*m_widthImage + j]);
			fprintf(logOut, "%2.4f ", preView[i*m_widthImage + j]);
			saveLog();

			S = 0;
		}
		printf("\n");
		fprintf(logOut, "\n[%s] ", DateTime::Now.ToString());
		saveLog();
	}

	// -------------------------------------------------------------------
	// ---- Выбрав какую строку раскоментировать, а какую закоментировать
	// Мы выбираем как будет выглядеть конечное изображение при пересчете и его профиль
	//
	// В первом случае мы обрезаем матрицу до интервала [-1; 1]
	//
	// Во втором случае мы подгоняем глубину пикселей, их цвет по матрицу в зависимости от максимального элемента и минимального, т.е.
	// матрица может лежать в любом интервале (не только [-1; 1]), но на профиле будет отображаться график в интервале [-1.5; 1.5] (Можно поправить это но долго)
	// Этот интевал выбран, так как вроде (!!!) сильнее при пересчете значения матрицы не расходятся.
	// Второй вариант точно отображает картинку как в МАТЛАБЕ.


	//clip();		// 1. Если будем обрезать матрицу
	dontClip();		// 2. Если будем делать как в МатЛабе

	// -----
	// -------------------------------------------------------------------
	
	cvCvtPlaneToPix(m_grayDst, m_grayDst, m_grayDst, 0, _dst);

	// Закрытие линии загрузки
	_processingBar->Visible = false;

	printf("DONE!!!\n\n");

	// Подсчет времени выполнения 
	m_readTime = (clock() - m_currTime) / 1000;
	mse_w = (clock() - m_currTime) % 1000;
	sec_w = m_readTime % 60;
	min_w = (m_readTime / 60) % 60;
	hou_w = ((m_readTime / 60) / 60);
	_labelTime->Text = "" + hou_w + ":" + min_w + ":" + sec_w + " (" + mse_w + " ms)";
	fprintf(logOut, "\n[%s] Operation time: %s\n___________________________________\n", DateTime::Now.ToString(), _labelTime->Text);
	saveLog();

	return true;
}

// Преобразование в сигнал
int SemCalcImages::sign(int _in) {
	if (_in > 0) return 1;
	//if (_in == 0) return 0;
	if (_in < 0) return -1;

	return 0;
}

void SemCalcImages::logSettings() {
	fprintf(logOut, "\n[%s] Set parametrs:\n", DateTime::Now.ToString());
	fprintf(logOut, "d = %2.3f; k = %2.3f; w = %2.3f; v = %2.3f; u = %d; ", m_d, m_k, m_w, m_v, (int)m_u);
	if (m_u == 0) fprintf(logOut, "ScanningMode = %d;", m_scanModes);
	fprintf(logOut, "\n\n[%s] Start calculate: \n", DateTime::Now.ToString());
	saveLog();
}

void SemCalcImages::getProfile(System::Windows::Forms::PictureBox^ _picBox) {
	fprintf(logOut, "\n[%s] Get Profile :\n", DateTime::Now.ToString());
	for (int i = 0; i < m_widthImage; i++) {
		fprintf(logOut, "%2.4f ", preView[m_heightImage / 2 * m_widthImage + i]);
	}
	fprintf(logOut, "\n___________________________________\n");
	saveLog();

	using namespace System::Drawing;

	Font^ fn = gcnew Font(FontFamily::GenericSansSerif, 6.0F, FontStyle::Bold);
	Brush^ whiteBrush = gcnew SolidBrush(Color::White);
	Brush^ blackBrush = gcnew SolidBrush(Color::Black);
	Brush^ redBrush = gcnew SolidBrush(Color::Red);
	Pen^ whitePen = gcnew Pen(Color::White, 1);
	Pen^ bluePen = gcnew Pen(Color::Blue, 1);
	Pen^ redPen = gcnew Pen(Color::Red, 1);
	Pen^ blackPen = gcnew Pen(Color::Black, 1);
	Pen^ ellowPen = gcnew Pen(Color::GreenYellow, 1);
	ellowPen->DashStyle = Drawing2D::DashStyle::Dash;

	Graphics^ g = _picBox->CreateGraphics();

	g->FillRectangle(whiteBrush, 0, 0, _picBox->Width, _picBox->Height);

	g->DrawLine(blackPen, 20, 10, 20, _picBox->Height - 10);
	g->DrawLine(blackPen, 20, _picBox->Height / 2, _picBox->Width - 10, _picBox->Height / 2);

	int dx = (m_widthImage - 1) / 25;
	for (int i = 0; i <= (m_widthImage - 1); i += dx + 1) {
		g->DrawLine(ellowPen, (_picBox->Width - 30) * i / (m_widthImage - 1) + 20, 10, (_picBox->Width - 30) * i / (m_widthImage - 1) + 20, _picBox->Height - 10);
		int num = i + 1;
		g->DrawString("" + num, fn, blackBrush, (float)((_picBox->Width - 30) * i / (m_widthImage - 1) + 20), (float)_picBox->Height / 2);
	}

	if (isCrop) {
		for (int i = 0; i <= 20; i++) {
			g->DrawLine(ellowPen, 20, (_picBox->Height - 20) * i / 20 + 10, _picBox->Width - 10, (_picBox->Height - 20) * i / 20 + 10);
			g->DrawLine(blackPen, 15, (_picBox->Height - 20) * i / 20 + 10, 20, (_picBox->Height - 20) * i / 20 + 10);

			float num = 1 - 0.1f*i;
			System::String^ str = "" + num;
			g->DrawString(str, fn, blackBrush, (float)0, (float)((_picBox->Height - 20) * i / 20 + 10));
		}

		for (int i = 0; i < (m_widthImage - 1); i++) {
			g->DrawLine(bluePen, (float)((_picBox->Width - 30) * (i) / (m_widthImage - 1) + 20), (float)((_picBox->Height - 20) * ((-10)*preView[m_heightImage / 2 * m_widthImage + i] + 10) / 20 + 10),
				(float)((_picBox->Width - 30) * (i + 1) / (m_widthImage - 1) + 20), (float)((_picBox->Height - 20) * ((-10)*preView[m_heightImage / 2 * m_widthImage + i + 1] + 10) / 20 + 10));
		}
	}
	else {
		for (int i = 0; i <= 30; i++) {
			g->DrawLine(ellowPen, 20, (_picBox->Height - 20) * i / 30 + 10, _picBox->Width - 10, (_picBox->Height - 20) * i / 30 + 10);
			g->DrawLine(blackPen, 15, (_picBox->Height - 20) * i / 30 + 10, 20, (_picBox->Height - 20) * i / 30 + 10);

			float num = 1.5f - 0.1f*i;
			System::String^ str = "" + num;
			g->DrawString(str, fn, blackBrush, (float)0, (float)((_picBox->Height - 20) * i / 30 + 10));
		}

		for (int i = 0; i < (m_widthImage - 1); i++) {
			g->DrawLine(bluePen, (float)((_picBox->Width - 30) * (i) / (m_widthImage - 1) + 20), (float)((_picBox->Height - 20) * ((-10)*preView[m_heightImage / 2 * m_widthImage + i] + 15) / 30 + 10),
				(float)((_picBox->Width - 30) * (i + 1) / (m_widthImage - 1) + 20), (float)((_picBox->Height - 20) * ((-10)*preView[m_heightImage / 2 * m_widthImage + i + 1] + 15) / 30 + 10));
		}
	}
}

void SemCalcImages::clip() {	
	isCrop = true;
	// Цикл по строкам
	fprintf(logOut, "\n\n[%s] Result Image: \n", DateTime::Now.ToString());
	for (int i = 0; i < m_heightImage; i++) {
		// Получение пикселей по строкам конечного изображения в градациях серого
		uchar* ptr = (uchar*)(m_grayDst->imageData + i * m_grayDst->widthStep);
		// Цикл по столбцам
		for (int j = 0; j < m_widthImage; j++) {
			if (preView[i*m_widthImage + j] > 1) preView[i*m_widthImage + j] = 1;
			if (preView[i*m_widthImage + j] < -1) preView[i*m_widthImage + j] = -1;
			ptr[j] = (uchar)(preView[i*m_widthImage + j] * 127.5 + 127.5);
			fprintf(logOut, "%4d ", (int)(preView[i*m_widthImage + j] * 127.5 + 127.5));
		}
		fprintf(logOut, "\n");
	}
	saveLog();
}

void SemCalcImages::dontClip() {
	isCrop = false;

	fprintf(logOut, "\n\n[%s] Result Image: \n", DateTime::Now.ToString());

	double max = preView[0];
	double min = preView[0];

	// Цикл по строкам
	for (int i = 0; i < m_heightImage; i++) {
		// Цикл по столбцам
		for (int j = 0; j < m_widthImage; j++) {
			if (preView[i*m_widthImage + j] > max) max = preView[i*m_widthImage + j];
			if (preView[i*m_widthImage + j] < min) min = preView[i*m_widthImage + j];
		}
	}

	if (max == min) return;
	
	double forPixels = (double)255 / (max - min);

	// Цикл по строкам
	for (int i = 0; i < m_heightImage; i++) {
		// Получение пикселей по строкам конечного изображения в градациях серого
		uchar* ptr = (uchar*)(m_grayDst->imageData + i * m_grayDst->widthStep);
		// Цикл по столбцам
		for (int j = 0; j < m_widthImage; j++) {
			ptr[j] = (uchar)((preView[i*m_widthImage + j] - min) * forPixels);
			fprintf(logOut, "%4d ", (int)((preView[i*m_widthImage + j] - min) * forPixels));
		}
		fprintf(logOut, "\n");
	}
	saveLog();
}