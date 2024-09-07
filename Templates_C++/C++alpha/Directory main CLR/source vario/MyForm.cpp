#include "MyForm.h"


int countLetters(System::String^ str) {
	int counter = 0;

	for (int i = 0; i < str->Length; i++) {
		//if ((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123)) {
		//	counter++;
		//}
		if (str[i].IsLetter(str, i)) {
			counter++;
		}
	}
	return counter;
}

//Button zum hinzufügen von textEingabe zu textAusgabe mit Leerzeichen hinten dran
System::Void WindowsProjekt::MyForm::button_Textanfuegen_Click(System::Object^sender, System::EventArgs^e) {
	
	//Hilfsvariable
	String^ text = textEingabe->Text;

	//Text aus der oberen Eingabe in textausgabe ausgeben
	//Neue zeile am Ende mit "\r\n" in Windows
	textAusgabe->Text += text + Environment::NewLine ;
	

	//Cursor wieder in die Eingabe setzen, damit der Benutzer gleich weiterschreiben kann
	textEingabe->Focus();

	//Aktualisiert automatisch durch klicken des ""Text hinzufügen" button das label Buchstabenanzahl
	//Durch Aufruf des Buchstabenzählen buttons
	WindowsProjekt::MyForm::button_Buchstabenzaehlen_Click(sender, e);
	//Alternativ Methode countletters mit übergebener textAusgabe aufrufen
	//label_Buchstabenzaehlen->Text = countLetters(textAusgabe->Text).ToString();
	
	//aktualisiert label_worterzaehelen
	WindowsProjekt::MyForm::button_Woerterzaehlen_Click(sender, e);
	
}

//Button zum zählen der einzelnen Zeichen in Eingabebox(textEingabe)
System::Void WindowsProjekt::MyForm::button_zeichenZaehlen_Click(System::Object^sender, System::EventArgs^e) {
		int anzahl = textEingabe->Text->Length;
		label_zeichenAnzahl->Text = anzahl.ToString();
}

//Ausgabetext leeren
System::Void  WindowsProjekt::MyForm::button_Leeren_Click(System::Object^  sender, System::EventArgs^  e) {
	//textAusgabe->Text = "";
	textAusgabe->Clear();
	//textAusgabe->Text = textAusgabe->Text->Empty;

	WindowsProjekt::MyForm::button_Buchstabenzaehlen_Click(sender, e);

	WindowsProjekt::MyForm::button_Woerterzaehlen_Click(sender, e);
}

//Wandelt Ausgabetext in Großbuchstaben um
System::Void WindowsProjekt::MyForm::button_Gross_Click(System::Object^  sender, System::EventArgs^  e) {
	textAusgabe->Text = textAusgabe->Text->ToUpper();
}
//Wandelt Ausgabetext in Kleinbuchstaben um
System::Void WindowsProjekt::MyForm::button_Klein_Click(System::Object^  sender, System::EventArgs^  e) {
	textAusgabe->Text = textAusgabe->Text->ToLower();
}
//Anzahl der Buchstaben ohne leertaste im Ausgabebox
System::Void WindowsProjekt::MyForm::button_Buchstabenzaehlen_Click(System::Object^  sender, System::EventArgs^  e) {
	//label_Buchstabenzaehlen->Text = textAusgabe->Text->Length.ToString();
	label_Buchstabenzaehlen->Text = countLetters(textAusgabe->Text).ToString();
}

//Befindet sich eine Zeichenfolge im textSuchen feld, welches sich auch in textAusgabe befindet
System::Void WindowsProjekt::MyForm::button_textSuchen_Click(System::Object^  sender, System::EventArgs^  e) {
	/*String^ suchText = textSuchen->Text;

	String^ ausgabeText = textAusgabe->Text;


	//Verwendung der Methode "Contains"
	bool istTextEnthalten = ausgabeText->Contains(suchText);

	//Auswertung der Prüfung
	if (istTextEnthalten == true)
	{
		//textBox_suchFeld->Text = "ist enthalten";

		textSuchen->BackColor = Color::Green;
	}
	else
	{
		textSuchen->BackColor = Color::Red;
		//textBox_suchFeld->Text = "ist nicht enthalten";
	}
	*/
	if (textAusgabe->Text->Contains(textSuchen->Text)) {
		textSuchen->BackColor = Color::Green;
	}
	else {
		textSuchen->BackColor = Color::Red;
	}

}



//Zählt die anzahl der Wörter und gibt das im label_Woerterzaehlen aus
System::Void WindowsProjekt::MyForm::button_Woerterzaehlen_Click(System::Object^  sender, System::EventArgs^  e) {
	array<wchar_t>^ name = {' ', '\r', '\n'};
	array<String^>^ splitfeld = textAusgabe->Text->Split(name , StringSplitOptions::RemoveEmptyEntries);
	
	label_Woerterzaehlen->Text = splitfeld->Length.ToString();

}