#include <iostream>
#include <vector>
using namespace std;

int main() {

	int arr[] { 2, 3, 5, 7 };

	auto [a1, b1, c1, d1] = arr;

	cout<<c1<<"\n";			// 5
	c1 += 20;
	cout<<arr[2]<<"\n";		// 5

	auto &[a2, b2, c2, d2] = arr;	// must be 4

	cout<<c2<<"\n";			// 5
	c2 = 20;
	cout<<arr[2]<<"\n";		// 20

	return 0;
}
