#include <iostream>
#include <tuple>

struct Result
{
    int a;
    double b;
    std::string stringa;
};

std::tuple<int, double, std::string> returnMultipleValues() {
    return std::make_tuple(10, 20.5, "Hello");
}



Result returnMultipleValues()
{
    return {10, 20.5, "questa stringa"};
}

int main(int argc, const char *argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";

    Result res = returnMultipleValues();
    // Ora res.a = 10, res.b = 20.5

    std::cout << res.a << "  " << res.b << "   " << res.stringa << std::endl;



    auto [a, b, c] = returnMultipleValues();


    return 0;
}