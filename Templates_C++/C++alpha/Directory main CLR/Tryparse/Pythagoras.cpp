#include "Pythagoras.h"

System::Boolean UB20::Pythagoras::ValidateInput(System::String^ str) {
	double d;
	bool valid = Double::TryParse(str, d);
	valid = valid && d > 0;
	if (!valid) {
		hypothenuse->Text = L"ERROR";
		MessageBox::Show(L"Error");
	}
	return valid;
}

System::Void UB20::Pythagoras::calcPyth() {
	double a = Double::Parse(katheteA->Text);
	double b = Double::Parse(katheteB->Text);

	double c = Math::Sqrt(a*a + b*b);
	hypothenuse->Text = c.ToString();
}

System::Void UB20::Pythagoras::katheteA_Leave(System::Object^  sender, System::EventArgs^  e) {
	if (ValidateInput(katheteA->Text) )
		calcPyth();
	else
		katheteA->Focus();
}

System::Void UB20::Pythagoras::katheteB_Leave(System::Object^  sender, System::EventArgs^  e) {
	if (ValidateInput(katheteB->Text))
		calcPyth();
	else
		katheteB->Focus();
}

System::Void UB20::Pythagoras::Pythagoras_Load(System::Object^  sender, System::EventArgs^  e) {
	calcPyth();
}

System::Void UB20::Pythagoras::stop_Click(System::Object^  sender, System::EventArgs^  e) {
	Pythagoras::Close();
}