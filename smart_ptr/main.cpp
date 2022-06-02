
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

void my_deleter(Test * ptr)
{
    std::cout << "\tUsing my custom function deleter" << std::endl;
    delete ptr;
}

void func(std::shared_ptr<Test> p) {
    std::cout << "Use count: " << p.use_count() << std::endl;
}

class B;
class A{
    shared_ptr<B> b_ptr;
public:
    void set_B(shared_ptr<B> &b){
        b_ptr = b;
    }
    A() { cout << "A Constructor" << endl; }
    ~A() { cout << "A Destructor" << endl; }
};

class B{
    weak_ptr<A> a_ptr;
public:
     void set_A(std::shared_ptr<A> &a) {
        a_ptr = a;
    }
    B() { cout << "B Constructor" << endl; }
    ~B() { cout << "B Destructor" << endl; }
};



int main( int argc, const char ** argv)
{
    // uniqe pointer
    /*
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
   */
    // shared pointer 
    
    shared_ptr<int> ptr1{new int {100} };
    cout<<"ptr1 use_count: "<<ptr1.use_count()<< endl;
    shared_ptr<int> ptr2 {ptr1};
    // func(ptr1);

    cout<<"ptr1 use_count: "<<ptr1.use_count()<< endl;
    cout<<"ptr2 use_count: "<<ptr2.use_count()<< endl;

    ptr1.reset();

    cout<<"ptr1 use_count: "<<ptr1.use_count()<< endl;
    cout<<"ptr2 use_count: "<<ptr2.use_count()<< endl;

    cout<<"ptr1 value: "<<ptr1<<endl;
    cout<<"ptr2 value: "<<ptr2<<endl;

    std::cout << "\n==========================================" << std::endl;

    shared_ptr<Test> test_ptr = make_shared<Test>(100);
    func(test_ptr);
    std::cout << "Use count: " << test_ptr.use_count() << std::endl;
    
    {
        shared_ptr<Test> test_ptr1 = test_ptr;
        std::cout << "Use count: " << test_ptr1.use_count() << std::endl;
        test_ptr.reset();

        
    }

    std::cout << "Use count: " << test_ptr.use_count() << std::endl;
    std::cout << "\n==========================================" << std::endl;
    
    std::shared_ptr<Account> acc1 = std::make_shared<Trust_Account>("Larry", 10000, 3.1);
    std::shared_ptr<Account> acc2 = std::make_shared<Checking_Account>("Moe", 5000);
    std::shared_ptr<Account> acc3 = std::make_shared<Savings_Account>("Curly", 6000);

    std::vector<std::shared_ptr<Account>> accounts;
    accounts.push_back(acc1);
    accounts.push_back(acc2);
    accounts.push_back(acc3);
    

    for (const auto &acc: accounts) {
        std::cout << *acc << std::endl;
        std::cout << "Use count: " << acc.use_count() << std::endl;
    }

    std::cout << "\n==========================================" << std::endl;
    

    // wake pointer
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();

    a->set_B(b);
    b->set_A(a);
    {
        shared_ptr<Test> ptr1 {new Test{100},my_deleter};
    }
    std::cout << "\n==========================================" << std::endl;
    {
        shared_ptr<Test> ptr1 { new Test{1000}, 
            [](Test* ptr)
            {
                 std::cout << "\tUsing my custom lamdba deleter" << std::endl;
                delete ptr;
            }
        };
        
    }



    

    return 0;

}