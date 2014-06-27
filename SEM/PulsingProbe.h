#include "SemCalcImages.h"

#pragma once

namespace SEM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PulsingProbe
	/// </summary>
	public ref class PulsingProbe : public System::Windows::Forms::Form
	{
	public:
		PulsingProbe(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			core = SemCalcImages::GetInstance();
			// Приведение картинок к стандартному типу
			//Bitmap^ srcBmp = gcnew Bitmap(core->m_src->width, core->m_src->height, core->m_src->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (IntPtr)core->m_src->imageData);
			Bitmap^ rslBmp = gcnew Bitmap(core->m_rslPp->width, core->m_rslPp->height, core->m_rslPp->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (IntPtr)core->m_rslPp->imageData);
			// И вывод их на форму
			//pictureBoxSrcImage->Image = srcBmp;
			pictureBoxResultImage->Image = rslBmp;

			textBoxV->Text = "" + core->getV();
			switch (core->getScanMode())
			{
			case 0:
				radioButtonAmpSignal->Checked = true;
				break;
			case 1:
				radioButtonInphase->Checked = true;
				break;
			case 2:
				radioButtonReactive->Checked = true;
				break;
			default:
				radioButtonAmpSignal->Checked = true;
				break;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PulsingProbe()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBoxSimParam;
	private: System::Windows::Forms::GroupBox^  groupBoxScanModes;
	private: System::Windows::Forms::GroupBox^  groupBoxGraphModes;
	private: System::Windows::Forms::TextBox^  textBoxV;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::RadioButton^  radioButtonReactive;
	private: System::Windows::Forms::RadioButton^  radioButtonInphase;
	private: System::Windows::Forms::RadioButton^  radioButtonAmpSignal;
	private: System::Windows::Forms::Button^  buttonCalcProfile;
	private: System::Windows::Forms::Button^  buttonCalcImage;
	private: System::Windows::Forms::Button^  buttonSaveImage;
	private: System::Windows::Forms::Button^  buttonCloseForm;
	private: System::Windows::Forms::PictureBox^  pictureBoxResultImage;
	private: System::Windows::Forms::CheckBox^  checkBoxZoom;
	protected:

	private:
		SemCalcImages^ core;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialogImage;
	private: System::Windows::Forms::Label^  labelTime;
	private: System::Windows::Forms::ProgressBar^  processingBar;
			 /// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBoxSimParam = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxV = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBoxScanModes = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonReactive = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonInphase = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonAmpSignal = (gcnew System::Windows::Forms::RadioButton());
			this->groupBoxGraphModes = (gcnew System::Windows::Forms::GroupBox());
			this->buttonCalcProfile = (gcnew System::Windows::Forms::Button());
			this->buttonCalcImage = (gcnew System::Windows::Forms::Button());
			this->buttonSaveImage = (gcnew System::Windows::Forms::Button());
			this->buttonCloseForm = (gcnew System::Windows::Forms::Button());
			this->pictureBoxResultImage = (gcnew System::Windows::Forms::PictureBox());
			this->checkBoxZoom = (gcnew System::Windows::Forms::CheckBox());
			this->saveFileDialogImage = (gcnew System::Windows::Forms::SaveFileDialog());
			this->labelTime = (gcnew System::Windows::Forms::Label());
			this->processingBar = (gcnew System::Windows::Forms::ProgressBar());
			this->groupBoxSimParam->SuspendLayout();
			this->groupBoxScanModes->SuspendLayout();
			this->groupBoxGraphModes->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxResultImage))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Blue;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(600, 23);
			this->label1->TabIndex = 1;
			this->label1->Text = L"SEM-IMAGE OF FERROELECTRIC DOMAINS IN PULSING MODE";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBoxSimParam
			// 
			this->groupBoxSimParam->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBoxSimParam->Controls->Add(this->textBoxV);
			this->groupBoxSimParam->Controls->Add(this->label2);
			this->groupBoxSimParam->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBoxSimParam->Location = System::Drawing::Point(16, 54);
			this->groupBoxSimParam->Name = L"groupBoxSimParam";
			this->groupBoxSimParam->Size = System::Drawing::Size(301, 96);
			this->groupBoxSimParam->TabIndex = 2;
			this->groupBoxSimParam->TabStop = false;
			this->groupBoxSimParam->Text = L"SIMULATION PARAMETERS";
			// 
			// textBoxV
			// 
			this->textBoxV->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxV->Location = System::Drawing::Point(176, 43);
			this->textBoxV->Name = L"textBoxV";
			this->textBoxV->Size = System::Drawing::Size(100, 22);
			this->textBoxV->TabIndex = 2;
			this->textBoxV->Text = L"1,0";
			this->textBoxV->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(22, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(123, 43);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Pulsation frequency, arb.units";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBoxScanModes
			// 
			this->groupBoxScanModes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->groupBoxScanModes->Controls->Add(this->radioButtonReactive);
			this->groupBoxScanModes->Controls->Add(this->radioButtonInphase);
			this->groupBoxScanModes->Controls->Add(this->radioButtonAmpSignal);
			this->groupBoxScanModes->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBoxScanModes->Location = System::Drawing::Point(349, 54);
			this->groupBoxScanModes->Name = L"groupBoxScanModes";
			this->groupBoxScanModes->Size = System::Drawing::Size(247, 123);
			this->groupBoxScanModes->TabIndex = 3;
			this->groupBoxScanModes->TabStop = false;
			this->groupBoxScanModes->Text = L"SCANNING MODES IN PULSING MODE";
			// 
			// radioButtonReactive
			// 
			this->radioButtonReactive->AutoSize = true;
			this->radioButtonReactive->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButtonReactive->ForeColor = System::Drawing::Color::Blue;
			this->radioButtonReactive->Location = System::Drawing::Point(19, 82);
			this->radioButtonReactive->Name = L"radioButtonReactive";
			this->radioButtonReactive->Size = System::Drawing::Size(172, 19);
			this->radioButtonReactive->TabIndex = 2;
			this->radioButtonReactive->Text = L"Reactive Signal Component";
			this->radioButtonReactive->UseVisualStyleBackColor = true;
			// 
			// radioButtonInphase
			// 
			this->radioButtonInphase->AutoSize = true;
			this->radioButtonInphase->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButtonInphase->ForeColor = System::Drawing::Color::Blue;
			this->radioButtonInphase->Location = System::Drawing::Point(19, 57);
			this->radioButtonInphase->Name = L"radioButtonInphase";
			this->radioButtonInphase->Size = System::Drawing::Size(104, 19);
			this->radioButtonInphase->TabIndex = 1;
			this->radioButtonInphase->Text = L"Inphase Signal";
			this->radioButtonInphase->UseVisualStyleBackColor = true;
			// 
			// radioButtonAmpSignal
			// 
			this->radioButtonAmpSignal->AutoSize = true;
			this->radioButtonAmpSignal->Checked = true;
			this->radioButtonAmpSignal->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButtonAmpSignal->ForeColor = System::Drawing::Color::Blue;
			this->radioButtonAmpSignal->Location = System::Drawing::Point(19, 32);
			this->radioButtonAmpSignal->Name = L"radioButtonAmpSignal";
			this->radioButtonAmpSignal->Size = System::Drawing::Size(117, 19);
			this->radioButtonAmpSignal->TabIndex = 0;
			this->radioButtonAmpSignal->TabStop = true;
			this->radioButtonAmpSignal->Text = L"Amplitude Signal";
			this->radioButtonAmpSignal->UseVisualStyleBackColor = true;
			// 
			// groupBoxGraphModes
			// 
			this->groupBoxGraphModes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->groupBoxGraphModes->Controls->Add(this->buttonCalcProfile);
			this->groupBoxGraphModes->Controls->Add(this->buttonCalcImage);
			this->groupBoxGraphModes->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBoxGraphModes->Location = System::Drawing::Point(349, 224);
			this->groupBoxGraphModes->Name = L"groupBoxGraphModes";
			this->groupBoxGraphModes->Size = System::Drawing::Size(247, 120);
			this->groupBoxGraphModes->TabIndex = 4;
			this->groupBoxGraphModes->TabStop = false;
			this->groupBoxGraphModes->Text = L"SIMULATION GRAPH MODES";
			// 
			// buttonCalcProfile
			// 
			this->buttonCalcProfile->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCalcProfile->ForeColor = System::Drawing::Color::Blue;
			this->buttonCalcProfile->Location = System::Drawing::Point(37, 68);
			this->buttonCalcProfile->Name = L"buttonCalcProfile";
			this->buttonCalcProfile->Size = System::Drawing::Size(173, 28);
			this->buttonCalcProfile->TabIndex = 1;
			this->buttonCalcProfile->Text = L"Calculate Profile";
			this->buttonCalcProfile->UseVisualStyleBackColor = true;
			this->buttonCalcProfile->Click += gcnew System::EventHandler(this, &PulsingProbe::buttonCalcProfile_Click);
			// 
			// buttonCalcImage
			// 
			this->buttonCalcImage->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCalcImage->ForeColor = System::Drawing::Color::Blue;
			this->buttonCalcImage->Location = System::Drawing::Point(37, 34);
			this->buttonCalcImage->Name = L"buttonCalcImage";
			this->buttonCalcImage->Size = System::Drawing::Size(173, 28);
			this->buttonCalcImage->TabIndex = 0;
			this->buttonCalcImage->Text = L"Calculate Image";
			this->buttonCalcImage->UseVisualStyleBackColor = true;
			this->buttonCalcImage->Click += gcnew System::EventHandler(this, &PulsingProbe::buttonCalcImage_Click);
			// 
			// buttonSaveImage
			// 
			this->buttonSaveImage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonSaveImage->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSaveImage->ForeColor = System::Drawing::Color::Blue;
			this->buttonSaveImage->Location = System::Drawing::Point(349, 372);
			this->buttonSaveImage->Name = L"buttonSaveImage";
			this->buttonSaveImage->Size = System::Drawing::Size(115, 28);
			this->buttonSaveImage->TabIndex = 5;
			this->buttonSaveImage->Text = L"Save Image";
			this->buttonSaveImage->UseVisualStyleBackColor = true;
			this->buttonSaveImage->Click += gcnew System::EventHandler(this, &PulsingProbe::buttonSaveImage_Click);
			// 
			// buttonCloseForm
			// 
			this->buttonCloseForm->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonCloseForm->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCloseForm->ForeColor = System::Drawing::Color::Blue;
			this->buttonCloseForm->Location = System::Drawing::Point(481, 372);
			this->buttonCloseForm->Name = L"buttonCloseForm";
			this->buttonCloseForm->Size = System::Drawing::Size(115, 28);
			this->buttonCloseForm->TabIndex = 6;
			this->buttonCloseForm->Text = L"Close Form";
			this->buttonCloseForm->UseVisualStyleBackColor = true;
			this->buttonCloseForm->Click += gcnew System::EventHandler(this, &PulsingProbe::buttonCloseForm_Click);
			// 
			// pictureBoxResultImage
			// 
			this->pictureBoxResultImage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxResultImage->Location = System::Drawing::Point(12, 167);
			this->pictureBoxResultImage->Name = L"pictureBoxResultImage";
			this->pictureBoxResultImage->Size = System::Drawing::Size(305, 210);
			this->pictureBoxResultImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxResultImage->TabIndex = 7;
			this->pictureBoxResultImage->TabStop = false;
			// 
			// checkBoxZoom
			// 
			this->checkBoxZoom->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->checkBoxZoom->AutoSize = true;
			this->checkBoxZoom->Checked = true;
			this->checkBoxZoom->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxZoom->Location = System::Drawing::Point(12, 383);
			this->checkBoxZoom->Name = L"checkBoxZoom";
			this->checkBoxZoom->Size = System::Drawing::Size(85, 17);
			this->checkBoxZoom->TabIndex = 8;
			this->checkBoxZoom->Text = L"Zoom Image";
			this->checkBoxZoom->UseVisualStyleBackColor = true;
			this->checkBoxZoom->CheckedChanged += gcnew System::EventHandler(this, &PulsingProbe::checkBoxZoom_CheckedChanged);
			// 
			// labelTime
			// 
			this->labelTime->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->labelTime->Location = System::Drawing::Point(501, 406);
			this->labelTime->Name = L"labelTime";
			this->labelTime->Size = System::Drawing::Size(95, 23);
			this->labelTime->TabIndex = 10;
			this->labelTime->Text = L"00:00:00 (000 ms)";
			this->labelTime->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// processingBar
			// 
			this->processingBar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->processingBar->Location = System::Drawing::Point(12, 406);
			this->processingBar->Name = L"processingBar";
			this->processingBar->Size = System::Drawing::Size(483, 23);
			this->processingBar->TabIndex = 9;
			this->processingBar->Visible = false;
			// 
			// PulsingProbe
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(624, 441);
			this->Controls->Add(this->labelTime);
			this->Controls->Add(this->processingBar);
			this->Controls->Add(this->checkBoxZoom);
			this->Controls->Add(this->pictureBoxResultImage);
			this->Controls->Add(this->buttonCloseForm);
			this->Controls->Add(this->buttonSaveImage);
			this->Controls->Add(this->groupBoxGraphModes);
			this->Controls->Add(this->groupBoxScanModes);
			this->Controls->Add(this->groupBoxSimParam);
			this->Controls->Add(this->label1);
			this->Name = L"PulsingProbe";
			this->Text = L"Pulsing Probe";
			this->Shown += gcnew System::EventHandler(this, &PulsingProbe::PulsingProbe_Shown);
			this->groupBoxSimParam->ResumeLayout(false);
			this->groupBoxSimParam->PerformLayout();
			this->groupBoxScanModes->ResumeLayout(false);
			this->groupBoxScanModes->PerformLayout();
			this->groupBoxGraphModes->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxResultImage))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonCloseForm_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
	}
