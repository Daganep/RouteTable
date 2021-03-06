#pragma once
#include "addMarsh.h"
#include "changeMarsh.h"
#include "BusList.h"

namespace RouteTable {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� mainForm
	/// </summary>
	public ref class mainForm : public System::Windows::Forms::Form
	{
	public:
		mainForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~mainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ b_m_remSelect;
	protected: BusList* myList = new BusList();

	protected:



	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;

	/*private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::Button^ button5;*/



	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::Button^ b_m_change;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::PictureBox^ p_m_find;

		  //�������� ������ � �������
		  void showBusList() {
			  dataGridView1->Rows->Clear();
			  BusList::List* tempNode = myList->getBegin();
			  while (tempNode) {
				  std::string w = std::to_string(tempNode->data.number);
				  String^ r1 = gcnew System::String(w.c_str());
				  String^ r2 = gcnew System::String(tempNode->data.start.c_str());
				  String^ r3 = gcnew System::String(tempNode->data.final.c_str());
				  dataGridView1->Rows->Add(r1, r2, r3);
				  tempNode = tempNode->next;
			  }
		  }

		  //���������� � ������� �������� ��������
		  void showLastNode() {
			  BusList::List* tempNode = myList->getBegin();
			  while (tempNode->next) {
				  tempNode = tempNode->next;
			  }
			  std::string w = std::to_string(tempNode->data.number);
			  String^ r1 = gcnew System::String(w.c_str());
			  String^ r2 = gcnew System::String(tempNode->data.start.c_str());
			  String^ r3 = gcnew System::String(tempNode->data.final.c_str());
			  dataGridView1->Rows->Add(r1, r2, r3);
		  }

		  //���������� String^ � std::string
		  std::string SystemToStl(String^ s)
		  {
			  using namespace Runtime::InteropServices;
			  const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			  return std::string(ptr);
		  }

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ b_m_remove;
	private: System::Windows::Forms::Button^ b_m_add;
	private: System::Windows::Forms::Button^ b_m_find;
	private: System::Windows::Forms::TextBox^ t_m_find;





	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(mainForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->b_m_remove = (gcnew System::Windows::Forms::Button());
			this->b_m_add = (gcnew System::Windows::Forms::Button());
			this->b_m_find = (gcnew System::Windows::Forms::Button());
			this->t_m_find = (gcnew System::Windows::Forms::TextBox());
			this->b_m_remSelect = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->b_m_change = (gcnew System::Windows::Forms::Button());
			this->p_m_find = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p_m_find))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->����ToolStripMenuItem,
					this->�������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(733, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->���������ToolStripMenuItem,
					this->���������ToolStripMenuItem, this->�����ToolStripMenuItem
			});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->���������ToolStripMenuItem->Text = L"���������";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainForm::���������ToolStripMenuItem_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->���������ToolStripMenuItem->Text = L"���������";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainForm::���������ToolStripMenuItem_Click);
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->�����ToolStripMenuItem->Text = L"�����";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainForm::�����ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainForm::�������ToolStripMenuItem_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridView1->Location = System::Drawing::Point(13, 28);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;

			/*dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;*/
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect; //��� �� ����?!
			/*this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;*/

			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(708, 444);
			this->dataGridView1->TabIndex = 1;
			// 
			// Column1
			// 
			this->Column1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column1->HeaderText = L"�������";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column2->HeaderText = L"��������� �����";
			this->Column2->MaxInputLength = 10;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column3->HeaderText = L"�������� �����";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// b_m_remove
			// 
			this->b_m_remove->Location = System::Drawing::Point(621, 478);
			this->b_m_remove->Name = L"b_m_remove";
			this->b_m_remove->Size = System::Drawing::Size(100, 23);
			this->b_m_remove->TabIndex = 2;
			this->b_m_remove->Text = L"�������";
			this->b_m_remove->UseVisualStyleBackColor = true;
			this->b_m_remove->Click += gcnew System::EventHandler(this, &mainForm::button1_Click);
			// 
			// b_m_add
			// 
			this->b_m_add->Location = System::Drawing::Point(409, 478);
			this->b_m_add->Name = L"b_m_add";
			this->b_m_add->Size = System::Drawing::Size(100, 23);
			this->b_m_add->TabIndex = 3;
			this->b_m_add->Text = L"��������";
			this->b_m_add->UseVisualStyleBackColor = true;
			this->b_m_add->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			// 
			// b_m_find
			// 
			this->b_m_find->Location = System::Drawing::Point(191, 478);
			this->b_m_find->Name = L"b_m_find";
			this->b_m_find->Size = System::Drawing::Size(100, 23);
			this->b_m_find->TabIndex = 4;
			this->b_m_find->Text = L"�����";
			this->b_m_find->UseVisualStyleBackColor = true;
			this->b_m_find->Click += gcnew System::EventHandler(this, &mainForm::button3_Click);
			// 
			// t_m_find
			// 
			this->t_m_find->Location = System::Drawing::Point(42, 480);
			this->t_m_find->MaxLength = 20;
			this->t_m_find->Name = L"t_m_find";
			this->t_m_find->Size = System::Drawing::Size(143, 20);
			this->t_m_find->TabIndex = 6;
			// 
			// b_m_remSelect
			// 
			this->b_m_remSelect->Location = System::Drawing::Point(297, 478);
			this->b_m_remSelect->Name = L"b_m_remSelect";
			this->b_m_remSelect->Size = System::Drawing::Size(106, 23);
			this->b_m_remSelect->TabIndex = 7;
			this->b_m_remSelect->Text = L"����� ���������";
			this->b_m_remSelect->UseVisualStyleBackColor = true;
			this->b_m_remSelect->Click += gcnew System::EventHandler(this, &mainForm::button4_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"����� ������|*.csv";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->Filter = L"������� CSV|*.csv";
			// 
			// b_m_change
			// 
			this->b_m_change->Location = System::Drawing::Point(515, 478);
			this->b_m_change->Name = L"b_m_change";
			this->b_m_change->Size = System::Drawing::Size(100, 23);
			this->b_m_change->TabIndex = 8;
			this->b_m_change->Text = L"�������������";
			this->b_m_change->UseVisualStyleBackColor = true;
			this->b_m_change->Click += gcnew System::EventHandler(this, &mainForm::button5_Click);
			// 
			// p_m_find
			// 
			this->p_m_find->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"p_m_find.Image")));
			this->p_m_find->Location = System::Drawing::Point(13, 480);
			this->p_m_find->Name = L"p_m_find";
			this->p_m_find->Size = System::Drawing::Size(23, 23);
			this->p_m_find->TabIndex = 9;
			this->p_m_find->TabStop = false;
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(733, 510);
			this->Controls->Add(this->p_m_find);
			this->Controls->Add(this->b_m_change);
			this->Controls->Add(this->b_m_remSelect);
			this->Controls->Add(this->t_m_find);
			this->Controls->Add(this->b_m_find);
			this->Controls->Add(this->b_m_add);
			this->Controls->Add(this->b_m_remove);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"mainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"������ ��������� ���������";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p_m_find))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//������� ����� "�������� �������"
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		int currentLastNumber = myList->getLastNumber();
		addMarsh^ aM = gcnew addMarsh(myList);		//������� ����� "��������"
		aM->ShowDialog();							//��� - ������
		if (currentLastNumber != myList->getLastNumber())showLastNode();
	}

		   //����� �� ���������
	private: System::Void �����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

		   //�������� �� ������
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (myList->getBegin()) {
			myList->deleteNode(Convert::ToInt32(gcnew System::String(dataGridView1->CurrentRow->Cells[0]->Value->ToString())));
			dataGridView1->Rows->RemoveAt(dataGridView1->CurrentRow->Index);
		}
		else {
			MessageBox::Show("��� ��������� ��� ��������!");
		}
		//showBusList();
	}

	//����� ��������
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (myList->getBegin()) {
			for (int i(0); i < dataGridView1->RowCount; i++) {
				dataGridView1->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::White;
			}
		}
		if (myList->getBegin()) {
			bool inTable = false;
			for (int i(0); i < dataGridView1->RowCount; i++) {
				if (dataGridView1[0, i]->Value->ToString()->ToLower() == t_m_find->Text->ToLower() 
					|| dataGridView1[1, i]->Value->ToString()->ToLower() == t_m_find->Text->ToLower()
					|| dataGridView1[2, i]->Value->ToString()->ToLower() == t_m_find->Text->ToLower()) {
					dataGridView1->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::Yellow;
					inTable = true;
				}
			}
			t_m_find->Text = "";
			if (!inTable) {
				MessageBox::Show("������� � ����� ������� �����������!");
			}
		}
		else {
			MessageBox::Show("� ������� ��� ���������!");
			t_m_find->Text = "";
		}
	}

	//����� ��������� ����� ������
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (myList->getBegin()) {
			for (int i(0); i < dataGridView1->RowCount; i++) {
				dataGridView1->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::White;
				t_m_find->Text = "";
			}
		}
	}

	//�������� �� �����
	private: System::Void ���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		std::ifstream fin;
		openFileDialog1->ShowDialog();
		std::string path = SystemToStl(openFileDialog1->FileName);
		fin.open(path);
		if (fin.is_open()) {
			myList->loadFromFile(fin);
			showBusList();
			fin.close();
		}
		else {
			MessageBox::Show("�� ������� ������� ����!");
		}
	}

	//���������� � ����
	private: System::Void ���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		std::ofstream fout;
		saveFileDialog1->ShowDialog();
		std::string path = SystemToStl(saveFileDialog1->FileName);
		fout.open(path);
		if (fout.is_open()) {
			myList->saveToFile(fout);
			fout.close();
		}
		else {
			MessageBox::Show("�� ������� ��������� � ����!");
		}
	}

	//�������
	private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("� ������� �� ����� ���� ��������� � ���������� �������!."
			+ "\n\n�������� ������� �� ����� ��������� 20 ��������."
			+ "\n\n��������! ����� ������� ��������� �� ���������� ��������� �������!");
	}

	//��������������
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		if (myList->getBegin()) {
			changeMarsh^ cM = gcnew changeMarsh(myList, dataGridView1->CurrentRow->Cells[0]->Value->ToString());		//������� ����� "�������������"
			cM->ShowDialog();																							//��� - ������
			showBusList();
		}
		else {
			MessageBox::Show("��� ��������� ��� ��������������!");
		}
	}
	};
}
