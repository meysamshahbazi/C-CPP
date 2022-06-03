
#include <iostream>

#include <string>

using namespace std;

double calc_mpg(int miles, int gallons)
{
    if (gallons == 0)
        throw 0;

    if (miles <0 || gallons < 0)
        throw string{"Negetive Value Error"};

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
    catch(...)
    {
        cerr<<"Unkown Error"<<endl;

    }
    

    cout<<"BYE\n";


    return 0;
}