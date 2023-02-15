#pragma 
#include <math.h>
#include <string>

double func(double x) {
	return pow(x, 4) - 2 * x - 1;
}

String^ sliceStr(String^ str) {
	int index = str->IndexOf(',');
	if (index == -1) return str;
	return str->Substring(0, index) + str->Substring(index, 5);
}


bool isAllDigits(String^ str) {
	int i = 0;
	bool point = false;

	str->Replace('.', ',');
	if (str[0] == '-') i++;

	while (i < str->Length) {
		if (!isdigit(str[i])) {
			if (str[i] == ',') {
				if (point) return false;
				else point = true;
			}
			else return false;
		}
		
		i++;
	}
	return true;
}
//Структура для создания объектов содержащих необходимую информацию

struct RootData {
public:
	int iterations = 0;
	double root;
};

RootData findRootBetween(double left, double right, String^ method) {
	RootData data;
	double eps = 1e-4;
	int iterations = 30000;

	double x = left, f = func(left);
	if (method == "half division") {
		f = func(x);
		while (fabs(f) >= eps && data.iterations <= iterations) {
			x = (left + right) / 2;
			f = func(x);
			func(left)* f < 0 ? right = x : left = x;
			data.iterations++;
		}
		data.root = x;
	}

	else if (method == "secant") {
		f = func(x);
		while (fabs(f) >= eps && data.iterations < iterations) {
			x = left - func(left) / (func(right) - func(left)) * (right - left);
			f = func(x);
			func(left)* f < 0 ? right = x : left = x;
			data.iterations++;
		}
		data.root = x;
	}
	if (data.iterations == iterations && fabs(func(data.root)) >= eps) {
		data.iterations = -1;
		data.root = NULL;
	}
	return data;
}


namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		int mainVar = 1;
		Form1(void)
		{
			InitializeComponent();
		}

	protected:
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ left;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ root1;
	private: System::Windows::Forms::TextBox^ right;
	private: System::Windows::Forms::Label^ root1Sec;
	private: System::Windows::Forms::Label^ root2Sec;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ root2;
	private: System::Windows::Forms::Label^ halfdiv;
	private: System::Windows::Forms::Label^ secant;

		   /// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;



	protected:

	protected:

	private:
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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->left = (gcnew System::Windows::Forms::TextBox());
			this->right = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->root1 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->root2 = (gcnew System::Windows::Forms::Label());
			this->halfdiv = (gcnew System::Windows::Forms::Label());
			this->secant = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->root1Sec = (gcnew System::Windows::Forms::Label());
			this->root2Sec = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Location = System::Drawing::Point(0, 0);
			this->chart1->MaximumSize = System::Drawing::Size(500, 380);
			this->chart1->MinimumSize = System::Drawing::Size(250, 190);
			this->chart1->Name = L"chart1";
			series1->BorderWidth = 3;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(500, 380);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			title1->Name = L"Title1";
			title1->Text = L"x^4 - 2x - 1";
			this->chart1->Titles->Add(title1);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 405);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(238, 41);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Построить график функции";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(262, 405);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(238, 41);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Найти корни";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			this->button2->Hide();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(534, 405);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Левая граница";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(534, 433);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Правая граница";
			// 
			// left
			// 
			this->left->Location = System::Drawing::Point(672, 402);
			this->left->Name = L"left";
			this->left->Size = System::Drawing::Size(74, 20);
			this->left->TabIndex = 6;
			this->left->Text = L"0";
			// 
			// right
			// 
			this->right->Location = System::Drawing::Point(672, 426);
			this->right->Name = L"right";
			this->right->Size = System::Drawing::Size(74, 20);
			this->right->TabIndex = 7;
			this->right->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(534, 150);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(122, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Количество итераций: ";
			// 
			// root1
			// 
			this->root1->AutoSize = true;
			this->root1->Location = System::Drawing::Point(706, 73);
			this->root1->Name = L"root1";
			this->root1->Size = System::Drawing::Size(31, 13);
			this->root1->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(534, 178);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(155, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Метод половинного деления:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(535, 201);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(88, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Метод секущих:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(534, 45);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(41, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Корни:";
			// 
			// root2
			// 
			this->root2->AutoSize = true;
			this->root2->Location = System::Drawing::Point(767, 73);
			this->root2->Name = L"root2";
			this->root2->Size = System::Drawing::Size(31, 13);
			this->root2->TabIndex = 13;
			// 
			// halfdiv
			// 
			this->halfdiv->AutoSize = true;
			this->halfdiv->Location = System::Drawing::Point(706, 178);
			this->halfdiv->Name = L"halfdiv";
			this->halfdiv->Size = System::Drawing::Size(40, 13);
			this->halfdiv->TabIndex = 14;
			// 
			// secant
			// 
			this->secant->AutoSize = true;
			this->secant->Location = System::Drawing::Point(706, 201);
			this->secant->Name = L"secant";
			this->secant->Size = System::Drawing::Size(39, 13);
			this->secant->TabIndex = 15;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(534, 73);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(155, 13);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Метод половинного деления:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(535, 95);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(88, 13);
			this->label9->TabIndex = 17;
			this->label9->Text = L"Метод секущих:";
			// 
			// root1Sec
			// 
			this->root1Sec->AutoSize = true;
			this->root1Sec->Location = System::Drawing::Point(706, 95);
			this->root1Sec->Name = L"root1Sec";
			this->root1Sec->Size = System::Drawing::Size(41, 13);
			this->root1Sec->TabIndex = 18;
			// 
			// root2Sec
			// 
			this->root2Sec->AutoSize = true;
			this->root2Sec->Location = System::Drawing::Point(767, 95);
			this->root2Sec->Name = L"root2Sec";
			this->root2Sec->Size = System::Drawing::Size(41, 13);
			this->root2Sec->TabIndex = 19;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(860, 485);
			this->Controls->Add(this->root2Sec);
			this->Controls->Add(this->root1Sec);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->secant);
			this->Controls->Add(this->halfdiv);
			this->Controls->Add(this->root2);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->root1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->right);
			this->Controls->Add(this->left);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chart1);
			this->Name = L"Form1";
			this->Text = L"Application";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	bool constructed = false;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//Построение графика
		if (constructed) return;
		double a = -2, b = 2, h = 0.1, x, y;
		this->chart1->Series[0]->Points->Clear();
		x = a;
		while (x >= a && x <= b) {
			y = func(x);
			this->chart1->Series[0]->Points->AddXY(x, y);
			x += h; 
		}
		//После построение графика появляется кнопка
		constructed = true;
		this->button2->Show();


	}
	
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ leftStr = this->left->Text->Replace('.', ',');
		String^ rightStr = this->right->Text->Replace('.', ',');

		//Проверка введённых значений
		//Игнорирование нажатой кнопки при ошибке валидации значений
		if (leftStr->Length == 0 || rightStr->Length == 0 || !(isAllDigits(leftStr)) || !(isAllDigits(rightStr))) return;
		double left = System::Convert::ToDouble(leftStr), right = System::Convert::ToDouble(rightStr);
		if (System::Convert::ToInt32(left) - System::Convert::ToInt32(right) == 0) return;
	
		RootData root1;
		RootData root2;
		RootData root1Sec;
		RootData root2Sec;

		//Поиск корней
		//1 корень
		if (func(left) * func(right) < 0) {
			root1 = findRootBetween(left, right, "half division");
			root1Sec = findRootBetween(left, right, "secant");
			root2.root = root2Sec.root = NULL;
		}
		else {
			//Нет корней
			if (func(left) < 0 && func(right) < 0) root1.root = root2.root = root1Sec.root = root2Sec.root = NULL;
			//2 корня || Нет корней
			else {
				double step = (fabs(left) + fabs(right)) / 100;
				double newLeft, tempLeft = left;
				while (tempLeft < right) {
					if (func(tempLeft) < 0) {
						newLeft = tempLeft;
						root1 = findRootBetween(left, newLeft, "half division");
						root2 = findRootBetween(newLeft, right, "half division");
						root1Sec = findRootBetween(left, newLeft, "secant");
						root2Sec = findRootBetween(newLeft, right, "secant");
						break;
					}


					tempLeft += step;
				}
				if (left >= right) root1.root = root2.root = root1Sec.root = root2Sec.root = NULL;
				
			}
		}
		//

		this->root1->Text = root1.root == NULL ? L"Нет" : sliceStr(root1.root.ToString());
		this->root2->Text = root2.root == NULL ? L"Нет" : sliceStr(root2.root.ToString());
		this->root1Sec->Text = root1Sec.root == NULL ? L"Нет" : sliceStr(root1Sec.root.ToString());
		this->root2Sec->Text = root2Sec.root == NULL ? L"Нет" : sliceStr(root2Sec.root.ToString());

		this->halfdiv->Text = (root1.iterations == -1 || root2.iterations == -1) ? L"Слишком много итераций" : (root1.iterations + root2.iterations).ToString();
		this->secant->Text = (root1Sec.iterations == -1 || root2Sec.iterations == -1) ? L"Слишком много итераций" : (root1Sec.iterations + root2Sec.iterations).ToString();
	}
};
}