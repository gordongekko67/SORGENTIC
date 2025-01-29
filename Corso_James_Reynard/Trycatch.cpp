#include <iostream>
#include <string>
#include <vector>


// Function which throws an unhandled exception
void func(const std::vector<int>& vec) {
	std::cout << vec.at(2) << std::endl;                             // Throws an exception
}




int main() {
    

    std::vector<int> vec;
	
	// Catch any exceptions thrown by func()
	try {
		func(vec);
	}
	// Handle the exception
	catch (const std::exception& e) {
		std::cout << "std::exception catch block\n";
		std::cout << "Exception caught: " << e.what() << std::endl;  // Print out a description of the exception
	}








    return 0;
}