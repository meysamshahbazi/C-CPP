#include <iostream>

using namespace std;

int main()
{
    int * int_ptr {nullptr};
    int_ptr = new int;

    cout << int_ptr<<endl;
    cout << *int_ptr<<endl;
    *int_ptr = 100;

    cout << int_ptr<<endl;
    cout << *int_ptr<<endl;

    delete int_ptr;

    size_t size{0};
    double *temp_ptr{nullptr};

    cout << "HOW many temps? ";
    cin >> size;

    temp_ptr = new double[size];
    for(size_t t =0;t<size;t++)
        temp_ptr[t] = t*2;
        
    for(size_t t =0;t<size;t++)
        cout <<*(temp_ptr+t)<<" ";

    delete [] temp_ptr;
    cout<<endl;
    return 0;


}