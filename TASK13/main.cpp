#include <iostream>
#include <deque>

template<typename T = int, template<typename U, typename Alloc> typename StorageType = std::deque>
struct fifo {
	typedef StorageType<T, std::allocator<T>> storage_type;

	storage_type storage = {};

	fifo() {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

	void push(T val) {
		storage.push_back(val);
	}

	T get() {
		T elem = storage.front();
		storage.pop_front();
		return elem;
	}

	int size() {
		return storage.size();
	}

	typename storage_type::const_iterator begin() const {
		return storage.begin();
	}

	typename storage_type::const_iterator end() const {
		return storage.end();
	}

};

int main(){
	fifo<> ft;
	for(int i: {0,1,2,3,4})
		ft.push(i);

	fifo<int, std::deque> f = ft;

	std::cout << f.get();
	std::cout << f.size();

	for(fifo<>::storage_type::const_iterator i = f.begin(); i != f.end(); ++i)
		std::cout << *i << ",";
}
/*
  fifo<T, StorageType>::fifo() [with T = int, StorageType = std::deque]
  0
  4
  1,2,3,4,
*/