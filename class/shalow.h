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
        ~Shallow();

};

Shallow::Shallow(int d)
{
    data = new int;
    *data = d;
}

Shallow::Shallow(const Shallow & source)
    :data{source.data}
{
    cout << "Copy constructor  - shallow copy" << endl;

}

Shallow::~Shallow()
{
    delete data;
    cout << "Destructor freeing data" << endl;
}




#endif