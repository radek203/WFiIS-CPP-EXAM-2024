#include <iostream>
#include <set>
#include <iterator>

using namespace std;

struct Person {
	std::string _surname;
	std::string _name;

	Person(const std::string &second, const std::string &first) : _surname(first), _name(second) {

	}
};

std::ostream &operator<<(std::ostream& os, const Person &pers) {
	os << pers._surname << " " << pers._name;
	return os;
}

bool operator<(const Person & p1, const Person & p2) {
	return p1._surname < p2._surname || p1._name < p2._name;
}


int main ()
{
	typedef	std::set<Person>  kontener_typ;
	kontener_typ c;
	c.insert(Person("Nowak","Jan"));
	c.insert(Person("Nowak","Adam"));
	c.insert(Person("Kowalski","Jan"));
	c.insert(Person("Nowak","Adam"));
	c.insert(Person("Iksinski","Adam"));
	std::copy (c.begin(), c.end(), std::ostream_iterator<Person>(std::cout, " "));
}

/*
Adam Iksinski Jan Kowalski Adam Nowak Jan Nowak
*/