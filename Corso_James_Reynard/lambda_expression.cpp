#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> vec;
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(5);




	// Pass a lambda expression
	auto odd_it = find_if(std::begin(vec), std::end(vec),[]
							(int n) { return (n % 2 == 1); }
	);

	// odd_it will be an iterator to the first odd element (if there is one)
	if (odd_it != std::end(vec))
		cout << "First odd element is: " << *odd_it << endl;	





	sort(vec.end(), vec.begin());

	for (auto i : vec)	{

		std::cout << i << std::endl;
	}




	return 0;
}



