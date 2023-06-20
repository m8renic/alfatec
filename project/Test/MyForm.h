#pragma once
#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <msclr\marshal_cppstd.h>
#include <thread>

FILE* logF;
int infFlag = 0;
int expand = 0;
int cps = 0;
int cc = 1;

namespace Test {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	
	public ref class MyForm : public System::Windows::Forms::Form{

		public: MyForm(void) {
			InitializeComponent();
		}
		protected:
			~MyForm(){
				if(components){
					delete components;
				}
			}
		private: System::Windows::Forms::Label^ ip;
		public: System::Windows::Forms::TextBox^ ipv;
		private: System::Windows::Forms::Label^ label1;
		public: System::Windows::Forms::TextBox^ portv;
		public: System::Windows::Forms::PictureBox^ logo;
		private: System::Windows::Forms::Label^ com;
		public: System::Windows::Forms::TextBox^ comv;
		private: System::Windows::Forms::Label^ logl;
		public: System::Windows::Forms::TextBox^ logFileName;
		private: System::Windows::Forms::Label^ label2;
		public: System::Windows::Forms::Timer^ interval;
		public: System::Windows::Forms::TextBox^ repComNum;
		public: System::Windows::Forms::Button^ repCom;
		public: System::Windows::Forms::Button^ connect;
		private: System::Windows::Forms::Label^ label3;
		public: System::Windows::Forms::ListBox^ LogBox;
		public: System::Windows::Forms::Button^ qC;
		public: System::Windows::Forms::Button^ qCL;
		public: System::Windows::Forms::TextBox^ cps_speed;
		private: System::Windows::Forms::Label^ label4;
		public: System::Windows::Forms::Button^ exec;
		public: System::Windows::Forms::ProgressBar^ prog;
		public: System::Windows::Forms::ListBox^ queueList;
		private: System::Windows::Forms::Button^ execComs;
		private: System::Windows::Forms::Button^ remCom;
	private: System::Windows::Forms::Label^ label5;
	private: System::ComponentModel::IContainer^ components;

	#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>

		void InitializeComponent(void){
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->ip = (gcnew System::Windows::Forms::Label());
			this->ipv = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->portv = (gcnew System::Windows::Forms::TextBox());
			this->logo = (gcnew System::Windows::Forms::PictureBox());
			this->com = (gcnew System::Windows::Forms::Label());
			this->comv = (gcnew System::Windows::Forms::TextBox());
			this->logl = (gcnew System::Windows::Forms::Label());
			this->logFileName = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->interval = (gcnew System::Windows::Forms::Timer(this->components));
			this->repComNum = (gcnew System::Windows::Forms::TextBox());
			this->repCom = (gcnew System::Windows::Forms::Button());
			this->connect = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->LogBox = (gcnew System::Windows::Forms::ListBox());
			this->qC = (gcnew System::Windows::Forms::Button());
			this->qCL = (gcnew System::Windows::Forms::Button());
			this->cps_speed = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->exec = (gcnew System::Windows::Forms::Button());
			this->prog = (gcnew System::Windows::Forms::ProgressBar());
			this->queueList = (gcnew System::Windows::Forms::ListBox());
			this->execComs = (gcnew System::Windows::Forms::Button());
			this->remCom = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logo))->BeginInit();
			this->SuspendLayout();
			// 
			// ip
			// 
			this->ip->AutoSize = true;
			this->ip->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ip->ForeColor = System::Drawing::Color::White;
			this->ip->Location = System::Drawing::Point(12, 15);
			this->ip->Name = L"ip";
			this->ip->Size = System::Drawing::Size(120, 25);
			this->ip->TabIndex = 0;
			this->ip->Text = L"IP address:";
			// 
			// ipv
			// 
			this->ipv->BackColor = System::Drawing::Color::Black;
			this->ipv->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ipv->ForeColor = System::Drawing::Color::White;
			this->ipv->Location = System::Drawing::Point(138, 12);
			this->ipv->Name = L"ipv";
			this->ipv->Size = System::Drawing::Size(183, 31);
			this->ipv->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(344, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 25);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Port:";
			// 
			// portv
			// 
			this->portv->BackColor = System::Drawing::Color::Black;
			this->portv->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->portv->ForeColor = System::Drawing::Color::White;
			this->portv->Location = System::Drawing::Point(407, 12);
			this->portv->MinimumSize = System::Drawing::Size(82, 20);
			this->portv->Name = L"portv";
			this->portv->Size = System::Drawing::Size(82, 31);
			this->portv->TabIndex = 3;
			// 
			// logo
			// 
			this->logo->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logo.ErrorImage")));
			this->logo->ImageLocation = L"alfa.png";
			this->logo->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logo.InitialImage")));
			this->logo->Location = System::Drawing::Point(629, 6);
			this->logo->MaximumSize = System::Drawing::Size(205, 64);
			this->logo->Name = L"logo";
			this->logo->Size = System::Drawing::Size(205, 64);
			this->logo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->logo->TabIndex = 4;
			this->logo->TabStop = false;
			// 
			// com
			// 
			this->com->AutoSize = true;
			this->com->BackColor = System::Drawing::Color::Black;
			this->com->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->com->ForeColor = System::Drawing::Color::White;
			this->com->Location = System::Drawing::Point(12, 76);
			this->com->Name = L"com";
			this->com->Size = System::Drawing::Size(115, 25);
			this->com->TabIndex = 5;
			this->com->Text = L"Command:";
			// 
			// comv
			// 
			this->comv->BackColor = System::Drawing::Color::Black;
			this->comv->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comv->ForeColor = System::Drawing::Color::White;
			this->comv->Location = System::Drawing::Point(133, 73);
			this->comv->Name = L"comv";
			this->comv->Size = System::Drawing::Size(467, 31);
			this->comv->TabIndex = 6;
			// 
			// logl
			// 
			this->logl->AutoSize = true;
			this->logl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->logl->ForeColor = System::Drawing::Color::White;
			this->logl->Location = System::Drawing::Point(12, 221);
			this->logl->Name = L"logl";
			this->logl->Size = System::Drawing::Size(88, 25);
			this->logl->TabIndex = 7;
			this->logl->Text = L"Log file:";
			// 
			// logFileName
			// 
			this->logFileName->BackColor = System::Drawing::Color::Black;
			this->logFileName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->logFileName->ForeColor = System::Drawing::Color::White;
			this->logFileName->Location = System::Drawing::Point(106, 218);
			this->logFileName->Name = L"logFileName";
			this->logFileName->ReadOnly = true;
			this->logFileName->Size = System::Drawing::Size(494, 31);
			this->logFileName->TabIndex = 8;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(12, 122);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(190, 25);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Repeat Command:";
			// 
			// interval
			// 
			this->interval->Interval = 10;
			this->interval->Tick += gcnew System::EventHandler(this, &MyForm::interval_Tick);
			// 
			// repComNum
			// 
			this->repComNum->BackColor = System::Drawing::Color::Black;
			this->repComNum->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->repComNum->ForeColor = System::Drawing::Color::White;
			this->repComNum->Location = System::Drawing::Point(208, 122);
			this->repComNum->Name = L"repComNum";
			this->repComNum->Size = System::Drawing::Size(87, 31);
			this->repComNum->TabIndex = 10;
			this->repComNum->Text = L"1";
			// 
			// repCom
			// 
			this->repCom->BackColor = System::Drawing::Color::Silver;
			this->repCom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->repCom->ForeColor = System::Drawing::Color::Black;
			this->repCom->Location = System::Drawing::Point(301, 122);
			this->repCom->Name = L"repCom";
			this->repCom->Size = System::Drawing::Size(146, 31);
			this->repCom->TabIndex = 11;
			this->repCom->Text = L"Until stopped";
			this->repCom->UseVisualStyleBackColor = false;
			this->repCom->Click += gcnew System::EventHandler(this, &MyForm::repCom_Click);
			// 
			// connect
			// 
			this->connect->BackColor = System::Drawing::Color::Silver;
			this->connect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->connect->ForeColor = System::Drawing::SystemColors::ControlText;
			this->connect->Location = System::Drawing::Point(495, 12);
			this->connect->Name = L"connect";
			this->connect->Size = System::Drawing::Size(105, 33);
			this->connect->TabIndex = 12;
			this->connect->Text = L"Connect";
			this->connect->UseVisualStyleBackColor = false;
			this->connect->Click += gcnew System::EventHandler(this, &MyForm::connect_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(12, 265);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 25);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Log:";
			// 
			// LogBox
			// 
			this->LogBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LogBox->FormattingEnabled = true;
			this->LogBox->ItemHeight = 25;
			this->LogBox->Location = System::Drawing::Point(12, 293);
			this->LogBox->Name = L"LogBox";
			this->LogBox->Size = System::Drawing::Size(822, 304);
			this->LogBox->TabIndex = 14;
			// 
			// qC
			// 
			this->qC->BackColor = System::Drawing::Color::Silver;
			this->qC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->qC->Location = System::Drawing::Point(681, 110);
			this->qC->Name = L"qC";
			this->qC->Size = System::Drawing::Size(153, 31);
			this->qC->TabIndex = 15;
			this->qC->Text = L"Add to list >>";
			this->qC->UseVisualStyleBackColor = false;
			this->qC->Click += gcnew System::EventHandler(this, &MyForm::qC_Click);
			// 
			// qCL
			// 
			this->qCL->BackColor = System::Drawing::Color::Silver;
			this->qCL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->qCL->Location = System::Drawing::Point(681, 147);
			this->qCL->Name = L"qCL";
			this->qCL->Size = System::Drawing::Size(153, 31);
			this->qCL->TabIndex = 16;
			this->qCL->Text = L"Show/Hide";
			this->qCL->UseVisualStyleBackColor = false;
			this->qCL->Click += gcnew System::EventHandler(this, &MyForm::qCL_Click);
			// 
			// cps_speed
			// 
			this->cps_speed->BackColor = System::Drawing::Color::Black;
			this->cps_speed->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->cps_speed->ForeColor = System::Drawing::Color::White;
			this->cps_speed->Location = System::Drawing::Point(546, 122);
			this->cps_speed->Name = L"cps_speed";
			this->cps_speed->Size = System::Drawing::Size(54, 31);
			this->cps_speed->TabIndex = 18;
			this->cps_speed->Text = L"10";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(479, 125);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(61, 25);
			this->label4->TabIndex = 19;
			this->label4->Text = L"CPS:";
			// 
			// exec
			// 
			this->exec->BackColor = System::Drawing::Color::Silver;
			this->exec->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->exec->Location = System::Drawing::Point(681, 76);
			this->exec->Name = L"exec";
			this->exec->Size = System::Drawing::Size(153, 28);
			this->exec->TabIndex = 20;
			this->exec->Text = L"Execute";
			this->exec->UseVisualStyleBackColor = false;
			this->exec->Click += gcnew System::EventHandler(this, &MyForm::ex_Click);
			// 
			// prog
			// 
			this->prog->Location = System::Drawing::Point(17, 166);
			this->prog->Name = L"prog";
			this->prog->Size = System::Drawing::Size(583, 23);
			this->prog->Step = 1;
			this->prog->TabIndex = 21;
			// 
			// queueList
			// 
			this->queueList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->queueList->FormattingEnabled = true;
			this->queueList->ItemHeight = 25;
			this->queueList->Location = System::Drawing::Point(870, 56);
			this->queueList->Name = L"queueList";
			this->queueList->Size = System::Drawing::Size(561, 479);
			this->queueList->TabIndex = 22;
			// 
			// execComs
			// 
			this->execComs->BackColor = System::Drawing::Color::Silver;
			this->execComs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->execComs->Location = System::Drawing::Point(870, 555);
			this->execComs->Name = L"execComs";
			this->execComs->Size = System::Drawing::Size(221, 42);
			this->execComs->TabIndex = 23;
			this->execComs->Text = L"Execute commands";
			this->execComs->UseVisualStyleBackColor = false;
			this->execComs->Click += gcnew System::EventHandler(this, &MyForm::execComs_Click);
			// 
			// remCom
			// 
			this->remCom->BackColor = System::Drawing::Color::Silver;
			this->remCom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->remCom->Location = System::Drawing::Point(1135, 555);
			this->remCom->Name = L"remCom";
			this->remCom->Size = System::Drawing::Size(296, 42);
			this->remCom->TabIndex = 24;
			this->remCom->Text = L"Remove selected command";
			this->remCom->UseVisualStyleBackColor = false;
			this->remCom->Click += gcnew System::EventHandler(this, &MyForm::remCom_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(865, 15);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(181, 25);
			this->label5->TabIndex = 25;
			this->label5->Text = L"Command queue:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(845, 610);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->remCom);
			this->Controls->Add(this->execComs);
			this->Controls->Add(this->queueList);
			this->Controls->Add(this->prog);
			this->Controls->Add(this->exec);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->cps_speed);
			this->Controls->Add(this->qCL);
			this->Controls->Add(this->qC);
			this->Controls->Add(this->LogBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->connect);
			this->Controls->Add(this->repCom);
			this->Controls->Add(this->repComNum);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->logFileName);
			this->Controls->Add(this->logl);
			this->Controls->Add(this->comv);
			this->Controls->Add(this->com);
			this->Controls->Add(this->logo);
			this->Controls->Add(this->portv);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ipv);
			this->Controls->Add(this->ip);
			this->MaximumSize = System::Drawing::Size(861, 649);
			this->Name = L"MyForm";
			this->Text = L"Alfatec";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
		public: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
			time_t now = time(0);
			char* buffer = ctime(&now);
			string t = string(buffer);
			string day, month, year;
			string h, m, s;

			if(t.substr(8, 1) == "1" || t.substr(8, 1) == "2" || t.substr(8, 1) == "3"){
				day = t.substr(8, 2);
			}else{
				day = "0" + t.substr(9, 1);
			}
			month = t.substr(4, 3);
			if(month == "Jan"){
				month = "01";
			}else if(month == "Feb"){
				month = "02";
			}else if(month == "Mar"){
				month = "03";
			}else if(month == "Apr"){
				month = "04";
			}else if(month == "May"){
				month = "05";
			}else if(month == "Jun"){
				month = "06";
			}else if(month == "Jul"){
				month = "07";
			}else if(month == "Aug"){
				month = "08";
			}else if(month == "Sep"){
				month = "09";
			}else if (month == "Oct"){
				month = "10";
			}else if(month == "Nov"){
				month = "11";
			}else{
				month = "12";
			}

			year = t.substr(20, 4);

			h = t.substr(11, 2);
			m = t.substr(14, 2);
			s = t.substr(17, 2);
			//cout << "\n" + day + " " + month + " " + year + "\n" + h + ":" + m + ":" + s;

			string timestamp = "log" + year + "-" + month + "-" + day + "T" + h + "-" + m + "-" + s;
			String^ ct = msclr::interop::marshal_as<System::String^>(timestamp);
			logFileName->Text = ct + ".txt";

			char newLog[30];
			sprintf(newLog, "logs\\%s.txt", timestamp.c_str());

			logF = fopen(newLog, "a");
		}
		public: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			fclose(logF);
		}
		public: System::Void connect_Click(System::Object^ sender, System::EventArgs^ e) {
			string ip = msclr::interop::marshal_as<std::string>(ipv->Text);
			string port = msclr::interop::marshal_as<std::string>(portv->Text);

			//TCP connect code

		}
		public: System::Void ex_Click(System::Object^ sender, System::EventArgs^ e) {
			//Thread this

			//std::thread thr(sending);
			//thr.join();

			if (msclr::interop::marshal_as<std::string>(comv->Text).empty()) {
				cout << "\nEmpty";
			}
			else {
				int c = stoi(msclr::interop::marshal_as<string>(repComNum->Text));
				int n = stoi(msclr::interop::marshal_as<string>(repComNum->Text));
				int j = 1;
				for (int i = 0; i < n; i++) {
					time_t now = time(0);
					char* buffer = ctime(&now);
					string time = string(buffer);
					string h, m, s;

					h = time.substr(11, 2);
					m = time.substr(14, 2);
					s = time.substr(17, 2);

					if (i + 1 == 60 * j) {
						Sleep(1000);
						j++;
					}

					string format = "-> " + h + ":" + m + ":" + s + "\t" + msclr::interop::marshal_as<std::string>(comv->Text) + "\n";
					fprintf(logF, format.c_str());
					LogBox->Items->Add(msclr::interop::marshal_as<System::String^>(format));
					//TCP send code, w/e

					prog->Value = 100 / c;
					c--;
				}
				comv->Text = "";
			}
		}
		public: System::Void repCom_Click(System::Object^ sender, System::EventArgs^ e) {
			if (msclr::interop::marshal_as<std::string>(comv->Text).empty()) {
				cout << "\nEmpty";
			}else{
				/*int cps = stoi(msclr::interop::marshal_as<std::string>(cps_speed->Text));
				if (infFlag == 0) {
					infFlag++;
					interval->Enabled = true;
					interval->Interval = ceil(1000 / cps);
					inetrval->Tick += gcnew System::EventHandler(this, &MyForm::interval_Tick);
					fprintf(logF, to_string((1000 / cps)).c_str());
					fprintf(logF, "\n");
				}
				else{
					infFlag--;
					interval->Enabled = false;
					interval->Tick -= gcnew System::EventHandler(this, &MyForm::interval_Tick);
				}*/

				//-------------------------------------------------------------------------------

				cps = stoi(msclr::interop::marshal_as<std::string>(cps_speed->Text));
				if (infFlag == 0) {
					infFlag++;
					interval->Enabled = true;
					interval->Interval = 10;
					interval->Tick += gcnew System::EventHandler(this, &MyForm::interval_Tick);
				}else{
					infFlag--;
					interval->Enabled = false;
					interval->Tick -= gcnew System::EventHandler(this, &MyForm::interval_Tick);
				}
			}
		}
		public: System::Void interval_Tick(System::Object^ sender, System::EventArgs^ e) {
			if(msclr::interop::marshal_as<std::string>(comv->Text).empty()){
				cout << "\nEmpty";
			}else{
				if(cc <= cps){
					time_t now = time(0);
					char* buffer = ctime(&now);
					string time = string(buffer);
					string h, m, s;

					h = time.substr(11, 2);
					m = time.substr(14, 2);
					s = time.substr(17, 2);

					string format = "-> " + h + ":" + m + ":" + s + "\t" + msclr::interop::marshal_as<std::string>(comv->Text) + "\n";
					fprintf(logF, format.c_str());
					LogBox->Items->Add(msclr::interop::marshal_as<System::String^>(format));
					cc++;
				}else if(cc > cps){
					Sleep(1000);
					cc = 1;
				}
			}
		}
		public: System::Void qCL_Click(System::Object^ sender, System::EventArgs^ e){
			if (expand == 0){
				this->MaximumSize = System::Drawing::Size(1452, 649);
				this->ClientSize = System::Drawing::Size(1436, 610);
				expand++;
			}
			else {
				this->MaximumSize = System::Drawing::Size(861, 649);
				this->ClientSize = System::Drawing::Size(845, 610);
				expand--;
			}
		}
		public: System::Void qC_Click(System::Object^ sender, System::EventArgs^ e) {
			if (msclr::interop::marshal_as<std::string>(comv->Text) != ""){
				queueList->Items->Add(comv->Text + "\n");
				cout << msclr::interop::marshal_as<std::string>(comv->Text);
				comv->Text = "";
			}
		}
		private: System::Void execComs_Click(System::Object^ sender, System::EventArgs^ e) {
			int c = queueList->Items->Count;
			int n = queueList->Items->Count;
			for(int i = 0; i < n; i++){
				//
				time_t now = time(0);
				char* buffer = ctime(&now);
				string time = string(buffer);
				string h, m, s;

				h = time.substr(11, 2);
				m = time.substr(14, 2);
				s = time.substr(17, 2);

				string format = "-> " + h + ":" + m + ":" + s + "    " + msclr::interop::marshal_as<std::string>(queueList->Items[i]->ToString()) + "\n";
				fprintf(logF, format.c_str());
				LogBox->Items->Add(msclr::interop::marshal_as<System::String^>(format));

				prog->Value = 100 / c;
				c--;
				//Sending Code / function
			}
			queueList->Items->Clear();
		}
		public: System::Void remCom_Click(System::Object^ sender, System::EventArgs^ e) {
			int rIndex = queueList->SelectedIndex;
			queueList->Items->RemoveAt(rIndex);
		}
	};
	/*void sending(){
		Test::MyForm obj;
		if (msclr::interop::marshal_as<std::string>(obj.comv->Text).empty()) {
			std::cout << "\nEmpty";
		}else{
			int c = std::stoi(msclr::interop::marshal_as<std::string>(obj.repComNum->Text));
			int n = std::stoi(msclr::interop::marshal_as<std::string>(obj.repComNum->Text));
			int j = 1;
			for (int i = 0; i < n; i++) {
				time_t now = time(0);
				char* buffer = ctime(&now);
				std::string time = std::string(buffer);
				std::string h, m, s;

				h = time.substr(11, 2);
				m = time.substr(14, 2);
				s = time.substr(17, 2);

				if (i + 1 == 60 * j) {
					Sleep(1000);
					j++;
				}

				std::string format = "-> " + h + ":" + m + ":" + s + "\t" + msclr::interop::marshal_as<std::string>(obj.comv->Text) + "\n";
				fprintf(logF, format.c_str());
				obj.LogBox->Items->Add(msclr::interop::marshal_as<System::String^>(format));
				//TCP send code, w/e

				obj.prog->Value = 100 / c;
				c--;
			}
			obj.comv->Text = "";
		}
	}*/
}