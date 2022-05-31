
#include <iostream>
#include <vector>
#include <memory>

#include "Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Savings_Account.h"

using namespace std;


class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    int get_data() const {return data; }
    ~Test() {std::cout << "Test destructor (" << data << ")" << std::endl; }
};



int main( int argc, const char ** argv)
{
    Test * t1 = new Test{100};
    delete t1;

    unique_ptr<Test> ptr1  {new Test{101}};

    unique_ptr<Test> ptr2 = make_unique<Test>(102);

    unique_ptr<Test> ptr3;
    ptr3 = move(ptr1);

    if (ptr1 == nullptr)
        cout<<"ptr1 is null out\n";

    cout<<"______________________________________\n";
    unique_ptr<Account> a1 = make_unique<Checking_Account> ("MOE",100);
    cout<<*a1<<endl;
    a1->deposit(200);
    cout<<*a1<<endl;

    vector<unique_ptr<Account>> acc_vec;
    acc_vec.push_back(make_unique<Checking_Account>("James", 1000));
    acc_vec.push_back( make_unique<Savings_Account>("Billy", 4000, 5.2));
    acc_vec.push_back( make_unique<Trust_Account>("Bobby", 5000, 4.5));
    acc_vec.push_back(move(a1));
    

    for (auto &a:acc_vec)
    {
        cout<<*a<<endl;
    }

    cout<<"______________________________________\n";

    

    return 0;
}