
#include <iostream>
#include <string>

// using namespace std;

template <typename T>
T min(T a, T b){
    return (a < b)? a:b;
}
template<typename T1,typename T2>
void func(T1 a, T2 b)
{
    std::cout<<a<<" "<<b<<std::endl;
}

template<typename T>
void my_swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
 struct Person
 {
    std::string name;
    int age;
    bool operator<(const Person & rhs)
    {
        return this->age < rhs.age;
    }
 };

 std::ostream & operator<<(std::ostream & os, const Person &p)
 {
     os<<p.name;
     return os;
 }
 
int main ()
{
    int a {3};
    int b {4};
    std::cout<<min(a,b)<<std::endl;
    std::cout<<"a is: "<<a<<", b is: "<<b<<std::endl;
    my_swap(a,b);
    std::cout<<"a is: "<<a<<", b is: "<<b<<std::endl;

    Person p1 {"Curly", 15};
    Person p2 {"Moe", 30};

    func(p1,p2);

    Person p3 = min(p1,p2);

    std::cout<<"Min age is "<<p3<<std::endl;
    


    return 0;
}

