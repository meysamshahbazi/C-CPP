#include<iostream>
#include<tuple> // tie() and tuple
using namespace std;

int main() {
	tuple<char, int, string> t1;
	t1 = make_tuple('c', 10, "mostafa");

	// Get<position>   c, 10
	cout << get < 0 > (t1) << " " << get < 1 > (t1) << "\n";

	// Set<position>
	get < 0 > (t1) = 'd';

	cout<< (t1 <= t1) <<"\n";	// we can compare tuples

	char ch;
	int val;
	string name;

	// tie unpack the tuple values into separate variables
	tie(ch, val, name) = t1;
	cout<<name<<"\n";

    // Concatenating 2 tuples to return a new tuple
    auto t2 = tuple_cat(t1, make_tuple(10.6));

    // C++17 some nicer syntax. Don't try unless C++17 compilation
    int c, d;
    //auto  [c, d] = std::make_tuple(4, 5);

	return 0;
}
