#include <iostream>
#include <functional>

double Fun2(double x)
{
    return x + 10;
}

template<typename T, typename F = std::function<T(T)>>
void Fun(T value, F f1 = [](T val) {
    return val * 10;
}) {
    std::cout << f1(value) << std::endl;
}

int main()
{
    Fun(10.5);

    Fun(10.5, [](auto val) {
        return val * 20;
    });

    Fun(10.5, Fun2);

    Fun(10.5, [](auto val) {
        return 20;
    });

    return 0;
}