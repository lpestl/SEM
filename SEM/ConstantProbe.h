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
	/// Summary for ConstantProbe
	/// </summary>
	public ref class ConstantProbe : public System::Windows::Forms::Form
	{
	public:
		ConstantProbe(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			core = SemCalcImages::GetInstance();
			// Приведение картинок к стандартному типу
			//Bitmap^ srcBmp = gcnew Bitmap(core->m_src->width, core->m_src->height, core->m_src->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (IntPtr)core->m_src->imageData);
			Bitmap^ rslBmp = gcnew Bitmap(core->m_rslCp->width, core->m_rslCp->height, core->m_rslCp->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (IntPtr)core->m_rslCp->imageData);
			// И вывод их на форму
			//pictureBoxSrcImage->Image = srcBmp;
			pictureBoxResultConst->Image = rslBmp;

			textBoxV->Text = "" + core->getV();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ConstantProbe()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBoxSimParam;
	private: System::Windows::Forms::TextBox^  textBoxV;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::GroupBox^  groupBoxGraphModes;
	private: System::Windows::Forms::Button^  buttonCalcProfile;
	private: System::Windows::Forms::Button^  buttonCalcImage;
	private: System::Windows::Forms::PictureBox^  pictureBoxResultConst;
	private: System::Windows::Forms::Button^  buttonSaveImage;
	private: System::Windows::Forms::Button^  buttonCloseForm;
	private: System::Windows::Forms::CheckBox^  checkBoxZoom;
	protected:

	private:
		SemCalcImages^ core;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialogImage;
	private: System::Windows::Forms::ProgressBar^  processingBar;

	private: System::Windows::Forms::Label^  labelTime;

	private: System::ComponentModel::IContainer^  components;
			 /// <summary>
		/// Required designer variable.
		/// </summary>


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
			this->groupBoxGraphModes = (gcnew System::Windows::Forms::GroupBox());
			this->buttonCalcProfile = (gcnew System::Windows::Forms::Button());
			this->buttonCalcImage = (gcnew System::Windows::Forms::Button());
			this->pictureBoxResultConst = (gcnew System::Windows::Forms::PictureBox());
			this->buttonSaveImage = (gcnew System::Windows::Forms::Button());
			this->buttonCloseForm = (gcnew System::Windows::Forms::Button());
			this->checkBoxZoom = (gcnew System::Windows::Forms::CheckBox());
			this->saveFileDialogImage = (gcnew System::Windows::Forms::SaveFileDialog());
			this->processingBar = (gcnew System::Windows::Forms::ProgressBar());
			this->labelTime = (gcnew System::Windows::Forms::Label());
			this->groupBoxSimParam->SuspendLayout();
			this->groupBoxGraphModes->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxResultConst))->BeginInit();
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
			this->label1->TabIndex = 0;
			this->label1->Text = L"SEM-IMAGE OF FERROELECTRIC DOMAINS IN THE HEAT SOURCE MODE";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBoxSimParam
			// 
			this->groupBoxSimParam->Controls->Add(this->textBoxV);
			this->groupBoxSimParam->Controls->Add(this->label2);
			this->groupBoxSimParam->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBoxSimParam->Location = System::Drawing::Point(16, 72);
			this->groupBoxSimParam->Name = L"groupBoxSimParam";
			this->groupBoxSimParam->Size = System::Drawing::Size(278, 102);
			this->groupBoxSimParam->TabIndex = 1;
			this->groupBoxSimParam->TabStop = false;
			this->groupBoxSimParam->Text = L"SIMULATION PARAMETERS";
			// 
			// textBoxV
			// 
			this->textBoxV->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxV->Location = System::Drawing::Point(161, 45);
			this->textBoxV->Name = L"textBoxV";
			this->textBoxV->Size = System::Drawing::Size(100, 22);
			this->textBoxV->TabIndex = 1;
			this->textBoxV->Text = L"1,0";
			this->textBoxV->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(22, 34);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(123, 43);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Scanning velocity, arb.units";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBoxGraphModes
			// 
			this->groupBoxGraphModes->Controls->Add(this->buttonCalcProfile);
			this->groupBoxGraphModes->Controls->Add(this->buttonCalcImage);
			this->groupBoxGraphModes->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBoxGraphModes->Location = System::Drawing::Point(16, 224);
			this->groupBoxGraphModes->Name = L"groupBoxGraphModes";
			this->groupBoxGraphModes->Size = System::Drawing::Size(278, 128);
			this->groupBoxGraphModes->TabIndex = 2;
			this->groupBoxGraphModes->TabStop = false;
			this->groupBoxGraphModes->Text = L"SIMULATION GRAPH MODES";
			// 
			// buttonCalcProfile
			// 
			this->buttonCalcProfile->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCalcProfile->ForeColor = System::Drawing::Color::Blue;
			this->buttonCalcProfile->Location = System::Drawing::Point(42, 77);
			this->buttonCalcProfile->Name = L"buttonCalcProfile";
			this->buttonCalcProfile->Size = System::Drawing::Size(196, 26);
			this->buttonCalcProfile->TabIndex = 1;
			this->buttonCalcProfile->Text = L"Calculate Profile";
			this->buttonCalcProfile->UseVisualStyleBackColor = true;
			this->buttonCalcProfile->Click += gcnew System::EventHandler(this, &ConstantProbe::buttonCalcProfile_Click);
			// 
			// buttonCalcImage
			// 
			this->buttonCalcImage->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCalcImage->ForeColor = System::Drawing::Color::Blue;
			this->buttonCalcImage->Location = System::Drawing::Point(42, 35);
			this->buttonCalcImage->Name = L"buttonCalcImage";
			this->buttonCalcImage->Size = System::Drawing::Size(196, 26);
			this->buttonCalcImage->TabIndex = 0;
			this->buttonCalcImage->Text = L"Calculate Image";
			this->buttonCalcImage->UseVisualStyleBackColor = true;
			this->buttonCalcImage->Click += gcnew System::EventHandler(this, &ConstantProbe::buttonCalcImage_Click);
			// 
			// pictureBoxResultConst
			// 
			this->pictureBoxResultConst->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxResultConst->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pictureBoxResultConst->Location = System::Drawing::Point(321, 72);
			this->pictureBoxResultConst->Name = L"pictureBoxResultConst";
			this->pictureBoxResultConst->Size = System::Drawing::Size(291, 272);
			this->pictureBoxResultConst->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxResultConst->TabIndex = 3;
			this->pictureBoxResultConst->TabStop = false;
			// 
			// buttonSaveImage
			// 
			this->buttonSaveImage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonSaveImage->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSaveImage->ForeColor = System::Drawing::Color::Blue;
			this->buttonSaveImage->Location = System::Drawing::Point(58, 402);
			this->buttonSaveImage->Name = L"buttonSaveImage";
			this->buttonSaveImage->Size = System::Drawing::Size(196, 27);
			this->buttonSaveImage->TabIndex = 4;
			this->buttonSaveImage->Text = L"Save Image";
			this->buttonSaveImage->UseVisualStyleBackColor = true;
			this->buttonSaveImage->Click += gcnew System::EventHandler(this, &ConstantProbe::buttonSaveImage_Click);
			// 
			// buttonCloseForm
			// 
			this->buttonCloseForm->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonCloseForm->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCloseForm->ForeColor = System::Drawing::Color::Blue;
			this->buttonCloseForm->Location = System::Drawing::Point(421, 402);
			this->buttonCloseForm->Name = L"buttonCloseForm";
			this->buttonCloseForm->Size = System::Drawing::Size(191, 27);
			this->buttonCloseForm->TabIndex = 5;
			this->buttonCloseForm->Text = L"Close Form";
			this->buttonCloseForm->UseVisualStyleBackColor = true;
			this->buttonCloseForm->Click += gcnew System::EventHandler(this, &ConstantProbe::buttonCloseForm_Click);
			// 
			// checkBoxZoom
			// 
			this->checkBoxZoom->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->checkBoxZoom->AutoSize = true;
			this->checkBoxZoom->Checked = true;
			this->checkBoxZoom->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxZoom->Location = System::Drawing::Point(321, 350);
			this->checkBoxZoom->Name = L"checkBoxZoom";
			this->checkBoxZoom->Size = System::Drawing::Size(84, 17);
			this->checkBoxZoom->TabIndex = 6;
			this->checkBoxZoom->Text = L"Zoom image";
			this->checkBoxZoom->UseVisualStyleBackColor = true;
			this->checkBoxZoom->CheckedChanged += gcnew System::EventHandler(this, &ConstantProbe::checkBoxZoom_CheckedChanged);
			// 
			// processingBar
			// 
			this->processingBar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->processingBar->Location = System::Drawing::Point(16, 372);
			this->processingBar->Name = L"processingBar";
			this->processingBar->Size = System::Drawing::Size(496, 23);
			this->processingBar->TabIndex = 7;
			this->processingBar->Visible = false;
			// 
			// labelTime
			// 
			this->labelTime->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->labelTime->Location = System::Drawing::Point(518, 372);
			this->labelTime->Name = L"labelTime";
			this->labelTime->Size = System::Drawing::Size(94, 23);
			this->labelTime->TabIndex = 8;
			this->labelTime->Text = L"00:00:00 (000 ms)";
			this->labelTime->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ConstantProbe
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(624, 441);
			this->Controls->Add(this->labelTime);
			this->Controls->Add(this->processingBar);
			this->Controls->Add(this->checkBoxZoom);
			this->Controls->Add(this->buttonCloseForm);
			this->Controls->Add(this->buttonSaveImage);
			this->Controls->Add(this->pictureBoxResultConst);
			this->Controls->Add(this->groupBoxGraphModes);
			this->Controls->Add(this->groupBoxSimParam);
			this->Controls->Add(this->label1);
			this->Name = L"ConstantProbe";
			this->Text = L"Constant Probe";
			this->Shown += gcnew System::EventHandler(this, &ConstantProbe::ConstantProbe_Shown);
			this->groupBoxSimParam->ResumeLayout(false);
			this->groupBoxSimParam->PerformLayout();
			this->groupBoxGraphModes->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxResultConst))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonCloseForm_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
	}