private: System::Void checkBoxZoom_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (checkBoxZoom->Checked) {
				 pictureBoxResultImage->SizeMode = PictureBoxSizeMode::Zoom;
			 }
			 else {
				 pictureBoxResultImage->SizeMode = PictureBoxSizeMode::CenterImage;
			 }
}
private: System::Void buttonSaveImage_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Настройка окна сохранение картинки
			 saveFileDialogImage->Filter = "Image Files(*.BMP;*.JPG;*.GIF;*.TIF;*.PNG)|*.BMP;*.JPG;*.GIF;*.TIF;*.PNG";
			 saveFileDialogImage->FilterIndex = 2;
			 saveFileDialogImage->RestoreDirectory = true;
			 // Если нажата кнопка ОК
			 if (saveFileDialogImage->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				 using namespace System::Runtime::InteropServices;
				 const char *flnm = (const char*)(void*)Marshal::StringToHGlobalAnsi(saveFileDialogImage->FileName);
				 // Сохраняем изображение с именем и расширением, которое указано в поле имя файла
				 // (Поддерживаемые форматы *.jpg, *.bmp, *.tif, *.png)
				 cvSaveImage(flnm, core->m_rslPp);
			 }
}
private: System::Void PulsingProbe_Shown(System::Object^  sender, System::EventArgs^  e) {
			 // Приведение картинок к стандартному типу
			 //Bitmap^ srcBmp = gcnew Bitmap(core->m_src->width, core->m_src->height, core->m_src->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (IntPtr)core->m_src->imageData);
			 Bitmap^ rslBmp = gcnew Bitmap(core->m_rslPp->width, core->m_rslPp->height, core->m_rslPp->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (IntPtr)core->m_rslPp->imageData);
			 // И вывод их на форму
			 //pictureBoxSrcImage->Image = srcBmp;
			 pictureBoxResultImage->Image = rslBmp;

			 processingBar->Visible = false;
			 labelTime->Text = "00:00:00 (000 ms)";
}
private: System::Void buttonCalcImage_Click(System::Object^  sender, System::EventArgs^  e) {
			 buttonCalcImage->Enabled = false;

			 core->setV(float::Parse(textBoxV->Text));

			 int checkMode = 0;
			 if (radioButtonAmpSignal->Checked) checkMode = 0;
			 if (radioButtonInphase->Checked) checkMode = 1;
			 if (radioButtonReactive->Checked) checkMode = 2;
			 
			 core->setScanMode(checkMode);
			 core->logSettings();
			 //core->calculateImage(core->m_rslCp);
			 core->calculate(core->m_rslPp, processingBar, labelTime);
			 
			 for (int i = 0; i < core->m_rslPp->height; i++) {
				 // Получение пикселей по строкам конечного изображения в градациях серого
				 //uchar* ptr1 = (uchar*)(core->m_rslCp->imageData + i * core->m_rslCp->widthStep);
				 uchar* ptr2 = (uchar*)(core->m_rslPp->imageData + i * core->m_rslPp->widthStep);
				 // Цикл по столбцам
				 for (int j = 0; j < core->m_rslPp->width * 3; j += 3) {
					 //printf("%3d (%3d) ", (int)ptr1[j], (int)ptr2[j]);
					 printf("%3d ", (int)ptr2[j]);
				 }
				 printf("\n");
			 }

			 // Приведение картинок к стандартному типу
			 //Bitmap^ srcBmp = gcnew Bitmap(core->m_src->width, core->m_src->height, core->m_src->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (IntPtr)core->m_src->imageData);
			 Bitmap^ rslBmp = gcnew Bitmap(core->m_rslPp->width, core->m_rslPp->height, core->m_rslPp->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (IntPtr)core->m_rslPp->imageData);
			 // И вывод их на форму
			 //pictureBoxSrcImage->Image = srcBmp;
			 pictureBoxResultImage->Image = rslBmp;

			 buttonCalcImage->Enabled = true;
}
private: System::Void buttonCalcProfile_Click(System::Object^  sender, System::EventArgs^  e) {
			 core->getProfile(pictureBoxResultImage);
}
};
}
