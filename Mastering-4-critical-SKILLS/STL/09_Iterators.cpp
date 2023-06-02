#include<iostream>
#include<deque>

#include<vector>
#include<set>
#include<map>

using namespace std;



void print_front(deque<int> &q) {
	cout << "Queue elements (front): ";

	deque<int>::iterator it = q.begin();

	while(it != q.end()) {
		cout<<*it<<" ";
		++it;
	}

	cout << "\n";
}


void print_back1(deque<int> &q) {
	cout << "Queue elements (back): ";

	// reverse iterator
	deque<int>::reverse_iterator it = q.rbegin();

	while(it != q.rend()) {
		cout<<*it<<" ";
		++it;
	}
	cout << "\n";
}

void print_back2(deque<int> &q) {
	cout << "Queue elements (back): ";

	for(auto it = q.rbegin(); it != q.rend(); ++it)
		cout<<*it<<" ";
	cout << "\n";
}

int count_lowers(const string & str)
{
	//string::iterator it;   // U can use

	int cnt = 0;
	for(auto it = str.begin(); it != str.end(); ++it)
	{
		char ch = *it;
		cnt += (islower(ch) > 0);
	}
	return cnt;
}

void lets_play() {
	deque<int> q {1, 2, 3, 4, 5};

	auto it = q.begin() + 3;	// FORTH element position
	cout<<*it<<"\n";		// 4

	cout<<*(it--)<<"\n";	// 4 then move to 3rd position
	cout<<*it<<"\n";		// 3

	cout<<*(--it)<<"\n";	// 2
	cout<<*it<<"\n";		// 2 Now on 2nd

	cout<<*(it + 3)<<"\n";	// 5th position
	it += 3;
	cout<<*it<<"\n";		// 2 Now on 5th position


	// reset all to 10
	for(auto it = q.begin(); it != q.end(); ++it)
		*it = 10;
}

void print_front_const(deque<int> &q) {
	cout << "Queue elements (front): ";

	deque<int>::const_iterator it = q.cbegin();

	while(it != q.cend()) {
		cout<<*it<<" ";
		//*it = 10;		// can't - CONST
		++it;
	}

	cout << "\n";
}

void more() {
	vector<int>::iterator it1;

	set<string>::iterator it2;

	// Each item is: pair<int, string>
	map<int, string>::iterator it3;
}

int main() {
	deque<int> q {1, 2, 3, 4, 5};

	print_front(q);		// 1 2 3 4 5
	print_back1(q);		// 5 4 3 2 1

	lets_play();

	//cout<<count_lowers("aAbc\n");	// 3

	return 0;
}
