#include <iostream>
using namespace std;

long long num = 0;
long long time_ = 0;


int main()
{
    cin >> num;
    cin >> time_;
    long long res = 0;
    long long sum = 0;
    long long max = 0;
    long long page[1000000];
    for(int i  = 0; i < num; i++){
        cin >> page[i];
        sum += page[i];
        if(page[i] > max)
            max = page[i];
    }

    //二分查找
    long long min = 0;
    res = (min+max)/2;
    //x用来记录阅读时间
    long long x = 0;
    while(min != res && max != res){
        x = 0;
        //flag用来记录是否超过最大时间
        int flag = 0;
        for(int i = 0;i < num;i++){
            if(page[i] % res == 0)
                x = x + page[i]/res;
            else
                x = x + page[i]/res + 1;
            if(x > time_)
            {flag = 1;break;}
        }
        if(x > time_)
            flag = 1;
        if(flag == 1)
        {min = res;res = (max+min)/2;}
        else
        {max = res;res = (max+min)/2;}
    }

    //有的时候会偏离正确答案1。
    do{
        x = 0;
        for(int i = 0;i < num;i++){
            if(page[i] % res == 0)
                x = x + page[i]/res;
            else
                x = x + page[i]/res + 1;
            if(x > time_)
            {res++;break;}
        }
    }while(x > time_);
    

    cout << res << endl;
}
