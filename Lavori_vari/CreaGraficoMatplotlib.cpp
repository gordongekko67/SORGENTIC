#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

int main() {
    std::vector<double> x = {1, 2, 3, 4, 5};
    std::vector<double> y = {10, 12, 15, 13, 17};

    plt::plot(x, y);
    plt::title("Stock Prices");
    plt::show();

    return 0;
}
