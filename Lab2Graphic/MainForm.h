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
	MAIN::Matrix<string> A_Matrix_string;
	MAIN::Matrix<complex<double>> A_Matrix_complex;

	// default matrix B
	int B_size = 0;
	int B_code_type;
	int B_pointer_item = 0;
	MAIN::Matrix<int> B_Matrix_int;
	MAIN::Matrix<double> B_Matrix_double;
	MAIN::Matrix<float> B_Matrix_float;
	MAIN::Matrix<string> B_Matrix_string;
	MAIN::Matrix<complex<double>> B_Matrix_complex;

	double alpha;

	void MarshalString(String^ s, string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

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
	private: System::Windows::Forms::TextBox^ input_alpha;
	protected:


	private: System::Windows::Forms::ComboBox^ A_select_type;
	private: System::Windows::Forms::Button^ A_button_create;
	private: System::Windows::Forms::Button^ button_init_alpha;
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
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ B_input_item;
	private: System::Windows::Forms::Button^ B_button_append;
	private: System::Windows::Forms::Label^ B_label_matrix;
	private: System::Windows::Forms::Label^ Result_label_matrix;



	private: System::Windows::Forms::ComboBox^ select_operation;
	private: System::Windows::Forms::Button^ button_calc;


	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label_operation;
	private: System::Windows::Forms::ComboBox^ select_norm;
	private: System::Windows::Forms::Button^ button_calc_norm;




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
			this->input_alpha = (gcnew System::Windows::Forms::TextBox());
			this->A_input_item = (gcnew System::Windows::Forms::TextBox());
			this->A_select_type = (gcnew System::Windows::Forms::ComboBox());
			this->A_button_create = (gcnew System::Windows::Forms::Button());
			this->button_init_alpha = (gcnew System::Windows::Forms::Button());
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
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->B_input_item = (gcnew System::Windows::Forms::TextBox());
			this->B_button_append = (gcnew System::Windows::Forms::Button());
			this->B_label_matrix = (gcnew System::Windows::Forms::Label());
			this->Result_label_matrix = (gcnew System::Windows::Forms::Label());
			this->select_operation = (gcnew System::Windows::Forms::ComboBox());
			this->button_calc = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label_operation = (gcnew System::Windows::Forms::Label());
			this->select_norm = (gcnew System::Windows::Forms::ComboBox());
			this->button_calc_norm = (gcnew System::Windows::Forms::Button());
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
			// input_alpha
			// 
			this->input_alpha->Location = System::Drawing::Point(94, 165);
			this->input_alpha->Name = L"input_alpha";
			this->input_alpha->Size = System::Drawing::Size(63, 20);
			this->input_alpha->TabIndex = 0;
			this->input_alpha->Text = L"Alpha";
			// 
			// A_input_item
			// 
			this->A_input_item->Location = System::Drawing::Point(650, 77);
			this->A_input_item->Name = L"A_input_item";
			this->A_input_item->Size = System::Drawing::Size(110, 20);
			this->A_input_item->TabIndex = 1;
			this->A_input_item->Text = L"Item";
			this->A_input_item->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::A_input_item_KeyPress);
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
			this->A_button_create->Click += gcnew System::EventHandler(this, &MainForm::A_button_create_Click);
			// 
			// button_init_alpha
			// 
			this->button_init_alpha->Location = System::Drawing::Point(186, 165);
			this->button_init_alpha->Name = L"button_init_alpha";
			this->button_init_alpha->Size = System::Drawing::Size(107, 20);
			this->button_init_alpha->TabIndex = 3;
			this->button_init_alpha->Text = L"init alpha";
			this->button_init_alpha->UseVisualStyleBackColor = true;
			this->button_init_alpha->Click += gcnew System::EventHandler(this, &MainForm::button_init_alpha_Click);
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
			this->A_label_matrix->Size = System::Drawing::Size(48, 13);
			this->A_label_matrix->TabIndex = 6;
			this->A_label_matrix->Text = L"A Matrix:";
			// 
			// label_info
			// 
			this->label_info->AutoSize = true;
			this->label_info->Location = System::Drawing::Point(821, 284);
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
			this->B_input_size->Location = System::Drawing::Point(94, 121);
			this->B_input_size->Name = L"B_input_size";
			this->B_input_size->Size = System::Drawing::Size(63, 20);
			this->B_input_size->TabIndex = 9;
			this->B_input_size->Text = L"Size";
			// 
			// B_select_type
			// 
			this->B_select_type->FormattingEnabled = true;
			this->B_select_type->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"int", L"double", L"float", L"complex", L"string" });
			this->B_select_type->Location = System::Drawing::Point(186, 121);
			this->B_select_type->Name = L"B_select_type";
			this->B_select_type->Size = System::Drawing::Size(107, 21);
			this->B_select_type->TabIndex = 10;
			this->B_select_type->Text = L"type";
			// 
			// B_button_create
			// 
			this->B_button_create->Location = System::Drawing::Point(325, 121);
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
			this->B_label_notification->Location = System::Drawing::Point(483, 124);
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
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(44, 167);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(37, 13);
			this->label21->TabIndex = 13;
			this->label21->Text = L"Alpha:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(44, 125);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(17, 13);
			this->label3->TabIndex = 14;
			this->label3->Text = L"B:";
			// 
			// B_input_item
			// 
			this->B_input_item->Location = System::Drawing::Point(650, 122);
			this->B_input_item->Name = L"B_input_item";
			this->B_input_item->Size = System::Drawing::Size(110, 20);
			this->B_input_item->TabIndex = 15;
			this->B_input_item->Text = L"Item";
			this->B_input_item->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::B_input_item_KeyPress);
			// 
			// B_button_append
			// 
			this->B_button_append->Location = System::Drawing::Point(810, 122);
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
			this->B_label_matrix->Location = System::Drawing::Point(289, 285);
			this->B_label_matrix->Name = L"B_label_matrix";
			this->B_label_matrix->Size = System::Drawing::Size(48, 13);
			this->B_label_matrix->TabIndex = 17;
			this->B_label_matrix->Text = L"B Matrix:";
			// 
			// Result_label_matrix
			// 
			this->Result_label_matrix->AutoSize = true;
			this->Result_label_matrix->Location = System::Drawing::Point(412, 284);
			this->Result_label_matrix->Name = L"Result_label_matrix";
			this->Result_label_matrix->Size = System::Drawing::Size(40, 13);
			this->Result_label_matrix->TabIndex = 17;
			this->Result_label_matrix->Text = L"Result:";
			// 
			// select_operation
			// 
			this->select_operation->FormattingEnabled = true;
			this->select_operation->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"+", L"-", L"*", L"* alpha" });
			this->select_operation->Location = System::Drawing::Point(47, 210);
			this->select_operation->Name = L"select_operation";
			this->select_operation->Size = System::Drawing::Size(107, 21);
			this->select_operation->TabIndex = 19;
			this->select_operation->Text = L"Operation";
			// 
			// button_calc
			// 
			this->button_calc->Location = System::Drawing::Point(186, 210);
			this->button_calc->Name = L"button_calc";
			this->button_calc->Size = System::Drawing::Size(107, 23);
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
			this->label_operation->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_operation->Location = System::Drawing::Point(171, 280);
			this->label_operation->Name = L"label_operation";
			this->label_operation->Size = System::Drawing::Size(47, 22);
			this->label_operation->TabIndex = 22;
			this->label_operation->Text = L"oper";
			// 
			// select_norm
			// 
			this->select_norm->FormattingEnabled = true;
			this->select_norm->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Norm K", L"Norm L", L"Norm M" });
			this->select_norm->Location = System::Drawing::Point(325, 212);
			this->select_norm->Name = L"select_norm";
			this->select_norm->Size = System::Drawing::Size(112, 21);
			this->select_norm->TabIndex = 23;
			this->select_norm->Text = L"Norm";
			// 
			// button_calc_norm
			// 
			this->button_calc_norm->Location = System::Drawing::Point(467, 212);
			this->button_calc_norm->Name = L"button_calc_norm";
			this->button_calc_norm->Size = System::Drawing::Size(107, 21);
			this->button_calc_norm->TabIndex = 24;
			this->button_calc_norm->Text = L"Calc norm";
			this->button_calc_norm->UseCompatibleTextRendering = true;
			this->button_calc_norm->UseVisualStyleBackColor = true;
			this->button_calc_norm->Click += gcnew System::EventHandler(this, &MainForm::button_calc_norm_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1012, 556);
			this->Controls->Add(this->button_calc_norm);
			this->Controls->Add(this->select_norm);
			this->Controls->Add(this->label_operation);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button_calc);
			this->Controls->Add(this->select_operation);
			this->Controls->Add(this->B_label_matrix);
			this->Controls->Add(this->Result_label_matrix);
			this->Controls->Add(this->B_button_append);
			this->Controls->Add(this->B_input_item);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label21);
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
			this->Controls->Add(this->button_init_alpha);
			this->Controls->Add(this->A_select_type);
			this->Controls->Add(this->A_input_item);
			this->Controls->Add(this->A_input_size);
			this->Controls->Add(this->input_alpha);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button_init_alpha_Click(System::Object^ sender, System::EventArgs^ e) {
		alpha = System::Convert::ToDouble(input_alpha->Text);
		label_info->Text += "\n\nalpha: " + alpha + "\n";
	}
	private: System::Void A_button_create_Click(System::Object^ sender, System::EventArgs^ e) {
		const int size = A_size = System::Convert::ToInt32(A_input_size->Text);
		String^ type = A_select_type->Text;
		label_info->Text += "\n\nA:\nsize: " + A_size + "\n";
		label_info->Text += "type: " + type + "\n";
		label_info->Text += "pointer: " + A_pointer_item + "\n";
		A_label_notification->Text = "Matrix A (" + A_size + " x " + A_size +") is created!";


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
			double** nullItems = new double* [size];
			for (int i = 0; i < size; i++) {
				nullItems[i] = new double[size];
				for (int j = 0; j < size; j++) {
					nullItems[i][j] = 0;
				}
			}
			A_Matrix_double = MAIN::Matrix<double>(nullItems, A_size);
			A_code_type = TYPE_DOUBLE;
		}
		else if (type == "float") {
			float** nullItems = new float* [size];
			for (int i = 0; i < size; i++) {
				nullItems[i] = new float[size];
				for (int j = 0; j < size; j++) {
					nullItems[i][j] = 0;
				}
			}
			A_Matrix_float = MAIN::Matrix<float>(nullItems, A_size);
			A_code_type = TYPE_FLOAT;
		}
		else if (type == "complex") {
			complex<double>** nullItems = new complex<double>* [size];
			for (int i = 0; i < size; i++) {
				nullItems[i] = new complex<double>[size];
				for (int j = 0; j < size; j++) {
					nullItems[i][j] = 0. + 0i;
				}
			}
			A_Matrix_complex = MAIN::Matrix<complex<double>>(nullItems, A_size);
			A_code_type = TYPE_COMPLEX;
		}
		else if(type == "string"){
			string** nullItems = new string *[size];
			for (int i = 0; i < size; i++) {
				nullItems[i] = new string[size];
				for (int j = 0; j < size; j++) {
					nullItems[i][j] = "";
				}
			}
			A_Matrix_string = MAIN::Matrix<string>(nullItems, A_size);
			A_code_type = TYPE_STRING;
		}

	}
	private: System::Void B_button_create_Click(System::Object^ sender, System::EventArgs^ e) {
		const int size = B_size = System::Convert::ToInt32(B_input_size->Text);
		String^ type = B_select_type->Text;
		label_info->Text += "\n\nB:\nsize: " + B_size + "\n";
		label_info->Text += "type: " + type + "\n";
		B_label_notification->Text = "Matrix B (" + B_input_size->Text + " x " + B_input_size->Text + ") is created!";

		if (type == "int") {
			int** nullItems = new int* [size];
			for (int i = 0; i < size; i++) {
				nullItems[i] = new int[size];
				for (int j = 0; j < size; j++){
					nullItems[i][j] = 0;
				}
			}
			B_Matrix_int = MAIN::Matrix<int>(nullItems, size);
			B_code_type = TYPE_INT;
		}
		else if (type == "double") {
			double** nullItems = new double* [size];
			for (int i = 0; i < size; i++) {
				nullItems[i] = new double[size];
				for (int j = 0; j < size; j++) {
					nullItems[i][j] = 0;
				}
			}
			B_Matrix_double = MAIN::Matrix<double>(nullItems, size);
			B_code_type = TYPE_DOUBLE;
		}
		else if (type == "float") {
			float** nullItems = new float* [size];
			for (int i = 0; i < size; i++) {
				nullItems[i] = new float[size];
				for (int j = 0; j < size; j++) {
					nullItems[i][j] = 0;
				}
			}
			B_Matrix_float = MAIN::Matrix<float>(nullItems, size);
			B_code_type = TYPE_FLOAT;
		}
		else if (type == "complex") {
			complex<double>** nullItems = new complex<double>*[size];
			for (int i = 0; i < size; i++) {
				nullItems[i] = new complex<double>[size];
				for (int j = 0; j < size; j++) {
					nullItems[i][j] = 0. + 0i;
				}
			}
			B_Matrix_complex = MAIN::Matrix<complex<double>>(nullItems, B_size);
			B_code_type = TYPE_COMPLEX;
		}
		else if (type == "string") {
			string** nullItems = new string * [size];
			for (int i = 0; i < size; i++) {
				nullItems[i] = new string[size];
				for (int j = 0; j < size; j++) {
					nullItems[i][j] = "";
				}
			}
			B_Matrix_string = MAIN::Matrix<string>(nullItems, B_size);
			B_code_type = TYPE_STRING;
		}
	}

	private: void clear_Result_label() {
		this->Result_label_matrix->Text = L"Result Matrixes:";
	}


	private: System::Void A_button_append_Click(System::Object^ sender, System::EventArgs^ e) {
		//A_label_matrix->Text += "\n";
		switch (A_code_type) {
			case TYPE_INT: {
				int row = A_pointer_item / A_size;
				int col = A_pointer_item % A_size;
				int item = System::Convert::ToInt32(A_input_item->Text);
				if (row < A_size) {
					if (col == 0) A_label_matrix->Text += "\n";
					A_Matrix_int.Set(item, row, col);
					A_label_matrix->Text += " " + A_input_item->Text + " ";
					A_pointer_item++;
				}
				else {
					A_label_notification->Text = "item limit exceeded";
					A_label_notification->ForeColor = System::Drawing::Color::Red;
				}
			}; break;
			case TYPE_DOUBLE: {
				int row = A_pointer_item / A_size;
				int col = A_pointer_item % A_size;
				double item = System::Convert::ToDouble(A_input_item->Text);
				if (row < A_size) {
					if (col == 0) A_label_matrix->Text += "\n";
					A_Matrix_double.Set(item, row, col);
					A_label_matrix->Text += " " + A_input_item->Text + " ";
					A_pointer_item++;
				}
				else {
					A_label_notification->Text = "item limit exceeded";
					A_label_notification->ForeColor = System::Drawing::Color::Red;
				}
			}; break;
			case TYPE_FLOAT: {
				int row = A_pointer_item / A_size;
				int col = A_pointer_item % A_size;
				double item = System::Convert::ToDouble(A_input_item->Text);
				if (row < A_size) {
					if (col == 0) A_label_matrix->Text += "\n";
					A_Matrix_float.Set(item, row, col);
					A_label_matrix->Text += " " + A_input_item->Text + " ";
					A_pointer_item++;
				}
				else {
					A_label_notification->Text = "item limit exceeded";
					A_label_notification->ForeColor = System::Drawing::Color::Red;
				}
			}; break;
			case TYPE_COMPLEX: {
				int row = A_pointer_item / A_size;
				int col = A_pointer_item % A_size;

				string s;
				MarshalString(A_input_item->Text, s);

				std::istringstream is('(' + s + ')');
				std::complex<double> item;
				is >> item;
				//float item = System::Convert::ToDouble(B_input_item->Text);
				if (row < A_size) {
					if (col == 0) A_label_matrix->Text += "\n";
					A_Matrix_complex.Set(item, row, col);
					A_label_matrix->Text += " (" + item.real() + ", " + item.imag() + ") ";
					A_pointer_item++;
				}
				else {
					A_label_notification->Text = "item limit exceeded";
					A_label_notification->ForeColor = System::Drawing::Color::Red;
				}
			}; break;
			case TYPE_STRING: {
				int row = A_pointer_item / A_size;
				int col = A_pointer_item % A_size;

				string s;
				MarshalString(A_input_item->Text, s);

				if (row < A_size) {
					if (col == 0) A_label_matrix->Text += "\n";
					A_Matrix_string.Set(s, row, col);
					A_label_matrix->Text += " \"" + A_input_item->Text + "\" ";
					A_pointer_item++;
				}
				else {
					A_label_notification->Text = "item limit exceeded";
					A_label_notification->ForeColor = System::Drawing::Color::Red;
				}
			}; break;
		}
	}
	private: System::Void A_input_item_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == (char)Keys::Enter) {
			A_button_append_Click(sender, e);
			A_input_item->Text = "";
		}
	}
	private: System::Void B_button_append_Click(System::Object^ sender, System::EventArgs^ e) {
		//A_label_matrix->Text += "\n";
		switch (B_code_type) {
		case TYPE_INT: {
			int row = B_pointer_item / B_size;
			int col = B_pointer_item % B_size;
			int item = System::Convert::ToInt32(B_input_item->Text);
			if (row < B_size) {
				if (col == 0) B_label_matrix->Text += "\n";
				B_Matrix_int.Set(item, row, col);
				B_label_matrix->Text += " " + B_input_item->Text + " ";
				B_pointer_item++;
			}
			else {
				B_label_notification->Text = "item limit exceeded";
				B_label_notification->ForeColor = System::Drawing::Color::Red;
			}
		}; break;
		case TYPE_DOUBLE: {
			int row = B_pointer_item / B_size;
			int col = B_pointer_item % B_size;
			double item = System::Convert::ToDouble(B_input_item->Text);
			if (row < B_size) {
				if (col == 0) B_label_matrix->Text += "\n";
				B_Matrix_double.Set(item, row, col);
				B_label_matrix->Text += " " + B_input_item->Text + " ";
				B_pointer_item++;
			}
			else {
				B_label_notification->Text = "item limit exceeded";
				B_label_notification->ForeColor = System::Drawing::Color::Red;
			}
		}; break;
		case TYPE_FLOAT: {
			int row = B_pointer_item / B_size;
			int col = B_pointer_item % B_size;
			float item = System::Convert::ToDouble(B_input_item->Text);
			if (row < B_size) {
				if (col == 0) B_label_matrix->Text += "\n";
				B_Matrix_float.Set(item, row, col);
				B_label_matrix->Text += " " + B_input_item->Text + " ";
				B_pointer_item++;
			}
			else {
				B_label_notification->Text = "item limit exceeded";
				B_label_notification->ForeColor = System::Drawing::Color::Red;
			}
		}; break;
		case TYPE_COMPLEX: {
			int row = B_pointer_item / B_size;
			int col = B_pointer_item % B_size;

			string s;
			MarshalString(B_input_item->Text, s);

			std::istringstream is('(' + s + ')');
			std::complex<double> item;
			is >> item;
			//float item = System::Convert::ToDouble(B_input_item->Text);
			if (row < B_size) {
				if (col == 0) B_label_matrix->Text += "\n";
				B_Matrix_complex.Set(item, row, col);
				B_label_matrix->Text += " (" + item.real() + ", " + item.imag() + ") ";
				B_pointer_item++;
			}
			else {
				B_label_notification->Text = "item limit exceeded";
				B_label_notification->ForeColor = System::Drawing::Color::Red;
			}
		}; break;
		case TYPE_STRING: {
			int row = B_pointer_item / B_size;
			int col = B_pointer_item % B_size;

			string s;
			MarshalString(B_input_item->Text, s);

			if (row < B_size) {
				if (col == 0) B_label_matrix->Text += "\n";
				B_Matrix_string.Set(s, row, col);
				B_label_matrix->Text += " \"" + B_input_item->Text + "\" ";
				B_pointer_item++;
			}
			else {
				B_label_notification->Text = "item limit exceeded";
				B_label_notification->ForeColor = System::Drawing::Color::Red;
			}
		}; break;
		}
	}
	private: System::Void B_input_item_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		 if (e->KeyChar == (char)Keys::Enter) {
			  B_button_append_Click(sender, e);
			  B_input_item->Text = "";
		 }
	}

	private: System::Void button_calc_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ operation = select_operation->Text;
		if (operation == "+") {
			code_operation = OPERATION_PLUS;
			label_operation->Text = "+";
			Matrix<int> summ_int;
			Matrix<double> summ_double;
			Matrix<float> summ_float;
			Matrix<string> summ_string;
			Matrix<complex<double>> summ_complex;
			switch (A_code_type){
				case TYPE_INT: {
				summ_int = A_Matrix_int.SumOfMatrix(B_Matrix_int);
				clear_Result_label();
				for (int i = 0; i < A_size * A_size; i++) {
					if (i % A_size == 0) Result_label_matrix->Text += "\n";
					Result_label_matrix->Text += " " + summ_int.Get(i / A_size, i % A_size) + " ";
				}

			}; break;
				case TYPE_DOUBLE: {
					summ_double = A_Matrix_double.SumOfMatrix(B_Matrix_double);
					clear_Result_label();
					for (int i = 0; i < A_size * A_size; i++) {
						if (i % A_size == 0) Result_label_matrix->Text += "\n";
						Result_label_matrix->Text += " " + summ_double.Get(i / A_size, i % A_size) + " ";
					}

				}; break;
				case TYPE_FLOAT: {
					summ_float = A_Matrix_float.SumOfMatrix(B_Matrix_float);
					clear_Result_label();
					for (int i = 0; i < A_size * A_size; i++) {
						if (i % A_size == 0) Result_label_matrix->Text += "\n";
						Result_label_matrix->Text += " " + summ_float.Get(i / A_size, i % A_size) + " ";
					}
				}; break;
				case TYPE_COMPLEX: {
					summ_complex = A_Matrix_complex.SumOfMatrix(B_Matrix_complex);
					clear_Result_label();
					for (int i = 0; i < A_size * A_size; i++) {
						if (i % A_size == 0) Result_label_matrix->Text += "\n";
						Result_label_matrix->Text += " (" + summ_complex.Get(i / A_size, i % A_size).real() + ", " + summ_complex.Get(i / A_size, i % A_size).imag() + ") ";
					}

				}; break;
				case TYPE_STRING: {
					summ_string = A_Matrix_string.SumOfMatrix(B_Matrix_string);
					clear_Result_label();
					for (int i = 0; i < A_size * A_size; i++) {
						if (i % A_size == 0) Result_label_matrix->Text += "\n";
						String^ str = gcnew String(summ_string.Get(i / A_size, i % A_size).c_str());
						Result_label_matrix->Text += " \"" + str + "\" ";
					}

				}; break;
				default:
					break;
			}
		}
		else if (operation == "-") {
			code_operation = OPERATION_PLUS;
			label_operation->Text = "-";
			Matrix<int> subs_int;
			Matrix<double> subs_double;
			Matrix<float> subs_float;
			Matrix<complex<double>> subs_complex;
			switch (A_code_type) {
			case TYPE_INT: {
				subs_int = A_Matrix_int.SubOfMatrix(B_Matrix_int);
				clear_Result_label();
				for (int i = 0; i < A_size * A_size; i++) {
					if (i % A_size == 0) Result_label_matrix->Text += "\n";
					Result_label_matrix->Text += " " + subs_int.Get(i / A_size, i % A_size) + " ";
				}

			}; break;
			case TYPE_DOUBLE: {
				subs_double = A_Matrix_double.SubOfMatrix(B_Matrix_double);
				clear_Result_label();
				for (int i = 0; i < A_size * A_size; i++) {
					if (i % A_size == 0) Result_label_matrix->Text += "\n";
					Result_label_matrix->Text += " " + subs_double.Get(i / A_size, i % A_size) + " ";
				}

			}; break;
			case TYPE_FLOAT: {
				subs_float = A_Matrix_float.SubOfMatrix(B_Matrix_float);
				clear_Result_label();
				for (int i = 0; i < A_size * A_size; i++) {
					if (i % A_size == 0) Result_label_matrix->Text += "\n";
					Result_label_matrix->Text += " " + subs_float.Get(i / A_size, i % A_size) + " ";
				}

			}; break;
			case TYPE_COMPLEX: {
				subs_complex = A_Matrix_complex.SubOfMatrix(B_Matrix_complex);
				clear_Result_label();
				for (int i = 0; i < A_size * A_size; i++) {
					if (i % A_size == 0) Result_label_matrix->Text += "\n";
					Result_label_matrix->Text += " (" + subs_complex.Get(i / A_size, i % A_size).real() + ", " + subs_complex.Get(i / A_size, i % A_size).imag() + ") ";
				}

			}; break;
			default:
				break;
			}
		}
		else if (operation == "*") {
			code_operation = OPERATION_PLUS;
			label_operation->Text = "*";
			Matrix<int> mult_int;
			Matrix<double> mult_double;
			Matrix<float> mult_float;
			Matrix<complex<double>> mult_complex;
			switch (A_code_type) {
			case TYPE_INT: {
				mult_int = A_Matrix_int.MultOfMatrix(B_Matrix_int);
				clear_Result_label();
				for (int i = 0; i < A_size * A_size; i++) {
					if (i % A_size == 0) Result_label_matrix->Text += "\n";
					Result_label_matrix->Text += " " + mult_int.Get(i / A_size, i % A_size) + " ";
				}

			}; break;
			case TYPE_DOUBLE: {
				mult_double = A_Matrix_double.MultOfMatrix(B_Matrix_double);
				clear_Result_label();
				for (int i = 0; i < A_size * A_size; i++) {
					if (i % A_size == 0) Result_label_matrix->Text += "\n";
					Result_label_matrix->Text += " " + mult_double.Get(i / A_size, i % A_size) + " ";
				}

			}; break;
			case TYPE_FLOAT: {
				mult_float = A_Matrix_float.MultOfMatrix(B_Matrix_float);
				clear_Result_label();
				for (int i = 0; i < A_size * A_size; i++) {
					if (i % A_size == 0) Result_label_matrix->Text += "\n";
					Result_label_matrix->Text += " " + mult_float.Get(i / A_size, i % A_size) + " ";
				}

			}; break;
			case TYPE_COMPLEX: {
				mult_complex = A_Matrix_complex.MultOfMatrix(B_Matrix_complex);
				clear_Result_label();
				for (int i = 0; i < A_size * A_size; i++) {
					if (i % A_size == 0) Result_label_matrix->Text += "\n";
					Result_label_matrix->Text += " (" + mult_complex.Get(i / A_size, i % A_size).real() + ", " + mult_complex.Get(i / A_size, i % A_size).imag() + ") ";
				}

			}; break;
			default:
				break;
			}
		}
		else if (operation == "* alpha") {
			code_operation = OPERATION_PLUS;
			label_operation->Text = "* alpha";
			Matrix<int> mult_int;
			Matrix<double> mult_double;
			Matrix<float> mult_float;
			Matrix<string> mult_string;
			Matrix<complex<double>> mult_complex;
			switch (A_code_type) {
				case TYPE_INT: {
					mult_int = A_Matrix_int.MultOfMatrixOnAlpha(alpha);
					clear_Result_label();
					for (int i = 0; i < A_size * A_size; i++) {
						if (i % A_size == 0) Result_label_matrix->Text += "\n";
						Result_label_matrix->Text += " " + mult_int.Get(i / A_size, i % A_size) + " ";
					}

				}; break;
				case TYPE_DOUBLE: {
					mult_double = A_Matrix_double.MultOfMatrixOnAlpha(alpha);
					clear_Result_label();
					for (int i = 0; i < A_size * A_size; i++) {
						if (i % A_size == 0) Result_label_matrix->Text += "\n";
						Result_label_matrix->Text += " " + mult_double.Get(i / A_size, i % A_size) + " ";
					}

				}; break;
				case TYPE_FLOAT: {
					mult_float = A_Matrix_float.MultOfMatrixOnAlpha(alpha);
					clear_Result_label();
					for (int i = 0; i < A_size * A_size; i++) {
						if (i % A_size == 0) Result_label_matrix->Text += "\n";
						Result_label_matrix->Text += " " + mult_float.Get(i / A_size, i % A_size) + " ";
					}

				}; break;
				case TYPE_COMPLEX: {
					mult_complex = A_Matrix_complex.MultOfMatrixOnAlpha(alpha);
					clear_Result_label();
					for (int i = 0; i < A_size * A_size; i++) {
						if (i % A_size == 0) Result_label_matrix->Text += "\n";
						Result_label_matrix->Text += " (" + mult_complex.Get(i / A_size, i % A_size).real() + ", " + mult_complex.Get(i / A_size, i % A_size).imag() + ") ";
					}

				}; break;
				case TYPE_STRING: {
					string** items = new string* [A_size];
					for (int i = 0; i < A_size; i++) {
						items[i] = new string[A_size];
					}
					mult_string = MAIN::Matrix<string>(items, A_size);
					for (int i = 0; i < alpha; i++) {
						mult_string = mult_string.SumOfMatrix(A_Matrix_string);
					}
					clear_Result_label();
					for (int i = 0; i < A_size * A_size; i++) {
						if (i % A_size == 0) Result_label_matrix->Text += "\n";
						String^ str = gcnew String(mult_string.Get(i / A_size, i % A_size).c_str());
						Result_label_matrix->Text += " \"" + str + "\" ";
					}

				}; break;
				default:
					break;
			}
		}
	}

	private: System::Void button_calc_norm_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ type = select_norm->Text;
		clear_Result_label();
		if (type == "Norm K") {
			switch (A_code_type) {
				case TYPE_INT: Result_label_matrix->Text += A_Matrix_int.NormK(); break;
				case TYPE_DOUBLE: Result_label_matrix->Text += A_Matrix_double.NormK(); break;
				case TYPE_FLOAT: Result_label_matrix->Text += A_Matrix_float.NormK(); break;
				case TYPE_COMPLEX: Result_label_matrix->Text += "(" + A_Matrix_complex.NormK().real() + ", " + A_Matrix_complex.NormK().imag() +") "; break;
				default: break;
			}
		}
		else if (type == "Norm L") {
			switch (A_code_type) {
				case TYPE_INT: Result_label_matrix->Text += A_Matrix_int.NormL(); break;
				case TYPE_DOUBLE: Result_label_matrix->Text += A_Matrix_double.NormL(); break;
				case TYPE_FLOAT: Result_label_matrix->Text += A_Matrix_float.NormL(); break;
				//case TYPE_COMPLEX: Result_label_matrix->Text += "(" + A_Matrix_complex.NormL().real() + ", " + A_Matrix_complex.NormL().imag() + ") "; break;
				default: break;
			}
		}
		else if (type == "Norm M") {
			switch (A_code_type) {
				case TYPE_INT: Result_label_matrix->Text += A_Matrix_int.NormM(); break;
				case TYPE_DOUBLE: Result_label_matrix->Text += A_Matrix_double.NormM(); break;
				case TYPE_FLOAT: Result_label_matrix->Text += A_Matrix_float.NormM(); break;
				//case TYPE_COMPLEX: Result_label_matrix->Text += "(" + A_Matrix_complex.NormM().real() + ", " + A_Matrix_complex.NormM().imag() + ") "; break;
				default: break;
			}
		}
	}
};
}
