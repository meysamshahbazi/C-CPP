
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>

 

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

 template<typename T, int N>
 class Array
 {
     int size {N};
     T value[N];
     friend std::ostream & operator<<(std::ostream &os, const Array<T,N> &arr)
     {
         os<<"[ ";
         for (const auto &v:arr.value)
            os<<v<<" ";
        os<<"]"<<std::endl;
        return os; 
     }

public:
    Array() = default;
    Array(T init_val)
    {
        for(auto &item: value)
            item = init_val;
        // for(int i=0;i<N;i++)
        //     value[i] = init_val;
    }
    void fill(T val)
    {
        for(auto &item: value)
            item = val;   
    }
    int get_size() const 
    {
        return size;
    }
     T & operator[](int index)
     {
        return value[index];
     }
 };

 void display(const std::vector<int> &vec) {
    std::cout << "[ ";
    for (auto const &i: vec) {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}


void test1()
{
    std::cout<<"=====================TEST1========================="<<std::endl;

    std::vector<int> num1  {1,2,3,4,5};

    std::vector<int>::iterator it = num1.begin();

    std::cout<< *it <<std::endl;

    it++;
    std::cout<< *it <<std::endl;

    it +=2;

    std::cout<< *it <<std::endl;

    it = num1.end() -1;
    std::cout<< *it <<std::endl;
}

void test2()
{
    std::cout<<"=====================TEST2========================="<<std::endl;
    std::vector<int> num1  {1,2,3,4,5};
    
    auto it = num1.begin();

    while( it != num1.end())
    {
        std::cout<<*it<<std::endl;
        it++;
    }

    it = num1.begin();
    // 
    while(it != num1.end())
    {
        
        *(it++) =0;
        // it++; 
    }

    display(num1);

    it = num1.end();
    while(it != num1.begin())
    {
        it--;
        *it =0; 
    }
    display(num1);
}

void test3()
{
    std::cout<<"=====================TEST3========================="<<std::endl;
    std::vector<int> num1  {1,2,3,4,5}; 
    // std::vector<int>::const_iterator it = num1.begin();

    auto it = num1.cbegin();

    while( it != num1.end())
    {
        std::cout<<*it<<std::endl;
        it++;
    }

    it = num1.begin();
    // 
    while(it != num1.end())
    {
        
        // *it =0;
        it++; 
    }

    display(num1);
}

void test4()
{
    std::cout<<"=====================TEST4========================="<<std::endl;
    std::vector<int> vec{1,2,3,4,5}; 

    auto it1 = vec.rbegin();

    while(it1 !=vec.rend())
    {
        std::cout<<*it1<<std::endl;
        it1++;
    } 
    std::list<std::string> name{"Larry","Moe","curly"};
    auto it2 = name.crbegin();

    std::cout<<*it2<<std::endl;
    it2++;
    std::cout<<*it2<<std::endl;

    std::map<std::string,std::string> favorites
    {
        {"frank","c++"},
        {"bill","java"},
        {"james","docker"}
    };
    auto it3 = favorites.begin();
    while(it3 != favorites.end())
    {
        std::cout<<it3->first<<":"<<it3->second<<std::endl;
        it3++;
    }
}

void test5()
{
    std::cout<<"=====================TEST4========================="<<std::endl;
    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    auto start = vec.begin()+2;
    auto end = vec.end()-4;

    while(start !=end)
    {
        std::cout<<*start<<std::endl;
        start++;
    } 

}


int main ()
{
    
    std::cout<<"==================================================="<<std::endl;
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

    My_Pair <std::string, int> pair1 {"Frank", 100};
    My_Pair <int, double> pair2 {124, 13.6};

    std::cout << pair1.first << ", " << pair1.second << std::endl;
    std::cout << pair2.first << ", " << pair2.second << std::endl;

    std::cout<<"==================================================="<<std::endl;

    // Array<int,5> nums;
    Array<int,5> nums{2};

    std::cout << "The size of nums is: "<< nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(0);
    std::cout << "The size of nums is: "<< nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(10);
    std::cout << nums << std::endl;

    nums[0] = 1000;
    nums[3] = 2000;
    std::cout << nums << std::endl;
    
    Array<int, 100> nums2 {1};
    std::cout << "The size of nums2 is: "<< nums2.get_size() << std::endl;
    std::cout << nums2 << std::endl;

    Array<std::string, 10> strings(std::string{"Frank"});
    std::cout << "The size of strings is: "<< strings.get_size() << std::endl;
    std::cout << strings << std::endl;

    strings[0] = std::string{"Larry"};
    std::cout << strings << std::endl;
    
    strings.fill(std::string{"X"});
    std::cout << strings<< std::endl;
    std::cout<<"==================================================="<<std::endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    


    return 0;
}

