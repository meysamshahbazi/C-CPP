#include <iostream>
#include <sstream>
using namespace std;

int main() {

	string input_str = "I am mostafa\nYour instructor for this course";

	for (auto[iss, line] = pair(istringstream(input_str), string {}); getline(iss, line); ) {
	    cout<<line<<"\n";
	}

/*
I am mostafa
Your instructor for this course
 */

	return 0;
}
