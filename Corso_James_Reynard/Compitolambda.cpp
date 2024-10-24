#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void function_print_vector(const std::vector<int> &v)
{
    for (auto i : v)
    {
        std::cout << i << std::endl;
    }
}

int main()
{
    std::vector<int> v;
    v.push_back(5);
    v.push_back(6);
    v.push_back(34);
    v.push_back(67);
    function_print_vector(v);

    sort(begin(v), end(v));
    function_print_vector(v);
    
    // To sort in reverse order, we invert the < operator
	sort(begin(v), end(v),[](int a, int b) { return a > b; });
    function_print_vector(v);

    return 0;
}