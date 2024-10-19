#include <iostream>
#include <string>
#include <vector>

std::string isodd(int x)
{
    std::string isodd = "false";
    if (x % 2 == 0)
    {
        isodd = "true";
    }
    return isodd;
}

void isoddvec(std::vector<int> v1)
{

    for (auto i : v1)
    {

        std::string isodd = "false";
        if ((i % 2) == 0)
        {
            isodd = "true";
        }

        std::cout << i << "    " <<   isodd << std::endl;
    }
}

void isoddvec2(std::vector<int> v1, int div)
{

    for (auto i : v1)
    {

        std::string isodd = "false";
        if ((i % div) == 0)
        {
            isodd = "true";
        }

        std::cout << "valore " << i  << " divisibile per    " << div << "  " <<   isodd << std::endl;
    }
}





int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i <= num; i++)
    {

        std ::cout << i << "  " << isodd(i) << std::endl;
    }

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(36);

    for (auto i : v)
    {
        std ::cout << i << "  " << isodd(i) << std::endl;
    }

    isoddvec(v);


    isoddvec2(v, 3);
    isoddvec2(v, 4);

    return 0;
}
