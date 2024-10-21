struct Result {
    int a;
    double b;
};

Result returnMultipleValues() {
    return {10, 20.5};
}

int main() {
    Result res = returnMultipleValues();
    // Ora res.a = 10, res.b = 20.5
}
