#include <iostream>
#include <tuple>
using namespace std;

int main() {

	tuple<char, int, string> t = make_tuple('c', 10, "mostafa");
	auto &[a, b, c] = t;

	// Direct initialization
	auto [m, n, q] = tuple('a', 123, true);


	return 0;
}
