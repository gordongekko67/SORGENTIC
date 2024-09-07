#include "MyForm.h"

System::Void UB20_2::MyForm::label_Datum_Click(System::Object^  sender, System::EventArgs^  e) {


	DateTime weltmeister = DateTime(2014, 7, 13);
	TimeSpan vergangen = TimeSpan(DateTime::Today.Ticks - weltmeister.Ticks);
	
	DateTime zeit2 = DateTime(2017, 3, 17);


	Console::WriteLine("{0:d}", zeit2);
	Console::WriteLine("{0:t}", weltmeister);
	
	String^ str = " wurde Deutschland Weltmeister";

	label_Datum->Text = weltmeister.ToString() + str + "\r\n Seit dem sind " + vergangen.ToString() + " Tage vergangen.";

textBox1->Text = "0";
			textBox2->Text = "0";
			textBox3->Text = "0";
			DateTime localDate = System::DateTime::Now;
			label1->Text = ("{0:t}", localDate).ToString();
			

}

System::Void UB20_2::MyForm::label_Zufall_Click(System::Object^  sender, System::EventArgs^  e) {
	//Zufallszahlgenerator
	Random ^zufallszahlen = gcnew Random();

	int zahl = zufallszahlen->Next(101);

	label_Zufall->Text = zahl.ToString();
	


}

System::Void UB20_2::MyForm::neuToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ dateiname = "Unbekannter.txt";
	this->Text = "Texteditor - " + dateiname;


	textBox_Eingabe->Text = "";
	label_Datum->Text = "";
	label_Zufall->Text = "";
	
}
System::Void UB20_2::MyForm::beendenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
	MyForm::Close();
}
System::Void UB20_2::MyForm::ausschneidenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
	textBox_Eingabe->Cut();
}
 System::Void UB20_2::MyForm::kopierenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
	 textBox_Eingabe->Copy();
 }
 System::Void UB20_2::MyForm::einfügenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
	 textBox_Eingabe->Paste();
 }