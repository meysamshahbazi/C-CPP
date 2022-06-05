
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cctype>
#include <numeric>


 

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

 class Personn{
    std::string name;
    int age;
public:
    Personn() = default;
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

    return 0;
}

