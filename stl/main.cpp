
#include <iostream>
#include <string>
#include <vector>

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
    bool operator<(const Person & rhs) const
    {
        return this->age < rhs.age;
    }
 };

 std::ostream & operator<<(std::ostream & os, const Person &p)
 {
     os<<p.name;
     return os;
 }
 
template <typename T>
class Item{
private:
    std::string name;
    T value;
public:
    Item(std::string name,T value): name{name}, value{value} {}
    std::string get_name() const { return name;}
    T get_value() const {return value;}

 };

 template<typename T1, typename T2>
 struct My_Pair{
     T1 first;
     T2 second;
 };


int main ()
{
    int a {3};
    int b {4};
    std::cout<<min(a,b)<<std::endl;
    std::cout<<"a is: "<<a<<", b is: "<<b<<std::endl;
    my_swap(a,b);
    std::cout<<"a is: "<<a<<", b is: "<<b<<std::endl;

    Person p1 {"Curly", 15};
    Person p2 {"Moe", 12};

    func(p1,p2);

    Person p3 = min(p1,p2);

    std::cout<<"Min age is "<<p3<<std::endl;
    
    std::cout<<"==================================================="<<std::endl;

    Item<int> it1{"Meysam",21};
    
    std::cout << it1.get_name() << " " << it1.get_value() << std::endl;

    Item <std::string> it2{"MAMMAD","ASGHAR"};
    std::cout << it2.get_name() << " " << it2.get_value() << std::endl;

    Item<Item<std::string>> it3{"franck",Item<std::string>{"c++","senior"}};

     std::cout << it3.get_name() << " " 
                    << it3.get_value().get_name() << " "
                    << it3.get_value().get_value() << std::endl;
    
    std::cout<<"==================================================="<<std::endl;

    std::vector<Item<double>> vec {};
    vec.push_back (Item<double>("Larry", 100.0));
    vec.push_back (Item<double>("Moe", 200.0));
    vec.push_back (Item<double>("Curly",300.0));

    for (const auto &item:vec)
    {
         std::cout << item.get_name() << " " << item.get_value() << std::endl;
    }

    std::cout<<"==================================================="<<std::endl;

     std::cout << "\n================================" << std::endl;
    My_Pair <std::string, int> pair1 {"Frank", 100};
    My_Pair <int, double> pair2 {124, 13.6};

    std::cout << pair1.first << ", " << pair1.second << std::endl;
    std::cout << pair2.first << ", " << pair2.second << std::endl;




    return 0;
}

