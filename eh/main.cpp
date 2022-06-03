
#include <iostream>

#include <string>
#include "Account.h"
#include <memory>
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"



using namespace std;

void func_a();
void func_b();
void func_c();

class DivideByZeroException {
};
class NegativeValueException {
};


void func_a() {
    std::cout << "Starting func_a" << std::endl;
    func_b();
    std::cout << "Ending func_a" << std::endl;
}

void func_b() {
    std::cout << "Starting func_b" << std::endl;
    try {
        func_c();
    }
    catch( int & ex )
    {
        cout<<"Cought error in func b"<<endl;
    }
    std::cout << "Ending func_b" << std::endl;
}

void func_c() {
    std::cout << "Starting func_c" << std::endl;
    throw 100;
    std::cout << "Ending func_c" << std::endl;
}

double calc_mpg(int miles, int gallons)
{
    if (gallons == 0)
        // throw 0;
        throw DivideByZeroException();

    if (miles <0 || gallons < 0)
        throw NegativeValueException();
        // throw string{"Negetive Value Error"};

    return static_cast<double>(miles)/gallons;
}

int main()
{
    int miles {};
    int gallons {};
    double mpg {};

    cout<<"Enter miles: ";
    cin >> miles;
    cout<<"Enter gallons: ";
    cin>>gallons;

    try {
        mpg = calc_mpg(miles,gallons);
        cout<< "Miles per gallons is: "<<mpg<<endl;
    }
    catch( int & ex)
    {
        cerr<<"Zero division Error"<<endl;
    }

    catch (string & ex)
    {
        cerr<<ex<<endl;
    }
    catch ( const DivideByZeroException & ex )
    {
          std::cerr << "Sorry, you can't divide by zero Class EXP" << std::endl;
    }
    catch (const NegativeValueException & ex)
    {
        std::cerr << "Sorry, one of your parameters is negative class EXP" << std::endl;
    }
    catch(...)
    {
        cerr<<"Unkhown Error"<<endl;

    }
    

    cout<<"BYE\n";

    std::cout << "Starting main" << std::endl;
    try {
        func_a();

    }
    catch( int & ex )
    {
        cout<<"Cought error in main"<<endl;
    }
    std::cout << "Finishing main" << std::endl;

    try
    {
        unique_ptr<Account> acc = make_unique<Checking_Account>("MOE",-10);
    }
    catch(const IllegalBalanceException & ex)
    {
        std::cerr<<ex.what()<<endl;
        // std::cerr << "Couldn't create account - negative balance" << std::endl;
    }
    std::cout << "Program completed successfully" << std::endl;
    


    return 0;
}