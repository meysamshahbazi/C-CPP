#include<iostream>
#include<deque>
using namespace std;

void print_back(deque<int> q) {
	cout << "Queue elements (back): ";
	while (!q.empty()) {
		cout << q.back() << " ";
		q.pop_back();
	}
	cout << "\n";
}

void print_front(deque<int> &q) {
	cout << "Queue elements (front): ";
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop_front();
	}
	cout << "\n";
}

bool is_palindrome(string str = "abba") {
	deque<char> dq;
	for (char c : str)		// Add chars
		dq.push_back(c);

	while (dq.size() > 1) {
		char f = dq.front();
		dq.pop_front();

		char b = dq.back();
		dq.pop_back();

		if (f != b)
			return false;
	}
	return true;
}

int main() {
	cout << boolalpha;   // print true as true
	cout << is_palindrome("abba") << "\n";	// true
	cout << is_palindrome("abcba") << "\n"; // true
	cout << is_palindrome("xyy") << "\n";   // false

	deque<int> q;
	q.push_back(20);	// q: 20
	q.push_back(30);	// q: 20 30
	q.push_back(40);	// q: 20 30 40
	q.push_front(10);	// q: 10 20 30 40
	q.push_back(50);	// q: 10 20 30 40 50
	q.push_front(0);	// q: 0 10 20 30 40 50

	deque<int> copy = q;

	print_back(q);		// 50 40 30 20 10 0
	print_front(q);		// 0 10 20 30 40 50
	print_front(q);		// NONE

	cout << copy.size() << "\n";	// 6
	cout << copy[1] << "\n";		// 10
	cout << copy.at(1) << "\n";		// 10
	//cout<<copy.at(1000)<<"\n";	// throws out_of_range exception

	copy.clear();
	cout << copy.size() << "\n";	// 0

	return 0;
}
