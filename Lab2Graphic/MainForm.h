#pragma once
#include "../Lab2_Diagonal/Matrix.h"

namespace Lab2Graphic {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	// global vars
	int code_operation = -1;
	
	const int TYPE_INT		= 0;
	const int TYPE_DOUBLE	= 1;
	const int TYPE_FLOAT	= 2;
	const int TYPE_COMPLEX	= 3;
	const int TYPE_STRING	= 4;

	const int OPERATION_PLUS		= 0;
	const int OPERATION_MINUS		= 1;
	const int OPERATION_MULTIPLY	= 2;


	// default matrix A
	int A_size = 0;
	int A_code_type;
	int A_pointer_item = 0;
	MAIN::Matrix<int> A_Matrix_int;
	MAIN::Matrix<double> A_Matrix_double;
	MAIN::Matrix<float> A_Matrix_float;

	// default matrix B
	int B_size = 0;
	int B_code_type;
	int B_pointer_item = 0;
	MAIN::Matrix<int> B_Matrix_int;
	MAIN::Matrix<double> B_Matrix_double;
	MAIN::Matrix<float> B_Matrix_float;
	//MAIN::Matrix<String> Matrix_string;
	/// <summary>
	/// —водка дл€ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		
		MainForm(void)
		{
			InitializeComponent();
			
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ A_input_size;
	private: System::Windows::Forms::TextBox^ A_input_item;
	protected:


	private: System::Windows::Forms::ComboBox^ A_select_type;
	private: System::Windows::Forms::Button^ A_button_create;
	private: System::Windows::Forms::Button^ A_button_append;
	protected:

	protected:




	private: System::Windows::Forms::Label^ A_label_notification;
	private: System::Windows::Forms::Label^ A_label_matrix;





	private: System::Windows::Forms::Label^ label_info;



	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ B_input_size;
	private: System::Windows::Forms::ComboBox^ B_select_type;
	private: System::Windows::Forms::Button^ B_button_create;
	private: System::Windows::Forms::Label^ B_label_notification;




	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ B_input_item;
	private: System::Windows::Forms::Button^ B_button_append;
	private: System::Windows::Forms::Label^ B_label_matrix;



	private: System::Windows::Forms::ComboBox^ select_operation;
	private: System::Windows::Forms::Button^ button_calc;


	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label_operation;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->A_input_size = (gcnew System::Windows::Forms::TextBox());
			this->A_input_item = (gcnew System::Windows::Forms::TextBox());
			this->A_select_type = (gcnew System::Windows::Forms::ComboBox());
			this->A_button_create = (gcnew System::Windows::Forms::Button());
			this->A_button_append = (gcnew System::Windows::Forms::Button());
			this->A_label_notification = (gcnew System::Windows::Forms::Label());
			this->A_label_matrix = (gcnew System::Windows::Forms::Label());
			this->label_info = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->B_input_size = (gcnew System::Windows::Forms::TextBox());
			this->B_select_type = (gcnew System::Windows::Forms::ComboBox());
			this->B_button_create = (gcnew System::Windows::Forms::Button());
			this->B_label_notification = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->B_input_item = (gcnew System::Windows::Forms::TextBox());
			this->B_button_append = (gcnew System::Windows::Forms::Button());
			this->B_label_matrix = (gcnew System::Windows::Forms::Label());
			this->select_operation = (gcnew System::Windows::Forms::ComboBox());
			this->button_calc = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label_operation = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// A_input_size
			// 
			this->A_input_size->Location = System::Drawing::Point(94, 76);
			this->A_input_size->Name = L"A_input_size";
			this->A_input_size->Size = System::Drawing::Size(63, 20);
			this->A_input_size->TabIndex = 0;
			this->A_input_size->Text = L"Size";
			// 
			// A_input_item
			// 
			this->A_input_item->Location = System::Drawing::Point(650, 77);
			this->A_input_item->Name = L"A_input_item";
			this->A_input_item->Size = System::Drawing::Size(110, 20);
			this->A_input_item->TabIndex = 1;
			this->A_input_item->Text = L"Item";
			this->A_input_item->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox2_TextChanged);
			// 
			// A_select_type
			// 
			this->A_select_type->FormattingEnabled = true;
			this->A_select_type->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"int", L"double", L"float", L"complex", L"string" });
			this->A_select_type->Location = System::Drawing::Point(186, 75);
			this->A_select_type->Name = L"A_select_type";
			this->A_select_type->Size = System::Drawing::Size(107, 21);
			this->A_select_type->TabIndex = 2;
			this->A_select_type->Text = L"type";
			// 
			// A_button_create
			// 
			this->A_button_create->Location = System::Drawing::Point(325, 76);
			this->A_button_create->Name = L"A_button_create";
			this->A_button_create->Size = System::Drawing::Size(112, 20);
			this->A_button_create->TabIndex = 3;
			this->A_button_create->Text = L"Create";
			this->A_button_create->UseVisualStyleBackColor = true;
			this->A_button_create->Click += gcnew System::EventHandler(this, &MainForm::button_create_Click);
			// 
			// A_button_append
			// 
			this->A_button_append->Location = System::Drawing::Point(810, 77);
			this->A_button_append->Name = L"A_button_append";
			this->A_button_append->Size = System::Drawing::Size(121, 20);
			this->A_button_append->TabIndex = 4;
			this->A_button_append->Text = L"Append";
			this->A_button_append->UseVisualStyleBackColor = true;
			this->A_button_append->Click += gcnew System::EventHandler(this, &MainForm::A_button_append_Click);
			// 
			// A_label_notification
			// 
			this->A_label_notification->AutoSize = true;
			this->A_label_notification->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->A_label_notification->Location = System::Drawing::Point(483, 78);
			this->A_label_notification->Name = L"A_label_notification";
			this->A_label_notification->Size = System::Drawing::Size(62, 13);
			this->A_label_notification->TabIndex = 5;
			this->A_label_notification->Text = L"In proccess";
			// 
			// A_label_matrix
			// 
			this->A_label_matrix->AutoSize = true;
			this->A_label_matrix->Location = System::Drawing::Point(68, 285);
			this->A_label_matrix->Name = L"A_label_matrix";
			this->A_label_matrix->Size = System::Drawing::Size(44, 13);
			this->A_label_matrix->TabIndex = 6;
			this->A_label_matrix->Text = L"Matrix...";
			// 
			// label_info
			// 
			this->label_info->AutoSize = true;
			this->label_info->Location = System::Drawing::Point(854, 310);
			this->label_info->Name = L"label_info";
			this->label_info->Size = System::Drawing::Size(27, 13);
			this->label_info->TabIndex = 7;
			this->label_info->Text = L"info:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(44, 20);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(124, 27);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Matrix App";
			// 
			// B_input_size
			// 
			this->B_input_size->Location = System::Drawing::Point(94, 136);
			this->B_input_size->Name = L"B_input_size";
			this->B_input_size->Size = System::Drawing::Size(63, 20);
			this->B_input_size->TabIndex = 9;
			this->B_input_size->Text = L"Size";
			// 
			// B_select_type
			// 
			this->B_select_type->FormattingEnabled = true;
			this->B_select_type->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"int", L"double", L"float", L"complex", L"string" });
			this->B_select_type->Location = System::Drawing::Point(186, 136);
			this->B_select_type->Name = L"B_select_type";
			this->B_select_type->Size = System::Drawing::Size(107, 21);
			this->B_select_type->TabIndex = 10;
			this->B_select_type->Text = L"type";
			// 
			// B_button_create
			// 
			this->B_button_create->Location = System::Drawing::Point(325, 136);
			this->B_button_create->Name = L"B_button_create";
			this->B_button_create->Size = System::Drawing::Size(112, 20);
			this->B_button_create->TabIndex = 11;
			this->B_button_create->Text = L"Create";
			this->B_button_create->UseVisualStyleBackColor = true;
			this->B_button_create->Click += gcnew System::EventHandler(this, &MainForm::B_button_create_Click);
			// 
			// B_label_notification
			// 
			this->B_label_notification->AutoSize = true;
			this->B_label_notification->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->B_label_notification->Location = System::Drawing::Point(483, 139);
			this->B_label_notification->Name = L"B_label_notification";
			this->B_label_notification->Size = System::Drawing::Size(62, 13);
			this->B_label_notification->TabIndex = 12;
			this->B_label_notification->Text = L"In proccess";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(44, 78);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(17, 13);
			this->label2->TabIndex = 13;
			this->label2->Text = L"A:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(44, 140);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(17, 13);
			this->label3->TabIndex = 14;
			this->label3->Text = L"B:";
			// 
			// B_input_item
			// 
			this->B_input_item->Location = System::Drawing::Point(650, 137);
			this->B_input_item->Name = L"B_input_item";
			this->B_input_item->Size = System::Drawing::Size(110, 20);
			this->B_input_item->TabIndex = 15;
			this->B_input_item->Text = L"Item";
			// 
			// B_button_append
			// 
			this->B_button_append->Location = System::Drawing::Point(810, 137);
			this->B_button_append->Name = L"B_button_append";
			this->B_button_append->Size = System::Drawing::Size(121, 20);
			this->B_button_append->TabIndex = 16;
			this->B_button_append->Text = L"Append";
			this->B_button_append->UseVisualStyleBackColor = true;
			this->B_button_append->Click += gcnew System::EventHandler(this, &MainForm::B_button_append_Click);
			// 
			// B_label_matrix
			// 
			this->B_label_matrix->AutoSize = true;
			this->B_label_matrix->Location = System::Drawing::Point(277, 285);
			this->B_label_matrix->Name = L"B_label_matrix";
			this->B_label_matrix->Size = System::Drawing::Size(44, 13);
			this->B_label_matrix->TabIndex = 17;
			this->B_label_matrix->Text = L"Matrix...";
			// 
			// select_operation
			// 
			this->select_operation->FormattingEnabled = true;
			this->select_operation->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"+", L"-", L"*" });
			this->select_operation->Location = System::Drawing::Point(47, 210);
			this->select_operation->Name = L"select_operation";
			this->select_operation->Size = System::Drawing::Size(107, 21);
			this->select_operation->TabIndex = 19;
			this->select_operation->Text = L"Operation";
			// 
			// button_calc
			// 
			this->button_calc->Location = System::Drawing::Point(218, 208);
			this->button_calc->Name = L"button_calc";
			this->button_calc->Size = System::Drawing::Size(75, 23);
			this->button_calc->TabIndex = 20;
			this->button_calc->Text = L"Calc";
			this->button_calc->UseVisualStyleBackColor = true;
			this->button_calc->Click += gcnew System::EventHandler(this, &MainForm::button_calc_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(172, 335);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 13);
			this->label6->TabIndex = 21;
			// 
			// label_operation
			// 
			this->label_operation->AutoSize = true;
			this->label_operation->Location = System::Drawing::Point(166, 334);
			this->label_operation->Name = L"label_operation";
			this->label_operation->Size = System::Drawing::Size(28, 13);
			this->label_operation->TabIndex = 22;
			this->label_operation->Text = L"oper";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(998, 489);
			this->Controls->Add(this->label_operation);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button_calc);
			this->Controls->Add(this->select_operation);
			this->Controls->Add(this->B_label_matrix);
			this->Controls->Add(this->B_button_append);
			this->Controls->Add(this->B_input_item);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->B_label_notification);
			this->Controls->Add(this->B_button_create);
			this->Controls->Add(this->B_select_type);
			this->Controls->Add(this->B_input_size);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label_info);
			this->Controls->Add(this->A_label_matrix);
			this->Controls->Add(this->A_label_notification);
			this->Controls->Add(this->A_button_append);
			this->Controls->Add(this->A_button_create);
			this->Controls->Add(this->A_select_type);
			this->Controls->Add(this->A_input_item);
			this->Controls->Add(this->A_input_size);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button_create_Click(System::Object^ sender, System::EventArgs^ e) {
		//String info("");
		const int size = A_size = System::Convert::ToInt32(A_input_size->Text);
		String^ type = A_select_type->Text;
		label_info->Text += "\n\nA:\nsize: " + A_size + "\n";
		label_info->Text += "type: " + type + "\n";
		label_info->Text += "pointer: " + A_pointer_item + "\n";
		A_label_notification->Text = "Matrix A (" + A_input_size->Text + " x " + A_input_size->Text +") is created!";
		//label_notification->ForeColor = "green";
		if (type == "int") {
			int** nullItems = new int* [size];
			for (int i = 0; i < size; i++) {
				nullItems[i] = new int[size];
				for (int j = 0; j < size; j++) {
					nullItems[i][j] = 0;
				}
			}
			A_Matrix_int = MAIN::Matrix<int>(nullItems, A_size);
			A_code_type = TYPE_INT;
		}
		else if (type == "double") {
			label_info->Text += "double\n";
			A_code_type = TYPE_DOUBLE;
		}
		else if (type == "float") {
			label_info->Text += "float\n";
			A_code_type = TYPE_FLOAT;
		}
		else if (type == "complex") {
			label_info->Text += "complex\n";
			A_code_type = TYPE_COMPLEX;
		}
		else {
			label_info->Text += "string\n";
			A_code_type = TYPE_STRING;
		}

	}
	private: System::Void B_button_create_Click(System::Object^ sender, System::EventArgs^ e) {
		//String info("");
		const int size = System::Convert::ToInt32(B_input_size->Text);
		String^ type = B_select_type->Text;
		label_info->Text += "\n\nB:\nsize: " + B_input_size->Text + "\n";
		label_info->Text += "type: " + type + "\n";
		B_label_notification->Text = "Matrix B (" + B_input_size->Text + " x " + B_input_size->Text + ") is created!";
		//label_notification->ForeColor = "green";
		if (type == "int") {
			int** nullItems = new int* [size];
			for (int i = 0; i < size; i++) {
				nullItems[i] = new int[size];
				for (int j = 0; j < size; j++){
					nullItems[i][j] = 0;
				}
			}
			B_Matrix_int = MAIN::Matrix<int>(nullItems, size);

		}
		else if (type == "double") {
			label_info->Text += "double\n";
			A_code_type = TYPE_DOUBLE;
		}
		else if (type == "float") {
			label_info->Text += "float\n";
		}
		else if (type == "complex") {
			label_info->Text += "complex\n";
		}
		else {
			label_info->Text += "string\n";
		}
	}
	private: System::Void A_button_append_Click(System::Object^ sender, System::EventArgs^ e) {
		//A_label_matrix->Text += "\n";
		switch (A_code_type) {
			case TYPE_INT: {
				int row = A_pointer_item / A_size;
				int col = A_pointer_item % A_size;
				int item = System::Convert::ToInt32(A_input_item->Text);
				if (col == 0) A_label_matrix->Text += "\n";
				A_Matrix_int.Set(item, row, col);
				A_label_matrix->Text += " " + A_input_item->Text + " ";
				A_pointer_item++;
			}
		}
	}
	private: System::Void B_button_append_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button_calc_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
