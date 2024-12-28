#include <iostream>
#include <string>

struct big {
    int t[8];
    virtual ~big() = default;
};




/*
template <typename T, unsigned N = sizeof(std::string)>
struct obj_ho1der {
  // Jezeli (sizeof(T) <= N) to type = scoped<T> w przeciwnym razie type = on_heap<T>
  using type = typename std::conditional<(sizeof(T) <= N), scoped<T>, on_heap<T>>::type;
};
*/

template <typename T>
struct on_heap {

    on_heap() : p(new T)
    {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }
    ~on_heap()
    {
        delete p;
    }

    T &operator*()
    {
        return *p;
    }
    T *operator->()
    {
        return p;
    }
    on_heap(const on_heap &) = delete;
    on_heap &operator=(const on_heap &) = delete;

private:
    T *p;
};


template <typename T>
struct scoped {

    scoped()
    {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }

    T &operator*()
    {
        return x;
    }
    T *operator->()
    {
        return &x;
    }
    scoped(const scoped &) = delete;
    scoped &operator=(const scoped &) = delete;

private:
    T x;
};


// Jezeli (sizeof(T) <= N) to type = scoped<T> w przeciwnym razie type = on_heap<T>
template <typename T, unsigned N = sizeof(std::string)>
using holder_type = typename std::conditional<(sizeof(T) <= N), scoped<T>, on_heap<T>>::type;



int main()
{
    holder_type<int> a;
    holder_type<int, 2> aa;
    holder_type<big> b;
    holder_type<big, 64> bb;

    *aa = *a = 5;
}
