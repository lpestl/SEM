#include "ConstantProbe.h"
#include "PulsingProbe.h"
#include "SemCalcImages.h"
#include <stdio.h>

#pragma once

namespace SEM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SEMmainForm
	/// </summary>
	public ref class SEMmainForm : public System::Windows::Forms::Form
	{
	public:
		SEMmainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			// Получаем ссылу на объекта класса, который производит подсчеты
			core = SemCalcImages::GetInstance();
			// Загружаем начальное изображение
			core->loadImage("inital_sample.TIF");
			// Приведение картинок к стандартному типу
			Bitmap^ srcBmp = gcnew Bitmap(core->m_src->width, core->m_src->height, core->m_src->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (IntPtr)core->m_src->imageData);
			//Bitmap^ rslBmp = gcnew Bitmap(core->m_rsl->width, core->m_rsl->height, core->m_rsl->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (IntPtr)core->m_rsl->imageData);
			// И вывод их на форму
			pictureBoxSrcImage->Image = srcBmp;
			//pictureBoxRsl->Image = rslBmp;

			// Создаем экземпляры дополнительных форм 
			constForm = gcnew ConstantProbe();
			pulsingForm = gcnew PulsingProbe();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SEMmainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::GroupBox^  groupBoxSimParam;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBoxC;

	private: System::Windows::Forms::TextBox^  textBoxRo;

	private: System::Windows::Forms::TextBox^  textBoxGamma;

	private: System::Windows::Forms::TextBox^  textBoxK;

	private: System::Windows::Forms::TextBox^  textBoxW;

	private: System::Windows::Forms::TextBox^  textBoxD;
	private: System::Windows::Forms::GroupBox^  groupBoxScanModes;
	private: System::Windows::Forms::Button^  buttonPulsingProbe;
	private: System::Windows::Forms::Button^  buttonConstProbe;
	private: System::Windows::Forms::GroupBox^  groupBoxDownloadInitImage;
	private: System::Windows::Forms::Button^  buttonDownload;
	private: System::Windows::Forms::Button^  buttonExit;
	private: System::Windows::Forms::PictureBox^  pictureBoxSrcImage;
	private: System::Windows::Forms::CheckBox^  checkBoxZoom;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialogImage;


	private:
		ConstantProbe^ constForm;
		PulsingProbe^ pulsingForm;
		SemCalcImages^ core;

	private: void setParametrsFromMainForm(float _d, float _w, float _k, float _gamma, float _ro, float _c, float _u) {
				 core->setD(_d);
				 core->setW(_w);
				 core->setK(_k);
				 core->setGamma(_gamma);
				 core->setRo(_ro);
				 core->setC(_c);
				 core->setU(_u);
	}
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SEMmainForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBoxSimParam = (gcnew System::Windows::Forms::GroupBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxC = (gcnew System::Windows::Forms::TextBox());
			this->textBoxRo = (gcnew System::Windows::Forms::TextBox());
			this->textBoxGamma = (gcnew System::Windows::Forms::TextBox());
			this->textBoxK = (gcnew System::Windows::Forms::TextBox());
			this->textBoxW = (gcnew System::Windows::Forms::TextBox());
			this->textBoxD = (gcnew System::Windows::Forms::TextBox());
			this->groupBoxScanModes = (gcnew System::Windows::Forms::GroupBox());
			this->buttonPulsingProbe = (gcnew System::Windows::Forms::Button());
			this->buttonConstProbe = (gcnew System::Windows::Forms::Button());
			this->groupBoxDownloadInitImage = (gcnew System::Windows::Forms::GroupBox());
			this->buttonDownload = (gcnew System::Windows::Forms::Button());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->pictureBoxSrcImage = (gcnew System::Windows::Forms::PictureBox());
			this->checkBoxZoom = (gcnew System::Windows::Forms::CheckBox());
			this->openFileDialogImage = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBoxSimParam->SuspendLayout();
			this->groupBoxScanModes->SuspendLayout();
			this->groupBoxDownloadInitImage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSrcImage))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label1->Location = System::Drawing::Point(44, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(528, 19);
			this->label1->TabIndex = 0;
			this->label1->Text = L"SEM-IMAGES SIMULATION OF FERROELECTRIC DOMAIN STRUCTURES";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label2->Location = System::Drawing::Point(210, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(176, 19);
			this->label2->TabIndex = 1;
			this->label2->Text = L"IN PYROELECTRIC MODE";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBoxSimParam
			// 
			this->groupBoxSimParam->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->groupBoxSimParam->Controls->Add(this->label8);
			this->groupBoxSimParam->Controls->Add(this->label7);
			this->groupBoxSimParam->Controls->Add(this->label6);
			this->groupBoxSimParam->Controls->Add(this->label5);
			this->groupBoxSimParam->Controls->Add(this->label4);
			this->groupBoxSimParam->Controls->Add(this->label3);
			this->groupBoxSimParam->Controls->Add(this->textBoxC);
			this->groupBoxSimParam->Controls->Add(this->textBoxRo);
			this->groupBoxSimParam->Controls->Add(this->textBoxGamma);
			this->groupBoxSimParam->Controls->Add(this->textBoxK);
			this->groupBoxSimParam->Controls->Add(this->textBoxW);
			this->groupBoxSimParam->Controls->Add(this->textBoxD);
			this->groupBoxSimParam->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBoxSimParam->Location = System::Drawing::Point(12, 50);
			this->groupBoxSimParam->Name = L"groupBoxSimParam";
			this->groupBoxSimParam->Size = System::Drawing::Size(283, 287);
			this->groupBoxSimParam->TabIndex = 2;
			this->groupBoxSimParam->TabStop = false;
			this->groupBoxSimParam->Text = L"SIMULATION PARAMETERS";
			// 
			// label8
			// 
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(20, 226);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(122, 34);
			this->label8->TabIndex = 11;
			this->label8->Text = L"Heat capacity, arb.units";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label7
			// 
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(20, 185);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(122, 34);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Density, arb.units";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(20, 144);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(122, 34);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Pyroelectric coefficient, arb.units";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(20, 103);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(122, 34);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Heat conductivity coefficient, arb.units";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(20, 62);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(122, 34);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Source power, arb.units";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(20, 21);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(122, 34);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Crystal thickness, arb.units";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBoxC
			// 
			this->textBoxC->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxC->Location = System::Drawing::Point(161, 233);
			this->textBoxC->Name = L"textBoxC";
			this->textBoxC->Size = System::Drawing::Size(100, 22);
			this->textBoxC->TabIndex = 5;
			this->textBoxC->Text = L"1,0";
			this->textBoxC->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBoxRo
			// 
			this->textBoxRo->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxRo->Location = System::Drawing::Point(161, 192);
			this->textBoxRo->Name = L"textBoxRo";
			this->textBoxRo->Size = System::Drawing::Size(100, 22);
			this->textBoxRo->TabIndex = 4;
			this->textBoxRo->Text = L"1,0";
			this->textBoxRo->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBoxGamma
			// 
			this->textBoxGamma->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxGamma->Location = System::Drawing::Point(161, 151);
			this->textBoxGamma->Name = L"textBoxGamma";
			this->textBoxGamma->Size = System::Drawing::Size(100, 22);
			this->textBoxGamma->TabIndex = 3;
			this->textBoxGamma->Text = L"0,5";
			this->textBoxGamma->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBoxK
			// 
			this->textBoxK->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxK->Location = System::Drawing::Point(161, 110);
			this->textBoxK->Name = L"textBoxK";
			this->textBoxK->Size = System::Drawing::Size(100, 22);
			this->textBoxK->TabIndex = 2;
			this->textBoxK->Text = L"1,0";
			this->textBoxK->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBoxW
			// 
			this->textBoxW->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxW->Location = System::Drawing::Point(161, 69);
			this->textBoxW->Name = L"textBoxW";
			this->textBoxW->Size = System::Drawing::Size(100, 22);
			this->textBoxW->TabIndex = 1;
			this->textBoxW->Text = L"1,0";
			this->textBoxW->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBoxD
			// 
			this->textBoxD->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxD->Location = System::Drawing::Point(161, 28);
			this->textBoxD->Name = L"textBoxD";
			this->textBoxD->Size = System::Drawing::Size(100, 22);
			this->textBoxD->TabIndex = 0;
			this->textBoxD->Text = L"1,0";
			this->textBoxD->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// groupBoxScanModes
			// 
			this->groupBoxScanModes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->groupBoxScanModes->Controls->Add(this->buttonPulsingProbe);
			this->groupBoxScanModes->Controls->Add(this->buttonConstProbe);
			this->groupBoxScanModes->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBoxScanModes->Location = System::Drawing::Point(13, 343);
			this->groupBoxScanModes->Name = L"groupBoxScanModes";
			this->groupBoxScanModes->Size = System::Drawing::Size(282, 87);
			this->groupBoxScanModes->TabIndex = 3;
			this->groupBoxScanModes->TabStop = false;
			this->groupBoxScanModes->Text = L"SCANNING MODES";
			// 
			// buttonPulsingProbe
			// 
			this->buttonPulsingProbe->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonPulsingProbe->ForeColor = System::Drawing::Color::Blue;
			this->buttonPulsingProbe->Location = System::Drawing::Point(22, 50);
			this->buttonPulsingProbe->Name = L"buttonPulsingProbe";
			this->buttonPulsingProbe->Size = System::Drawing::Size(238, 23);
			this->buttonPulsingProbe->TabIndex = 1;
			this->buttonPulsingProbe->Text = L"Pulsing Probe";
			this->buttonPulsingProbe->UseVisualStyleBackColor = true;
			this->buttonPulsingProbe->Click += gcnew System::EventHandler(this, &SEMmainForm::buttonPulsingProbe_Click);
			// 
			// buttonConstProbe
			// 
			this->buttonConstProbe->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonConstProbe->ForeColor = System::Drawing::Color::Blue;
			this->buttonConstProbe->Location = System::Drawing::Point(22, 21);
			this->buttonConstProbe->Name = L"buttonConstProbe";
			this->buttonConstProbe->Size = System::Drawing::Size(238, 23);
			this->buttonConstProbe->TabIndex = 0;
			this->buttonConstProbe->Text = L"Constant Probe";
			this->buttonConstProbe->UseVisualStyleBackColor = true;
			this->buttonConstProbe->Click += gcnew System::EventHandler(this, &SEMmainForm::buttonConstProbe_Click);
			// 
			// groupBoxDownloadInitImage
			// 
			this->groupBoxDownloadInitImage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBoxDownloadInitImage->Controls->Add(this->buttonDownload);
			this->groupBoxDownloadInitImage->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Italic,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->groupBoxDownloadInitImage->Location = System::Drawing::Point(310, 50);
			this->groupBoxDownloadInitImage->Name = L"groupBoxDownloadInitImage";
			this->groupBoxDownloadInitImage->Size = System::Drawing::Size(302, 55);
			this->groupBoxDownloadInitImage->TabIndex = 4;
			this->groupBoxDownloadInitImage->TabStop = false;
			this->groupBoxDownloadInitImage->Text = L"DOWNLOAD INITIAL IMAGE";
			// 
			// buttonDownload
			// 
			this->buttonDownload->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonDownload->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonDownload->ForeColor = System::Drawing::Color::Blue;
			this->buttonDownload->Location = System::Drawing::Point(6, 21);
			this->buttonDownload->Name = L"buttonDownload";
			this->buttonDownload->Size = System::Drawing::Size(290, 23);
			this->buttonDownload->TabIndex = 0;
			this->buttonDownload->Text = L"Model_Samle";
			this->buttonDownload->UseVisualStyleBackColor = true;
			this->buttonDownload->Click += gcnew System::EventHandler(this, &SEMmainForm::buttonDownload_Click);
			// 
			// buttonExit
			// 
			this->buttonExit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonExit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonExit->ForeColor = System::Drawing::Color::Blue;
			this->buttonExit->Location = System::Drawing::Point(458, 407);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(154, 23);
			this->buttonExit->TabIndex = 5;
			this->buttonExit->Text = L"Exit";
			this->buttonExit->UseVisualStyleBackColor = true;
			this->buttonExit->Click += gcnew System::EventHandler(this, &SEMmainForm::buttonExit_Click);
			// 
			// pictureBoxSrcImage
			// 
			this->pictureBoxSrcImage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxSrcImage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxSrcImage.Image")));
			this->pictureBoxSrcImage->Location = System::Drawing::Point(310, 119);
			this->pictureBoxSrcImage->Name = L"pictureBoxSrcImage";
			this->pictureBoxSrcImage->Size = System::Drawing::Size(302, 282);
			this->pictureBoxSrcImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxSrcImage->TabIndex = 6;
			this->pictureBoxSrcImage->TabStop = false;
			// 
			// checkBoxZoom
			// 
			this->checkBoxZoom->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->checkBoxZoom->AutoSize = true;
			this->checkBoxZoom->Checked = true;
			this->checkBoxZoom->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxZoom->Location = System::Drawing::Point(310, 413);
			this->checkBoxZoom->Name = L"checkBoxZoom";
			this->checkBoxZoom->Size = System::Drawing::Size(84, 17);
			this->checkBoxZoom->TabIndex = 7;
			this->checkBoxZoom->Text = L"Zoom image";
			this->checkBoxZoom->UseVisualStyleBackColor = true;
			this->checkBoxZoom->CheckedChanged += gcnew System::EventHandler(this, &SEMmainForm::checkBoxZoom_CheckedChanged);
			// 
			// openFileDialogImage
			// 
			this->openFileDialogImage->FileName = L"openFileDialogImage";
			// 
			// SEMmainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(624, 441);
			this->Controls->Add(this->checkBoxZoom);
			this->Controls->Add(this->pictureBoxSrcImage);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->groupBoxDownloadInitImage);
			this->Controls->Add(this->groupBoxScanModes);
			this->Controls->Add(this->groupBoxSimParam);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"SEMmainForm";
			this->Text = L"SEM-IMAGES SIMULATION";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &SEMmainForm::SEMmainForm_FormClosing);
			this->groupBoxSimParam->ResumeLayout(false);
			this->groupBoxSimParam->PerformLayout();
			this->groupBoxScanModes->ResumeLayout(false);
			this->groupBoxDownloadInitImage->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSrcImage))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void checkBoxZoom_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (checkBoxZoom->Checked) {
					 pictureBoxSrcImage->SizeMode = PictureBoxSizeMode::Zoom; 
				 }
				 else {
					 pictureBoxSrcImage->SizeMode = PictureBoxSizeMode::CenterImage;
				 }
	}
