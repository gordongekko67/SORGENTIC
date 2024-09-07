#include "MyForm.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

int main(array<String^>^args) {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	Provagrafico::MyForm^ form = gcnew Provagrafico::MyForm;

	Application::Run(form);
	
	


}