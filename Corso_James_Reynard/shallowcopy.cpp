#include <iostream>
#include <string>

class String
{

    char *data;
    int size;

public:
    String(const std::string &s) : size(s.size())
    {

		std::cout << "calling copy constructor" <<  std::endl;
        data = new char[size];

        for (int i = 0; i < size; i++)
        {
            data[i] = s[i];
        }
    }

    
	// Synthesized member functions
	// String(const String& arg) : size(arg.size), data(arg.data) {}
	// String& operator =(const String& arg) { size = arg.size; data = arg.data; return *this; }

	// Destructor
	~String() {
		std::cout << "Calling destructor" << std::endl;
		 
		delete [] data;                     // Release the heap memory for the data
	}
	
	int length() {
		return size;
	}

};


int main()
{
    String str("1");
	
	String str2("Two");
	String str3(str2);
	std::cout << "Str2 size: " << str2.length() << std::endl;
	std::cout << "Str3 size: " << str3.length() << std::endl;
	
	std::cout << "Str size: " << str.length() << std::endl;
    
    return 0;
}