#include <iostream>
#include <queue>

using namespace std;

struct last_k_numbers_sum_stream
{
    int k;
    queue<int> m_q;
    int sum = 0;
    last_k_numbers_sum_stream(int _k) {k = _k;}

    int next(int new_num){
        if(m_q.size() == k) {
            sum -= m_q.front();
            m_q.pop();
        }
        sum += new_num;
        m_q.push(new_num);
        return sum;
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