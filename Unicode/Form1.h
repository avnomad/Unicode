#pragma once


namespace Unicode {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->SuspendLayout();
			// 
			// Form1
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->DoubleBuffered = true;
			this->ForeColor = System::Drawing::Color::Lime;
			this->KeyPreview = true;
			this->Name = L"Form1";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::Form1_KeyPress);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				System::Drawing::Font^ drawFont = gcnew System::Drawing::Font( "Microsoft Sans Serif",7 );
				SolidBrush^ drawBrush = gcnew SolidBrush( Color::Lime );
				StringFormat^ drawFormat = gcnew StringFormat;

				String^ drawString;
				float x,y;
				wchar_t c;
				int count;


				e->Graphics->Clear(Color::Black);
				c = 0;
				count = 0;
				for( x = 20 ; x < Form1::Width ; x += 51 )
					for( y = 5 ; y < Form1::Height - 50 ; y += 11 )					
					{
						drawString = "";
						drawString += count++;
						drawFormat->Alignment = StringAlignment::Far;
						e->Graphics->DrawString(drawString,drawFont,drawBrush,x,y,drawFormat);
						drawString = "";
						drawString += c++;
						drawFormat->Alignment = StringAlignment::Near;
						e->Graphics->DrawString(drawString,drawFont,drawBrush,x+4,y,drawFormat);
					}
				e->Graphics->Flush();
			 }


	private: System::Void Form1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
				 if(e->KeyChar == '\033')
					 exit(0);
			 }
	};
}

