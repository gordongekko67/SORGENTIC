#include "TempCalc.h"
//####################################################################
//Methoden zur Berechnung und Überprüfung der eingabedaten
//####################################################################

System::Void UB20::TempCalc::ValidateAndCalculate() {
	if (ValidateData())
		Calculate();
}

System::Boolean UB20::TempCalc::ValidateData() {
	if (String::IsNullOrEmpty(text_in->Text) || text_in->Text == "-")
	{//Keine Fehlermeldung, falls Einabefeld während der Eingabe geleert wurde oder nur negatives Vorzeichen eingegeben wurde
	 //Rückgabewert false, damit keine Berechnung ausgelöst wird
		text_out->Text = "";
		return false;
	}
	else {
		double temp;
		bool valid = Double::TryParse(text_in->Text, temp);
		if (!valid) {
			MessageBox::Show("unerlaubtes Zahlenformat!");
			return false;
		}
		else
			return true;
	}
}

System::Void UB20::TempCalc::Calculate() {

	double Tin = Double::Parse(text_in->Text);		//für lesbarkeit kurze Variable definieren, da sie oöfter vorkommt
	double Tout;

	//Fälle einzeln durchgehen. Berechnung und Konsistenzprüfung zu unterschiedlich, als dass sich separate Funktionen lohnen würden. Daher alles in einer

	//1. Celsius -> Farenheit
	if (button_CtoF->Checked)
	{
		if (Tin < (-273.15)) {
			MessageBox::Show(L"Temperatur unterhalb absolutem Nullpunkt (-273.15°C)!");
			text_out->Text = "";
		}
		else
		{
			Tout = Tin * 9.0 / 5.0 + 32.0;
			text_out->Text = Tout.ToString();
		}
	}

	//2. Farenheit -> Celsius
	else if (button_FtoC->Checked)
	{
		if (Tin < (-459.67)) {
			MessageBox::Show(L"Temperatur unterhalb absolutem Nullpunkt (-459.67°F)!");
			text_out->Text = "";
		}
		else
		{
			Tout = (Tin - 32.0) * 5.0 / 9.0;
			text_out->Text = Tout.ToString();
		}
	}

	//3. Celsius -> Kelvin
	else if (button_CtoK->Checked)
	{
		if (Tin < (-273.15)) {
			MessageBox::Show(L"Temperatur unterhalb absolutem Nullpunkt (-273.15°C)!");
			text_out->Text = "";
		}
		else
		{
			Tout = Tin + 273.15;
			text_out->Text = Tout.ToString();
		}
	}

	//4. Kelvin -> Celsius
	else if (button_KtoC->Checked)
	{
		if (Tin < 0) {
			MessageBox::Show(L"Temperatur unterhalb absolutem Nullpunkt (0K)!");
			text_out->Text = "";
		}
		else
		{
			Tout = Tin - 273.15;
			text_out->Text = Tout.ToString();
		}
	}
}

System::Void UB20::TempCalc::ChangeScale() {
	if (button_CtoF->Checked) {
		TscaleIn->Text = "°C";
		TscaleOut->Text = "°F";
	}
	else if (button_FtoC->Checked) {
		TscaleIn->Text = "°F";
		TscaleOut->Text = "°C";
	}
	else if (button_CtoK->Checked) {
		TscaleIn->Text = "°C";
		TscaleOut->Text = "K";
	}
	else if (button_KtoC->Checked) {
		TscaleIn->Text = "K";
		TscaleOut->Text = "°C";
	}
}

//####################################################################
// Event Handler
//####################################################################
System::Void UB20::TempCalc::text_in_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	ValidateAndCalculate();
}

System::Void UB20::TempCalc::button_CtoF_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	ValidateAndCalculate();
	ChangeScale();
}

System::Void UB20::TempCalc::button_FtoC_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	ValidateAndCalculate();
	ChangeScale();
}

System::Void UB20::TempCalc::button_CtoK_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	ValidateAndCalculate();
	ChangeScale();
}

System::Void UB20::TempCalc::button_KtoC_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	ValidateAndCalculate();
	ChangeScale();
}

System::Void UB20::TempCalc::TempCalc_Load(System::Object^  sender, System::EventArgs^  e) {
	ValidateAndCalculate();
}





