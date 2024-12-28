#include <iostream>
#include <set>
#include <iterator>

struct Comparator {
	virtual bool operator() (const std::string &s1, const std::string &s2) const {
		return true;
	}
};

struct Normal : Comparator {

	bool operator() (const std::string &s1, const std::string &s2) const override {
		return s1 < s2;
	}

} normal_order;

struct Reverse : Comparator {

	bool operator() (const std::string &s1, const std::string &s2) const override {
		return s2 < s1;
	}

} reverse_order;

int main() {
	typedef std::set<std::string, Comparator&> kontener_typ;

	kontener_typ c(normal_order);
	c.insert("abc");
	c.insert("def");
	c.insert("ghi");
	c.insert("jkl");
	copy(c.begin(), c.end(), std::ostream_iterator<std::string>(std::cout, ", "));

	kontener_typ d(reverse_order);
	d.insert("abc");
	d.insert("def");
	d.insert("ghi");
	d.insert("jkl");
	copy(d.begin(), d.end(), std::ostream_iterator<std::string>(std::cout, ", "));
}
/*
abc, def, ghi, jkl, jkl, ghi, def, abc,
*/