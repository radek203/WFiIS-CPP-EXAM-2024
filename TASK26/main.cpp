#include <iostream>

struct A {

};

template<typename T>
struct B: A {
	T v = T();

	B() {
		std::cout << "default" << std::endl;
	}

	B (const B& b) : v(b.v) {
		std::cout << "Copy " << typeid(B<T>).name() << "()\n";
	}
};

int main(){
	typedef B<A> B_A;
	using TypeName = B<B_A>;

	/*
	 * Ponieważ konstrukcje są zagnieżdżone w wywołaniach funkcji, każda wywołana instancja jest tworzona tymczasowo
	 * i natychmiast przekazywana dalej do następnej warstwy wywołań. W wyniku tego nigdy nie dochodzi do kopiowania,
	 * a jedynie do tworzenia nowych obiektów za pomocą domyślnego konstruktora - najpierw dla B<A> potem dla B<B<A>>.
	 */

	TypeName a = TypeName(TypeName(TypeName(TypeName(TypeName()))));

	/*
	 * Tutaj tylko kopiujemy B<B<A>> - czyli wywolujemy dla B<B<A>> najpierw B<A> potem B<B<A>>
	 */

	TypeName b {a};
}

/*
default
default
Copy 1BI1AE()
Copy 1BIS_I1AEE()
*/