#include <iostream>
#include <sstream>
using namespace std;

struct MyArray {
	int salaries[3];
};

int main() {
	int arr[] {1, 2, 3};
	// CE: invalid conversion from ‘int*’ to ‘int’
	//int sal[4] {arr};

	auto salPtr {arr};	// this is pointer

	MyArray myarr {3, 4, 5};
	auto [actuall_arr] = myarr;	// NOT a pointer
	assert(typeid(actuall_arr) == typeid(myarr.salaries));

	return 0;
}