private: System::Void checkBoxZoom_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (checkBoxZoom->Checked) {
				 pictureBoxResultConst->SizeMode = PictureBoxSizeMode::Zoom;
			 }
			 else {
				 pictureBoxResultConst->SizeMode = PictureBoxSizeMode::CenterImage;
			 }
}
private: System::Void buttonCalcImage_Click(System::Object^  sender, System::EventArgs^  e) {
			 buttonCalcImage->Enabled = false;

			 core->setV(float::Parse(textBoxV->Text));
			 core->logSettings();
			 //core->calculateImage(core->m_rslCp);
			 core->calculate(core->m_rslCp, processingBar, labelTime);

			 for (int i = 0; i < core->m_rslCp->height; i++) {
				 // Получение пикселей по строкам конечного изображения в градациях серого
				 uchar* ptr1 = (uchar*)(core->m_rslCp->imageData + i * core->m_rslCp->widthStep);
				 //uchar* ptr2 = (uchar*)(m_rslPp->imageData + i * m_rslPp->widthStep);
				 // Цикл по столбцам
				 for (int j = 0; j < core->m_rslCp->width * 3; j += 3) {
					//printf("%3d (%3d) ", (int)ptr1[j], (int)ptr2[j]);
					 printf("%3d ", (int)ptr1[j]);
				 }
				 printf("\n");
			 }

			 // Приведение картинок к стандартному типу
			 //Bitmap^ srcBmp = gcnew Bitmap(core->m_src->width, core->m_src->height, core->m_src->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (IntPtr)core->m_src->imageData);
			 Bitmap^ rslBmp = gcnew Bitmap(core->m_rslCp->width, core->m_rslCp->height, core->m_rslCp->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (IntPtr)core->m_rslCp->imageData);
			 // И вывод их на форму
			 //pictureBoxSrcImage->Image = srcBmp;
			 pictureBoxResultConst->Image = rslBmp;

			 buttonCalcImage->Enabled = true;
}
private: System::Void buttonSaveImage_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Настройка окна сохранение картинки
			 saveFileDialogImage->Filter = "Image Files(*.BMP;*.JPG;*.GIF;*.TIF;*.PNG)|*.BMP;*.JPG;*.GIF*.TIF;*.PNG";
			 saveFileDialogImage->FilterIndex = 2;
			 saveFileDialogImage->RestoreDirectory = true;
			 // Если нажата кнопка ОК
			 if (saveFileDialogImage->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				 using namespace System::Runtime::InteropServices;
				 const char *flnm = (const char*)(void*)Marshal::StringToHGlobalAnsi(saveFileDialogImage->FileName);
				 // Сохраняем изображение с именем и расширением, которое указано в поле имя файла
				 // (Поддерживаемые форматы *.jpg, *.bmp, *.tif, *.png)
				 cvSaveImage(flnm, core->m_rslCp);
			 }
}
private: System::Void ConstantProbe_Shown(System::Object^  sender, System::EventArgs^  e) {
			 // Приведение картинок к стандартному типу
			 //Bitmap^ srcBmp = gcnew Bitmap(core->m_src->width, core->m_src->height, core->m_src->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (IntPtr)core->m_src->imageData);
			 Bitmap^ rslBmp = gcnew Bitmap(core->m_rslCp->width, core->m_rslCp->height, core->m_rslCp->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (IntPtr)core->m_rslCp->imageData);
			 // И вывод их на форму
			 //pictureBoxSrcImage->Image = srcBmp;
			 pictureBoxResultConst->Image = rslBmp;

			 processingBar->Visible = false;
			 labelTime->Text = "00:00:00 (000 ms)";
}
private: System::Void buttonCalcProfile_Click(System::Object^  sender, System::EventArgs^  e) {
			 core->getProfile(pictureBoxResultConst);
}
};
}
