#pragma once
#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <msclr\marshal_cppstd.h>
#include <thread>
#include "MyForm.h"

namespace Test {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>

	public ref class MyForm1 : public System::Windows::Forms::Form
	{

	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::ListBox^ queueList;
	protected:
	public: System::Windows::Forms::Button^ queueExec;
	public: System::Windows::Forms::Button^ rS;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	public:

	public:




	protected:



	protected:

	public:
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
			this->queueList = (gcnew System::Windows::Forms::ListBox());
			this->queueExec = (gcnew System::Windows::Forms::Button());
			this->rS = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// queueList
			// 
			this->queueList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->queueList->FormattingEnabled = true;
			this->queueList->ItemHeight = 25;
			this->queueList->Location = System::Drawing::Point(12, 12);
			this->queueList->Name = L"queueList";
			this->queueList->Size = System::Drawing::Size(561, 379);
			this->queueList->TabIndex = 0;
			// 
			// queueExec
			// 
			this->queueExec->BackColor = System::Drawing::Color::Silver;
			this->queueExec->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->queueExec->Location = System::Drawing::Point(579, 94);
			this->queueExec->Name = L"queueExec";
			this->queueExec->Size = System::Drawing::Size(205, 58);
			this->queueExec->TabIndex = 1;
			this->queueExec->Text = L"Execute Commands";
			this->queueExec->UseVisualStyleBackColor = false;
			this->queueExec->Click += gcnew System::EventHandler(this, &MyForm1::queueExec_Click);
			// 
			// rS
			// 
			this->rS->BackColor = System::Drawing::Color::Silver;
			this->rS->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->rS->Location = System::Drawing::Point(579, 158);
			this->rS->Name = L"rS";
			this->rS->Size = System::Drawing::Size(205, 60);
			this->rS->TabIndex = 2;
			this->rS->Text = L"Remove Selected";
			this->rS->UseVisualStyleBackColor = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->ImageLocation = L"alfa.png";
			this->pictureBox1->Location = System::Drawing::Point(579, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(205, 64);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(790, 422);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->rS);
			this->Controls->Add(this->queueExec);
			this->Controls->Add(this->queueList);
			this->Name = L"MyForm1";
			this->Text = L"Current Command Queue";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	public: System::Void queueExec_Click(System::Object^ sender, System::EventArgs^ e) {
		//MyForm^ m = gcnew MyForm();
		//string t = msclr::interop::marshal_as<std::string>(m->comv->Text);
	}
};
}