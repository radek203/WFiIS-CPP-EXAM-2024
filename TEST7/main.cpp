#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
#include <memory>

int add(int a, int b) {
    return a + b;
}

std::tuple<double, char, std::string> get_student(int id) {
    switch (id) {
        case 0: return {3.8, 'A', "Lisa Simpson"};
        case 1: return {2.9, 'C', "Milhouse Van Houten"};
        case 2: return {1.7, 'D', "Ralph Wiggum"};
        case 3: return {0.6, 'F', "Bart Simpson"};
        default: return {};
    }
}

void inc(int &n) {
    n++;
}

void inc(const int &n) {
    std::cout << std::endl << n;
}

template<typename T>
class Cloud {
    std::vector<std::pair<T, T>> points = {};
public:
    Cloud(std::initializer_list<std::pair<T, T>> l) : points(l) {

    }

    void print() {
        for (auto point : points) {
            std::cout << " X: " << point.first << " Y: " << point.second << std::endl;
        }
    }
};

class MyClass {
public:
    MyClass() {
        std::cout << "Konstruktor MyClass" << std::endl;
    }
    ~MyClass() {
        std::cout << "Destruktor MyClass" << std::endl;
    }
    void display() {
        std::cout << "Metoda display MyClass" << std::endl;
    }
};

int main() {

    std::vector<int> vec = {10, 3, 6, 11, 2};

    std::array<int, 3> a = {1, 2, 3};

    std::sort(vec.begin(), vec.end(), std::less<>());

    for (auto i : vec) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl << std::less()(5, 5);
    std::cout << std::endl << std::less_equal<>{}(5, 5);
    std::cout << std::endl << std::greater<double>{}(5, 5.6);
    std::cout << std::endl;

    using namespace std::placeholders;  // for _1, _2, _3...
    std::vector<int> v{ 1, 2, 3, 4, 4, 3, 7, 8, 9, 10 };

    int num_items3 = std::count_if(v.begin(), v.end(), std::bind(std::greater<int>(), _1, 8));
    std::cout << "number bigger then 8: " << num_items3 << '\n';

    int num_items4 = std::count_if(v.begin(), v.end(), std::bind(std::less<int>(), _1, 8));
    std::cout << "number less then 8: " << num_items4 << '\n';

    auto fun = [](int a, int b) {
        return a + b;
    };

    auto f = std::bind(add, 20, std::placeholders::_1);
    std::cout << std::endl << f(10);


    std::pair<int, std::string> pair(5, "Jan Kowalski");
    std::cout << std::endl << pair.first << " " << pair.second;

    auto student = get_student(2);
    std::cout << std::endl << std::get<0>(student) << " " << std::get<1>(student) << " " << std::get<2>(student);

    double avg;
    char grade;
    std::string name;
    std::tie(avg, grade, name) = student;
    std::cout << std::endl << avg << " " << grade << " " << name;

    auto [avg1, grade1, name1] = get_student(3);
    std::cout << std::endl << avg1 << " " << grade1 << " " << name1;

    auto t1 = std::make_tuple(10, "XD", "XDD");

    int x = 20;
    inc(std::ref(x));
    std::cout << std::endl << x;
    inc(std::cref(x));


    std::cout << std::endl;
    std::pair<double, double> p1(1.2, 3.4);
    std::pair<double, double> p2(5.2, 2.1);
    std::pair<double, double> p3(3.7, 8.3);

    Cloud c1({p1, p2, p3});
    c1.print();


    // Tworzymy unikalny wskaźnik do obiektu MyClass
    std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>();

    // Używamy obiektu poprzez unikalny wskaźnik
    ptr->display();

    auto v3 = std::make_unique<int[]>(5);

    std::cout << " TAB: " << v3.get()[0] << " " << v3[1] << " " <<  v3[2] << " " << v3[3] << " " << v3[4] << std::endl;

    // Tworzymy współdzielony wskaźnik do obiektu MyClass
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();

    {
        // Tworzymy kolejny współdzielony wskaźnik do tego samego obiektu
        std::shared_ptr<MyClass> ptr2 = ptr1;

        // Używamy obiektu poprzez jeden z współdzielonych wskaźników
        ptr2->display();

        std::cout << "Liczba referencji ptr1: " << ptr1.use_count() << std::endl;
        std::cout << "Liczba referencji ptr2: " << ptr2.use_count() << std::endl;

        ptr2 = nullptr;

        std::cout << "Liczba referencji ptr1: " << ptr1.use_count() << std::endl;
        std::cout << "Liczba referencji ptr2: " << ptr2.use_count() << std::endl;

        ptr2.reset(new MyClass);

        std::cout << "Liczba referencji ptr1: " << ptr1.use_count() << std::endl;
        std::cout << "Liczba referencji ptr2: " << ptr2.use_count() << std::endl;
    }

    // Po wyjściu z zakresu blokowego, ptr2 zostaje zniszczony, ale obiekt MyClass nie, bo ptr1 nadal istnieje
    std::cout << "Liczba referencji po zniszczeniu ptr2: " << ptr1.use_count() << std::endl;

    // Po zakończeniu funkcji, ptr1 zostanie automatycznie zniszczony, a obiekt MyClass zwolniony
    // Po zakończeniu funkcji, ptr zostanie automatycznie zniszczony, a obiekt MyClass zwolniony

    return 0;
}