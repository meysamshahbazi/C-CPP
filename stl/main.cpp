
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <deque>
#include <iterator>
#include <stack>
#include <queue>


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

 class Personn{
    std::string name;
    int age;
    friend std::ostream &operator<<(std::ostream &os,const Personn &p);
public:
    // Personn() = default;
    Personn(): name{"Unkhown"},age{0} {}
    Personn(std::string name, int age)
        :name{name},age{age} {}
    bool operator<(const Personn &rhs) const 
    {
        return this->age <rhs.age;
    }
    bool operator==(const Personn & rhs) const
    {
        return (this->name==rhs.name && this->age == rhs.age);
    }
 };
std::ostream &operator<<(std::ostream &os,const Personn &p) 
{
    os<<p.name<<":"<<p.age;
    return os;
}
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


template<typename T>
void display(const std::vector<T> &vec) {
    std::cout << "[ ";
    for (auto const &i: vec) {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

void display2(const std::vector<int> &vec)
{
    std::cout<<"[ ";
    std::for_each(vec.begin(),vec.end(),
        [] (int x){std::cout<<x<<" ";});
    std::cout<<"]"<<std::endl;
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

void find_test()
{
    std::cout<<"=====================FINDTEST========================="<<std::endl;
    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    auto loc = std::find(std::begin(vec),std::end(vec),1);

    if (loc != vec.end() )
        std::cout<<"find in the location of "<< loc-vec.begin()<<std::endl;
    else 
        std::cout << "Couldn't find the number" << std::endl;

    std::list<Personn> players {
        {"Larry", 18},
        {"Moe", 20},
        {"Curly", 21}
    };

    auto loc1 = std::find(players.begin(),players.end(),Personn{"Moe", 20});

    if (loc1 != players.end())
        std::cout << "Found  Moe" << std::endl;
    else
        std::cout << "Moe not found" << std::endl;
    
}

void count_test()
{
    std::cout<<"=====================COUNTTEST========================="<<std::endl;
    std::vector<int> vec {1,2,3,4,5,1,2,1};
    int num = std::count(vec.begin(),vec.end(),2);
    std::cout << num << " occurrences found" << std::endl;

}

void count_if_test() 
{
    std::cout<<"=====================COUNTifTEST========================="<<std::endl;
    std::vector<int> vec {1,2,3,4,5,1,2,1,100};
    int num = std::count_if(vec.begin(),vec.end(),[] (int x){return x %2 == 0;});
    std::cout << num << " even numbers found" << std::endl;
    num = std::count_if(vec.begin(),vec.end(),[](int x){return x%2 !=0;});
    std::cout << num << " odd numbers found" << std::endl;
    num = std::count_if(vec.begin(),vec.end(),[](int x){return x>= 5;});
    std::cout << num << "  numbers are >= 5" << std::endl;

}
void replace_test() 
{
    std::cout<<"=====================REPLACETEST========================="<<std::endl;

    std::vector<int> vec {1,2,3,4,5,1,2,1};

    for (auto i: vec) {
         std::cout << i << " ";
    }
    std::cout<<std::endl;

    std::replace(vec.begin(),vec.end(),1,100);
    for (auto i: vec) {
         std::cout << i << " ";
    }
    std::cout<<std::endl;


}

void all_of_test()
{
    std::cout<<"=====================ALL_OF_TEST========================="<<std::endl;
    std::vector<int> vec1 {1,3,5,7,9,1,3,13,19,5};

    if (std::all_of(vec1.begin(),vec1.end(),[](int x){return x>10;}))
        std::cout << "All the elements are > 10" << std::endl;
    else
        std::cout << "Not all the elements are > 10" << std::endl;
    
    if (std::all_of(vec1.begin(),vec1.end(),[](int x){return x<20;}))
        std::cout << "All the elements are < 20" << std::endl;
    else 
        std::cout << "Not all the elements are < 20" << std::endl;

}

void string_transform_test() 
{
    std::cout<<"==================================================="<<std::endl;

    std::string str1 {"This is a test"};
    std::cout << "Before transform: " << str1 << std::endl;
    std::transform(str1.begin(),str1.end(),str1.begin(),::toupper );
    std::cout << "After transform: " << str1 << std::endl;


}

void display(const std::array<int,5> &arr )
{
    std::cout<<"[ ";
    for (auto &a : arr)
        std::cout<<a<<" ";
    std::cout<<"]"<<std::endl;
}

void test11()
{
    std::cout << "\nTest11 =========================================" << std::endl;
    std::array<int,5> arr1 = {1,2,3,4,5};
    std::array<int,5> arr2;

    display(arr1);
    display(arr2);

    arr2 = {10,20,30,40,50};
    display(arr1);
    display(arr2);

    std::cout<< "Size of arr1 is: " <<arr1.size()<<std::endl;
    std::cout<< "Size of arr2 is: " <<arr2.size()<<std::endl;

    arr1[0] = 1000;
    arr1.at(1) = 2000;
    display(arr1);

    std::cout << "Front of arr2: " << arr2.front()<<std::endl;
    std::cout << "Back of arr2: " << arr2.back()<<std::endl;
}
void test12()
{
    std::cout << "\nTest12 =========================================" << std::endl;
    std::array<int,5> arr1 = {1,2,3,4,5};
    std::array<int,5> arr2 = {10,20,30,40,50};

    display(arr1);
    display(arr2);

    arr1.fill(0);

    display(arr1);
    display(arr2);

    arr1.swap(arr2);

    display(arr1);
    display(arr2);
}

void test13()
{
    std::cout << "\nTest13 =========================================" << std::endl;
    std::array<int,5> arr1 = {1,2,3,4,5};

    int * ptr = arr1.data();
    std::cout<<ptr<<std::endl;
    *ptr = 1000;
    display(arr1);
}

void test14()
{
    std::cout << "\nTest14 =========================================" << std::endl;
    std::array<int,5> arr1 = {2,1,4,5,3}; 
    display(arr1);

    std::sort(arr1.begin(),arr1.end());
    display(arr1);

}

void test15()
{
    std::cout << "\nTest15 =========================================" << std::endl;
    std::array<int,5> arr1 = {2,1,4,5,3}; 

    std::array<int,5>::iterator min_num = std::min_element(arr1.begin(),arr1.end());
    auto max_num = std::max_element(arr1.begin(),arr1.end());
    std::cout << "min: " << *min_num << " , max: " << *max_num << std::endl;

}

void test16()
{
    std::cout << "\nTest16 =========================================" << std::endl;
    std::array<int, 5> arr1 {2,1,3,3,5};

    auto adjacent = std::adjacent_find(arr1.begin(),arr1.end());
    if (adjacent != arr1.end() )
        std::cout << "Adjacent element found with value: " << *adjacent <<std::endl;
    else 
        std::cout << "No adjacent elements found" << std::endl;

}

void test17() 
{
    std::cout << "\nTest17 =========================================" << std::endl;
    std::array<int, 5> arr1 {2,1,3,3,5};

    int sum = std::accumulate(arr1.begin(),arr1.end(),0);
    std::cout << "Sum of the elements in arr1 is: " << sum << std::endl;
}

void test18()
{
    std::cout << "\nTest18 =========================================" << std::endl;
    std::array<int, 10> arr1 {1,2,3,1,2,3,3,3,3,3};

    int count = std::count(arr1.begin(),arr1.end(),3);
    std::cout << "Found 3 : " << count << " times" << std::endl;
}
void test19()
{
    std::cout << "\nTest19 =========================================" << std::endl;
    std::array<int, 10> arr1 {1, 2, 3, 50, 60, 70, 80, 200, 300 ,400};

    int count = std::count_if(arr1.begin(),arr1.end(),
    [](int x) { return x>10 && x<200;});
    std::cout << "Found  " << count << " matches" << std::endl;
}

void test21(){
    std::cout << "\nTest21 =========================" << std::endl;
    
    std::vector<int> vec{1,2,3,4,5};
    display(vec);
    
    vec = {2,4,6,8};

    display2(vec);
    std::vector<int> vec1(10,20);
    display2(vec1);
}

void test22()
{
    std::cout << "\nTest22 =========================" << std::endl;
    std::vector<int> vec{1,2,3,4,5};
    display2(vec);
    std::cout<<"vec size: "<<vec.size()<<std::endl;
    std::cout<<"vec max size: "<<vec.max_size()<<std::endl;
    std::cout<<"vec capacity: "<<vec.capacity()<<std::endl;

    vec.push_back(6);

    std::cout<<"vec size: "<<vec.size()<<std::endl;
    std::cout<<"vec max size: "<<vec.max_size()<<std::endl;
    std::cout<<"vec capacity: "<<vec.capacity()<<std::endl;

    vec.shrink_to_fit();
    display2(vec);
    std::cout<<"vec size: "<<vec.size()<<std::endl;
    std::cout<<"vec max size: "<<vec.max_size()<<std::endl;
    std::cout<<"vec capacity: "<<vec.capacity()<<std::endl;

    vec.reserve(100);
    display2(vec);
    std::cout<<"vec size: "<<vec.size()<<std::endl;
    std::cout<<"vec max size: "<<vec.max_size()<<std::endl;
    std::cout<<"vec capacity: "<<vec.capacity()<<std::endl;
}
void test23()
{
    std::cout << "\nTest23 =========================" << std::endl;
    std::vector<int> vec{1,2,3,4,5};
    display2(vec);

    vec[0] = 100;
    vec.at(1) = 200;

    display(vec);


}
void test24()
{
    std::cout << "\nTest24 =========================" << std::endl;

    std::vector<Personn> stooges;

    Personn p1{"Larry",18};
    display(stooges);

    stooges.push_back(p1);
    display(stooges);

    stooges.push_back({Personn{"Moe",23}});

    display(stooges);
    stooges.emplace_back("Curly",30);
    display(stooges);

}
void test25()
{
    std::cout << "\nTest25 =========================" << std::endl;
    std::vector<Person> stooges {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 30}
    };
    display(stooges);
    std::cout<<"Front: "<<stooges.front()<<std::endl;
    std::cout<<"Back: "<<stooges.back()<<std::endl;

    stooges.pop_back();
    display(stooges);
}
void test26()
{
    std::cout << "\nTest26 =========================" << std::endl;
    std::vector<int> vec{1,2,3,4,5};
    display2(vec);

    vec.clear();
    display(vec);

    vec = {1,2,3,4,5,6,7,8,9,10};
    display(vec);

    vec.erase(vec.begin(),vec.begin()+2);
    display(vec);

    vec = {1,2,3,4,5,6,7,8,9,10};
    display(vec);

    auto it = vec.begin();
    while (it != vec.end() )
    {
        if( *it%2 ==0)
            vec.erase(it);
        else   
            it++;
    }
    display2(vec);
}

void test27()
{
    std::cout << "\nTest27 =========================" << std::endl;

    std::vector<int> vec1 {1,2,3,4,5};
    std::vector<int> vec2 {10,20,30,40,50};
    
    display(vec1);
    display(vec2);

    vec1.swap(vec2);
    display(vec1);
    display(vec2);

}

void test28()
{
    std::cout << "\nTest28 =========================" << std::endl;
    std::vector<int> vec1 {1,21,3,40,12};    
    
    display(vec1);

    std::sort(vec1.begin(),vec1.end());

    display2(vec1);
}

void test29()
{
    std::cout << "\nTest29 =========================" << std::endl;
    std::vector<int> vec1 {1,2,3,4,5};   
    std::vector<int> vec2 {10,20};
    
    display(vec1); 
    display(vec2);
    std::cout << std::endl;

    std::copy(vec1.begin(),vec1.end(),std::back_inserter(vec2));
    display(vec1); 
    display(vec2);

    vec1 = {1,2,3,4,5,6,7,8,9,10};
    vec2 = {10,20};
    
    display(vec1);
    display(vec2);
    std::copy_if(vec1.begin(),vec1.end(),std::back_inserter(vec2),
    [](int x){return x%2 ==0;});
    display(vec1); 
    display(vec2);
}

void test210()
{
    std::cout << "\nTest210 =========================" << std::endl;
    std::vector<int> vec1 {1,2,3,4,5};   
    std::vector<int> vec2 {10,20,30,40,50};
    std::vector<int> vec3;

    std::transform(vec1.begin(),vec1.end(),vec2.begin(),
    std::back_inserter(vec3),
    [](int x, int y){ return x*y;});
    display(vec1);
    display(vec2);
    display(vec3);

}

void test211()
{
    std::cout << "\nTest211 =========================" << std::endl;
    std::vector<int> vec1 {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> vec2 {100,200,300,400};
    
    display(vec1);
    display(vec2);

    auto it = std::find(vec1.begin(),vec1.end(),5);
    if (it != vec1.end()) 
    {
        std::cout<<"inserring... "<<std::endl;
        vec1.insert(it,vec2.begin(),vec2.end());
    }
    else 
    {
        std::cout << "Sorry, 5 not found" << std::endl;   
    }

    display(vec1);

}
template<typename T>
void display(const std::deque<T> &d)
{
    std::cout<<"{ ";
    for (const auto &item:d )
        std::cout<<item<<" ";
    
    std::cout<<"}"<<std::endl;
}
void test31()
{
    std::cout << "\nTest31 =========================" << std::endl;
    std::deque<int> d {1,2,3,4,5};
    display(d);
    d = {5,6,7,8};
    display(d);
    
    std::deque<int> d1(10,100);

    display(d1);

    d[0]= 100;
    d.at(1) = 200;

    display(d);
}

void test32()
{
    std::cout << "\nTest32 =========================" << std::endl;
    std::deque<int> d {0,0,0};

    d.push_back(10);
    d.push_back(20);

    display(d);

    d.push_front(100);
    d.push_front(200);

    display(d);

    std::cout<<"FRONT "<< d.front() << std::endl;
    std::cout<<"back "<< d.back() << std::endl;
    std::cout<<"SIZE "<< d.size()<< std::endl;
}

void test33()
{
    std::cout << "\nTest33 =========================" << std::endl;
    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::deque<int> d;

    for(const auto & item: vec)
    {
        if (item %2 ==0 )
            d.push_back(item);
        else 
            d.push_front(item);
    }
    display(d);

}

void test34()
{
    std::cout << "\nTest34 =========================" << std::endl;

    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::deque<int> d;

    for (const auto & elem:vec)
        d.push_front(elem);

    display(d);

    d.clear();

    for (const auto & elem:vec)
        d.push_back(elem);

    display(d);


}

void test35()
{
    std::cout << "\nTest35 =========================" << std::endl;
    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::deque<int> d;

    std::copy(vec.begin(),vec.end(),std::front_inserter(d));
    display(d);

    d.clear();
    
    std::copy(vec.begin(),vec.end(),std::back_inserter(d));
    display(d);
}

template <typename T>
void display(const std::list<T> &l) 
{
    std::cout<<"[[ ";
    for (const auto &elem : l)
        std::cout << elem <<" ";

    std::cout<<"]]"<<std::endl;
}

void test41()
{
    std::cout << "\nTest41 =========================" << std::endl;
    std::list<int> l1 {1,2,3,4,5};
    display(l1);
    std::list<std::string> l2;
    l2.push_back("BACK");
    l2.push_front("FRONT");
    display(l2);
    std::list<int> l3;
    l3 = {1,2,3,4,5,6,7,8,9,10};
    display(l3);
    std::list<int> l4(10,100);
    display(l4);
}

void test42()
{
    std::cout << "\nTest42 =========================" << std::endl;
    std::list<int> l{1,2,3,4,5,6,7,8,9,10};
    display(l);
    std::cout<<"SIZE: "<<l.size()<<std::endl;
    std::cout<<"FRONT: "<<l.front()<<std::endl;
    std::cout<<"BACK: "<<l.back()<<std::endl;

    l.clear();
    display(l);
    std::cout<<"SIZE: "<<l.size()<<std::endl;
}

void test43()
{
    std::cout << "\nTest43 =========================" << std::endl;
    std::list<int> l {1,2,3,4,5,6,7,8,9,10};
    display(l);

    l.resize(5);
    display(l);

    l.resize(10);
    display(l);
    std::list<Personn> persons;
    persons.resize(10);
    display(persons);
}

void test44()
{
    std::cout << "\nTest44 =========================" << std::endl;
    std::list<int> l {1,2,3,4,5,6,7,8,9,10};
    display(l);

    auto it = std::find(l.begin(),l.end(),5);

    if( it != l.end() )
        l.insert(it,100);

    display(l);

    std::list<int> l2 {1000,2000,3000};

    l.insert(it,l2.begin(),l2.end());
    display(l);
    std::advance(it,-4);
    std::cout<<*it<<std::endl;

    l.erase(it);

    display(l);

}

void test45()
{
    std::cout << "\nTest45 =========================" << std::endl;
    std::list<Personn>  stooges {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 17}
    };
    display(stooges);
    stooges.emplace_back("TMI",11);
    display(stooges);

    auto it = std::find(stooges.begin(),stooges.end(),Personn{"Moe", 25});

    if (it != stooges.end())
        stooges.emplace(it,"frank",14);
    display(stooges);
}

void test46()
{
    std::cout << "\nTest46 =========================" << std::endl;
    std::list<Personn>  stooges {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 17}
    };
    display(stooges);
    stooges.sort();
    // std::sort(stooges.begin(),stooges.end());
    display(stooges);
}

template<typename T>
void display(const std::set<T> &set_to_display )
{
    std::cout<<"[ ";
    for (const auto &s:set_to_display)
    {
        std::cout<<s<<" ";
    }
    std::cout<<"]"<<std::endl;
}

void test51()
{
    std::cout << "\nTest 51 =========================" << std::endl;
    std::set<int> s1 = {1, 4, 3, 5, 2};
    display(s1);
    s1 = {1,2,3,1,1,2,2,3,3,4,5};
    display(s1);

    s1.insert(0);

    display(s1);
    s1.insert(10);
    display(s1);
    
    if(s1.count(10))
        std::cout<<"10 is here in set"<<std::endl;
    else    
        std::cout<<"10 is NNOOOT here in set"<<std::endl;

    auto it = s1.find(5);
    if(it !=s1.end() )
        std::cout<<"found "<<*it<<std::endl;
    
    s1.clear();
    display(s1);

}
void test52()
{
    std::cout << "\nTest 52 =========================" << std::endl;
    std::set<Personn> stooges {
        {"Larry", 1},
        {"Moe", 2},
        {"Curly", 3}
    };
    display(stooges);
    stooges.emplace("james",19);
    display(stooges);
    stooges.emplace("frank",19);
    display(stooges);

    auto it = stooges.find(Personn{"Moeee",2});
    if (it != stooges.end()) 
        std::cout<<"found= "<<*it<<std::endl;

    display(stooges);

    it = stooges.find(Personn{"XXX",19});
    if (it != stooges.end())
        stooges.erase(it);

    display(stooges);

}
void test53()
{
    std::cout << "\nTest 53 =========================" << std::endl;
    std::set<std::string> s {"A", "B", "C"};
    display(s);

    auto result = s.insert("D");
    display(s);
    std::cout<<*(result.first)<<std::endl;
    std::cout<<(result.second)<<std::endl;

    result = s.insert("A");
    display(s);
    std::cout<<*(result.first)<<std::endl;
    std::cout<<(result.second)<<std::endl;

}

template<typename T1,typename T2>
void display(const std::map<T1,T2> &m)
{
    std::cout<<"[ ";
    for (const auto & elem:m)
    {
        std::cout<<elem.first<<":"<<elem.second<<" ";
    }
    std::cout<<"]"<<std::endl;
}
void test61()
{
    std::cout << "\nTest 61 =========================" << std::endl;
    std::map<std::string, int> m{
        {"Larry", 3},
        {"Moe", 1},
        {"Curly", 2}
    };
    display(m);
    m.insert(std::make_pair<std::string,int>("Anna",5));
    display(m);

    // m.insert(std::make_pair<std::string,int>("joe",4));
    m.emplace("joe",4);
    display(m);
    m["Frank"] = 14;
    display(m);

    m["Frank"] += 14;
    display(m);

    m.erase("Frank");

    display(m);

    std::cout << "Count for Joe: " << m.count("joe") << std::endl;
    std::cout << "Count for Frank: " << m.count("Frank") << std::endl;

    auto it = m.find("Larry");

    if (it != m.end())
        std::cout << "Found: " << it->first << " : " << it->second << std::endl;  

    m.clear();
    display(m);


}

void display(const std::map<std::string, std::set<int>> &m)
{
    std::cout<<"{ "<<std::endl;
    for (const auto & elem:m)
    {
        std::cout<<elem.first<<":";
        display(elem.second);
    }
    std::cout<<"}"<<std::endl;
}
void test62()
{
    std::cout << "\nTest 61 =========================" << std::endl;
    
     std::map<std::string, std::set<int>> grades  {
        {"Larry", {100, 90} },
        {"Moe",  {94} },
        {"Curly", {80, 90, 100} }
    };
    display(grades);

    grades["Larry"].insert(95);
    display(grades);
    auto it = grades.find("Moe");
    if (it != grades.end())
        it->second.insert(1000);

    display(grades);

}

template <typename T>
void display(std::stack<T> s)
{
    std::cout<<"[ ";
    while(!s.empty() )
    {
        std::cout<<s.top()<<" ";
        s.pop();
    }
    std::cout<<"]"<<std::endl;
}

template <typename T>
void display(std::queue<T> s)
{
    std::cout<<"[ ";
    while(!s.empty() )
    {
        std::cout<<s.front()<<" ";
        s.pop();
    }
    std::cout<<"]"<<std::endl;
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
    
    std::cout<<"==================================================="<<std::endl;

    find_test();
    count_test();
    count_if_test();
    replace_test();
    all_of_test();
    string_transform_test();

    test11();
    test12();
    test13();
    test14();
    test15();
    test16();
    test17();
    test18();
    test19();

    test21();
    test22();
    test23();
    test24();
    test25();
    test26();
    test27();
    test28();
    test29();
    test210();
    test211();

    test31();
    test32();
    test33();
    test34();
    test35();

    test41();
    test42();
    test43();
    test44();
    test45();
    test46();

    test51();
    test52();
    test53();

    test61();
    test62();
    // stack 
    std::cout<<"Test stack ========================="<<std::endl;
    std::stack<int> s;

    for (int i: {1,2,3,4,5})
        s.push(i);
    display(s);

    s.push(100);

    display(s);

    s.pop();
    s.pop();
    display(s);
    std::cout << "Size: " << s.size() << std::endl;
    while( !s.empty() )
        s.pop();

    std::cout << "Size: " << s.size() << std::endl;
    display(s);

    s.push(10);
    display(s);
    s.top() = 100;
    display(s);
    // queue
    std::cout<<"Test queue ========================="<<std::endl;
    std::queue<int> q;

    for(int i:{1,2,3,4,5})
        q.push(i);
    display(q);

    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back:  " << q.back() << std::endl;

    q.push(100);
    display(q);

    q.pop();
    display(q);

        q.pop();
    q.pop();
    display(q);
    
    while (!q.empty())
        q.pop();
    display(q);

    std::cout << "Size: " << q.size() << std::endl;
    
    q.push(10);
    q.push(100);
    q.push(1000);
    display(q);
    
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back:  " << q.back() << std::endl;
    
    q.front() = 5;
    q.back() = 5000;
    
    display(q);
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back:  " << q.back() << std::endl;

    

    return 0;
}

