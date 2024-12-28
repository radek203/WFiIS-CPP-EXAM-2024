#include <iostream>

class A : public std::exception {
private:
	std::string message;
public:
	explicit A(const std::string& msg) : message(msg) {}

	virtual const char* what() const noexcept override {
		return message.c_str();
	}
};

class B {

};

void willNotThrow() noexcept {
	std::cout << "This function is noexcept." << std::endl;
}

void fun() {
	throw std::bad_exception();
}

void funn() {
	throw A("A Error :D");
}

void funnn() {
	throw B();
}

void mayThrow() {
	throw std::runtime_error("An error occurred in mayThrow");
}

int main() {
	try {
		//fun();
		funn();
		//funnn();
		willNotThrow();
		mayThrow();
		willNotThrow();
	} catch (const std::runtime_error& e) {
		std::cerr << "Caught a runtime_error: " << e.what() << std::endl;
	} catch (const std::bad_exception& e) {
		std::cerr << "Caught a bad_exception: " << e.what() << std::endl;
	} catch (const A& a) {
		std::cerr << "Caught a A exception " << a.what() << std::endl;
	} catch (...) {
		std::cerr << "Caught an unknown exception" << std::endl;
	}

	return 0;
}