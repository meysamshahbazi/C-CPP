#include <iostream>

using namespace std;

struct last_k_numbers_sum_stream
{
    int k;
    last_k_numbers_sum_stream(int _k) {k = _k;}
    int next(int new_num){
        
        return 0;
    }
    
};

int main()
{
    last_k_numbers_sum_stream proececor(4);

    int num;
    while(cin >>num) {
        cout<<proececor.next(num)<<endl;
    }    
    return 0;
}