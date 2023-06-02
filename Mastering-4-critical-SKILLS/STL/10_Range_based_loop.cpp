#include<iostream>
#include<deque>
using namespace std;

void what_is_auto()
{
	int x1 = 10;
	auto x2 = 10;			// c++ deduces int
	auto x3 = 10.0;			// double
	auto x4 = "mostafa";	// string
	// There are more details. This is good for now
	// Auto: No conversions / clean code
}

int main() {
	what_is_auto();

	int arr[] { 1, 2, 3 };

	for (auto val : arr)
		cout << val << " ";		// 1 2 3
	cout << "\n";

	deque<int> q { 1, 2, 3, 4, 5 };

	for (const auto &val : q)
		cout << val << " ";		// 1 2 3 4 5
	cout << "\n";

	for (auto val : { 1, 2, 3, 4, 5 })
		cout << val << " ";		// 1 2 3 4 5
	cout << "\n";

	for (auto val : "hello")
		cout << val;		// hello
	cout << "\n";

	return 0;
}
