#include <iostream>
#include <vector>
using namespace std;

struct Employee {
	string name;
	int salary;
};

int main() {
	Employee emp { "Mostafa", 20 };

	// bind by value
	auto [str1, sal1] = emp;

	// bind by reference
	auto &[str2, sal2] = emp;

	sal2 += 30;	// emp.salary now 50

	const auto &[str3, sal3] = emp;

	return 0;
}
