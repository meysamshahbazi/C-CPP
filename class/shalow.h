#ifndef _SHALLOW_H
#define _SHALLOW_H
#include <iostream>

class Shallow{
    private:
        int * data;
    public:
        void set_data_value(int d){*data = d; }
        int get_data_value() {return *data;}
        Shallow(int d);
        Shallow(const Shallow & source);
        Shallow(Shallow &&source) noexcept;
        ~Shallow();

};

Shallow::Shallow(int d)
{
    data = new int;
    *data = d;
}

// this is for shallow copy with comes up with problem
// Shallow::Shallow(const Shallow & source)
//     :data{source.data}
// {
//     cout << "Copy constructor  - shallow copy" << endl;

// }


// compy constructor for deep coping


Shallow::Shallow(const Shallow & source )
    :Shallow(*source.data)
{
    // data = new int;
    // *data = *source.data;
    cout << "Copy constructor  - DEEP copy" << endl;
}

Shallow::Shallow(Shallow && source) noexcept
    :data{source.data}
{
    source.data = nullptr;
    cout << "Move constructor - moving resource: " << *data << endl;
}




Shallow::~Shallow()
{
    if (data != nullptr) {
        cout << "Destructor freeing data for: " << *data << endl;
    } else {
        cout << "Destructor freeing data for nullptr" << endl;
    }
    delete data;
}




#endif