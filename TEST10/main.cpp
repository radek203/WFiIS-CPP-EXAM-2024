#include <iostream>

//inline zostanie bezposrednio wtracona do kodu przez komilator
static inline void fun() {
	std::cout << "Test" << std::endl;
}

void funn() {
	int x = 10;

	if (x == 10) {
		//pomijamy kod skaczac do...
		goto label1;
	}

	std::cout << "TEST GOTO1" << std::endl;

label1:
	std::cout << "TEST GOTO2" << std::endl;
}

class Test {
	const char *X;
public:
	Test(const char *_X) : X(_X) {

	}
};

//Jezeli dziedziczmy domyslnie jest private, (dla struct public)
//Jezeli tworzylibysmy tablice (tej klasy) za pomoca new musi istniec konstruktor domyslny
class Test2 {
	//w teorii zmienne private i protected powinno sie pisac z _ np. _name, a nazwy funkcji z wielkiej np. void Licz()
	std::string name;
public:
	//Jak wywolamy to recznie to wywola sie kod w srodku, ale nie niszczy obiektu
	~Test2() {

	}

	//Jezeli dziedziczymy najpierw wywoluje sie konstruktor podstawowy potem klasy pochodnej + trzeba umieszczac odwolanie do konstrukowa podstawowego
	//Umieszczamy konstruktory ktore znajduja sie tylko 1 poziom wyzej w hierarchi!!!
	//Konstruktory nie musza byc public!
	Test2(const std::string &_name) : name(_name) {

	}

	//jak definiujemy wewnatrz klasy to sa automatycznie inline
	void fun() {

	}

	//protected: - jest przy dziedziczeniu zeby dziecko mialo dostep do skladowych rodzica
};

//W struct wszystkie zmienne sa publiczne domyslnie!
struct Test3 {
	int b;
	std::string t;
};

class Test4 {
public:
	int a;
	int b;
};

class Test5 {
public:
	//tylko max. 2 bity bedzie zajmowac
	unsigned int val : 2;
};

//Informujemy ze zmienna jest w innym pliku .cpp zeby ja zaczytac (nie trzeba .h)
extern int globalVariable;

int g = 2137;

//Zawsze odczytywany z pamieci
volatile int h = 1999;

//referencja
void fun1(double &d) {
	d = 20;
}

//move
void fun2(double &&d2) {
	d2 = 10;
}

void fun3(float);
void fun3(char);
//Nie mozemy zrobic samego inta, bo nie bedzie wiedzialo ktora wybrac czy z float czy z int
void fun3(int, float = 0);

//Musi byc liczba kolumn
void funnn1(float t[5][2]) {
	std::cout << "TEST1 ";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 2; j++) {
			std::cout << t[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

//Musi byc liczba kolumn
void funnn2(float t[][2]) {
	std::cout << "TEST2 ";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 2; j++) {
			std::cout << t[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {

	std::cout << "TEST" << std::endl;
	Test t1 = Test("X");
	fun();
	funn();

	int i = 10;
	switch (i) {
		case 3:
			std::cout << "TEST SWITCH1" << std::endl;
			break;
		case 10:
			std::cout << "TEST SWITCH2" << std::endl;
			//Musi byc break, inaczej default tez spelnia warunek i sie wykona
			break;
		default:
			std::cout << "TEST SWITCH3" << std::endl;
	}

	do {
		i++;
		std::cout << "TEST DO-WHILE " << i << std::endl;
	} while (i < 15);

	globalVariable++;
	std::cout << "TEST EXTERN " << globalVariable << std::endl;

	//Pozwala na deklaracje jakis wiekszych znakow
	wchar_t wideChar = L'Ą'; // Uzycie prefiksu L dla szerokich znakow

	// Wydruk szerokiego znaku
	//std::cout << "Szeroki znak: " << wideChar << std::endl;
	std::wcout << L"Szeroki znak: " << wideChar;

	//Mozna zapisac w postaci 8 albo 16
	int k = 0x0A;
	int l = 073;
	std::cout << std::endl << "TEST 16: " << k << " TEST 8: " << l << std::endl;

	//Mozna przyslonic, ale i odczytac z zakresu globalnego
	int g = 2000;
	std::cout << "G LOCAL " << g << " G GLOBAL " << ::g << std::endl;

	std::cout << "Volatile test " << h << std::endl;

	for (int p = 0, o = 0; p < 10, o < 6; p++, o = p/2) {
		std::cout << "TEST FOR " << o << " " << p << std::endl;
	}

	double dd = 2;
	fun1(dd);
	std::cout << "Wartosc " << dd << std::endl;
	fun2(std::move(dd));
	std::cout << "Wartosc " << dd << std::endl;

	int t4[4] = {2, 4, 6, 8};
	int t5[4] = {2, 4}; //dwa ostatnie elementy sa 0
	int t6[] = {2, 4, 6, 8};

	char tekst[] = "XD\0D";
	char tekst2[5] = "XDDD";
	char *tekst3 = "XDDD";
	std::cout << "TEST TEKST " << tekst << " " << tekst2 << " " << tekst3 << std::endl;

	//Mozna przekazac tablice ktora ma wiecej elementow, ale jak przekazemy taka co ma mniej to beda smieci...
	float t[5][2] = {};
	funnn1(t);
	funnn2(t);

	int ttt1 = 5;
	const int *ttt1p = &ttt1; //obiekt nie moze byc zmieniony przez ten wskaznik
	//*ttt1p = 20;
	int *const ttt1pp  = &ttt1; //staly wskaznik - nie mozna zmienic obiektu na jaki wskazuje
	*ttt1pp = 20;

	void *w1;
	w1 = &ttt1;
	std::cout << "TEST VOID " << *static_cast<int*>(w1) << std::endl;

	int *i2 = new int(6);
	std::cout << "TEST NEW " << *i2 << std::endl;
	delete i2;

	//Parametry po kolei sa przypisywane jak konstruktor
	Test3 tests[3] = {{90, "XD"}, 20, "TEST"};
	Test3 test3 = {20, "XD"};
	//Test3 test4 = 20;

	//Z klasami tez tak mozna, lecz musza byc wszystkie zmienne publiczne!
	Test4 test4 = {0, 0};

	//Jak nie ma konstruktora to mozna za pomoca listy inicializacyjnej (ale zmienne publiczne musza byc)
	//Test5 test5(20);
	Test5 test5 = {19};
	std::cout << "TEST UNSIGNED " << test5.val << std::endl;

	return 0;
}