#include "MyForm.h"

System::Void Zeichnen::MyForm::panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	//ALs erstes brauchen wir ein Panel oder ein Picturebox und erzeugen ein Objekt von Graphics
	//Dieses Objekt von Graphics muss erzeugt werden mit CreateGraphics()
	Graphics^ zeichenBereich = panel1->CreateGraphics();
	/*Stifte oder Pinsel zum zeichnen von linien, Kreise etc.*/

	//Schwarzerstift mit schwarzer schriftfarbe
	Pen^ bunterStift = gcnew Pen(Color::Black);
	Pen^ blauerStift = gcnew Pen(Color::Blue);
	
	bunterStift->Color = Color::Red;
	
	//Pinsel mit
	Brush^ pinsel = gcnew SolidBrush(Color::Maroon);
	

	zeichenBereich->TranslateTransform(panel1->Width / 2, panel1->Height / 2);

	Point p1 = Point(0, -200);
	Point p2 = Point(0, 180);
	Point p3 = Point(180, 0);
	Point p4 = Point(-180, 0);

	System::Drawing::Font^ schrift = gcnew System::Drawing::Font("Times New Roman", 15);

	zeichenBereich->DrawLine(bunterStift,p1,p2);
	zeichenBereich->DrawLine(bunterStift, p3,p4);
	
	zeichenBereich->DrawString("3", this->Font, pinsel, p1);
	zeichenBereich->DrawString("3", this->Font, pinsel, p2);
	zeichenBereich->DrawString("-3", this->Font, pinsel, p3);
	zeichenBereich->DrawString("-3", this->Font, pinsel, p4);
	
	/*Zeichnet einen Kreis*/
	zeichenBereich->DrawEllipse(bunterStift, 0, 0, 80, 50);
	
}