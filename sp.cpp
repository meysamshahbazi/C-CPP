

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() 
{
    int num {10};

    cout << "Value of num is: " << num << endl;		
    cout << "sizeof of num is: " << sizeof num << endl; 	
    cout << "Address of num is: " << &num << endl;	
    
    int * p;

    cout << "\nValue of p is: " << p << endl;   // garbage
    cout << "Address of p is: " << &p << endl;
    cout << "sizeof of p is: " << sizeof p<< endl;

    p = nullptr;
    cout << "\nValue of p is: " << p << endl;

    
    int *p1 {nullptr};
    double *p2 {nullptr};
    unsigned long long *p3 {nullptr};
    vector<string> *p4{nullptr};
    string *p5 {nullptr};

    cout << "\nsizeof p1 is: " << sizeof p1 << endl;
    cout << "sizeof p2 is: " << sizeof p2 << endl;
    cout << "sizeof p3 is: " << sizeof p3 << endl;
    cout << "sizeof p4 is: " << sizeof p4 << endl;
    cout << "sizeof p5 is: " << sizeof p5 << endl;

    int score {10};
    double high_temp {100.7};
    int *score_ptr {nullptr};

    score_ptr = &score;

    cout << "\nValue of score is: " << score << endl;
    cout << "Address of score is: " << &score << endl;
    cout << "Value of score_ptr is: " << score_ptr << endl;
    cout << "Content of score_ptr is: " << *score_ptr << endl;

    // score_ptr = &high_temp;

    cout << "\n------------------------------" << endl;

    *score_ptr = 200;

    cout << "Content of score_ptr is: " << *score_ptr << endl;
    cout << "Value of score is: " << score << endl;
    cout << "\n------------------------------" << endl;
    // delete high_temp;
    // double high_temp {100.7};

    double low_temp {37.4};

    double *temp_ptr {&high_temp};
    cout << *temp_ptr << endl;  
    temp_ptr = &low_temp;
    cout << *temp_ptr << endl;  

    cout << "\n------------------------------" << endl;

    string name {"Ferferi"};
    string *name_ptr {&name};

    cout << *name_ptr<<endl;
    name = "Jame";

    cout << *name_ptr<<endl;
    cout << "\n------------------------------" << endl;

    vector<string> stooges {"Larry","AA","BB"};
    vector<string> *vec_ptr {&stooges};

    cout << "first: "<<(*vec_ptr).at(0)<<endl;

    cout<< "print all: ";
    for (auto s : *vec_ptr)
        cout<<s<<" ";

    cout<<endl;

    return 0;


}