private: System::Void buttonDownload_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (openFileDialogImage->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				 buttonDownload->Text = openFileDialogImage->SafeFileName;
				 core->loadImage(openFileDialogImage->FileName);
				 // Приведение картинок к стандартному типу
				 Bitmap^ srcBmp = gcnew Bitmap(core->m_src->width, core->m_src->height, core->m_src->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (IntPtr)core->m_src->imageData);
				 //Bitmap^ rslBmp = gcnew Bitmap(core->m_rsl->width, core->m_rsl->height, core->m_rsl->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (IntPtr)core->m_rsl->imageData);
				 // И вывод их на форму
				 pictureBoxSrcImage->Image = srcBmp;
				 //pictureBoxRsl->Image = rslBmp;
			 }
}
private: System::Void buttonExit_Click(System::Object^  sender, System::EventArgs^  e) {
			 //core->ResetInstance();
			 this->Close();
}
private: System::Void buttonConstProbe_Click(System::Object^  sender, System::EventArgs^  e) {
			 setParametrsFromMainForm(	float::Parse(textBoxD->Text), 
										float::Parse(textBoxW->Text),
										float::Parse(textBoxK->Text),
										float::Parse(textBoxGamma->Text),
										float::Parse(textBoxRo->Text),
										float::Parse(textBoxC->Text),
										1.0);
			 constForm->ShowDialog(this);
}
private: System::Void buttonPulsingProbe_Click(System::Object^  sender, System::EventArgs^  e) {
			 setParametrsFromMainForm(	float::Parse(textBoxD->Text),
										float::Parse(textBoxW->Text),
										float::Parse(textBoxK->Text),
										float::Parse(textBoxGamma->Text),
										float::Parse(textBoxRo->Text),
										float::Parse(textBoxC->Text),
										0.0);
			 pulsingForm->ShowDialog(this);
}
private: System::Void SEMmainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			 core->ResetInstance();
}
};
}
