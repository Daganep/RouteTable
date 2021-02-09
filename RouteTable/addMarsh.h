#pragma once
#include "BusList.h"
#include <string>

namespace RouteTable {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text;

	/// <summary>
	/// Сводка для addMarsh
	/// </summary>
	public ref class addMarsh : public System::Windows::Forms::Form
	{
	public:
		addMarsh(BusList* list)
		{
			InitializeComponent();
			newNode = list;
			//
			//TODO: добавьте код конструктора
			//
		}

		std::string SystemToStl(String^ s)
		{
			using namespace Runtime::InteropServices;
			const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			return std::string(ptr);
		}



	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~addMarsh()
		{
			if (components)
			{
				delete components;
			}
		}
	public: BusList* newNode;
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label4;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(94, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Номер маршрута";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 52);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(95, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Начальный пункт";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 82);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(88, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Конечный пункт";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(122, 17);
			this->textBox1->MaxLength = 3;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(168, 20);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(122, 49);
			this->textBox2->MaxLength = 20;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(168, 20);
			this->textBox2->TabIndex = 4;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(122, 79);
			this->textBox3->MaxLength = 20;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(168, 20);
			this->textBox3->TabIndex = 5;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(122, 110);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &addMarsh::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(215, 110);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Отмена";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &addMarsh::button2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::Red;
			this->label4->Location = System::Drawing::Point(12, 134);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 16);
			this->label4->TabIndex = 8;
			this->label4->Visible = false;
			// 
			// addMarsh
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(302, 159);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"addMarsh";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Добавить маршрут";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion




		//отмена добавления
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

		   //добавить маршрут
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int number = 0;
		bool isGood = true;
		std::string field2 = SystemToStl(textBox2->Text);
		std::string field3 = SystemToStl(textBox3->Text);
		for (int i(0); i < field2.length(); i++) {
			if (field2[i].Equals(';')) {
				isGood = false;
				break;
			}
		}
		for (int i(0); i < field3.length(); i++) {
			if (field3[i].Equals(';')) {
				isGood = false;
				break;
			}
		}
		//проверка на ввод цифр
		if (!System::Int32::TryParse((textBox1->Text), number) || number < 1 || number > 999) {
			textBox1->Clear();
			label4->Text = "Некорректный номер маршрута";
			label4->Visible = true;
		}
		//проверка на незаполненные поля
		else if (textBox1->Text == "" || textBox2->Text == "" || textBox3->Text == "") {
			label4->Text = "Заполните все поля";
			label4->Visible = true;
		}
		//проверка на наличие маршрута
		else if (newNode->searchNode(number)) {
			label4->Text = "Такой маршрут уже есть!";
			label4->Visible = true;
		}
		else if (!isGood) {
			label4->Text = "Недопустимый символ ';'!";
			label4->Visible = true;
		}
		//если проверки пройдены, добавить маршрут
		else {
			newNode->addNode(number, SystemToStl(textBox2->Text), SystemToStl(textBox3->Text));
			label4->Visible = false;
			this->Close();
		}
	}
	};
}
