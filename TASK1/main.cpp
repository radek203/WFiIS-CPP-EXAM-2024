#include <iostream>

class A
{
public:
	A(){std::cout<<__PRETTY_FUNCTION__<<"; ";}
	~A(){std::cout<<__PRETTY_FUNCTION__<<"; ";}
};

class B
{
public:
	B(){std::cout<<__PRETTY_FUNCTION__<<"; ";}
	~B(){std::cout<<__PRETTY_FUNCTION__<<"; ";}
};

class X: public A, public B
{
public:
	X(){std::cout<<__PRETTY_FUNCTION__<<"; ";}
	~X(){std::cout<<__PRETTY_FUNCTION__<<"; ";}
};

class Y: public X, public B
{
public:
	Y(){std::cout<<__PRETTY_FUNCTION__<<"; ";}
	~Y(){std::cout<<__PRETTY_FUNCTION__<<"; ";}
};

class Z: public Y
{
public:
	Z(){std::cout<<__PRETTY_FUNCTION__<<"\n";}
	~Z(){std::cout<<__PRETTY_FUNCTION__<<"; ";}
};

int main()
{
	Z z;
}