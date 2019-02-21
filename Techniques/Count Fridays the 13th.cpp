#include<bits/stdc++.h>
using namespace std;

string day[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
unsigned int month[] =         {0,31,28,31,30,31,30,31,31,30,31,30,31};
unsigned int monthLeapYear[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};

struct date{
    unsigned int d,m,y;
    date(){}
    date(int d,int m,int y){
        this->d = d;
        this->m = m;
        this->y = y;
    }
};

bool leap(int year){
    if((year%4 == 0 && year%100 != 0) || (year % 400 == 0)){
        return true;
    }
    else return false;
}

bool valid(date a,date b){
    if(a.y > b.y)return false;
    if(a.y < b.y)return true;
    if(a.y == b.y){
        if(a.m < b.m)return true;
        if(a.m == b.m){
            if(a.d <= b.d)return true;
            return false;
        }
        return false;
    }
    return false;
}

int main()
{
    unsigned int t;
    cin >> t;
    while(t--){
        unsigned int d1,m1,y1,d2,m2,y2;
       int ans = 0;
       scanf("%d %d %d %d %d %d",&d1,&m1,&y1,&d2,&m2,&y2);
       unsigned int cnt = 1;
       for(int y = 1900; y <= y2; y++){
            for(int m = 1; m <= 12; m++){
                if(leap(y) == false){
                    for(int d = 1; d <= month[m]; d++,cnt++){
                        if(d == 13){
                            int sos = cnt%7;
                               // cout << cnt << " " << d << " " << m << " " <<y << endl;
                            if(day[sos] == "Fri" && (valid(date(d1,m1,y1),date(d,m,y)) && valid(date(d,m,y),date(d2,m2,y2)))){
                                ans++;
                            }
                        }
                    }
                }
                else{
                    for(int d = 1; d <= monthLeapYear[m]; d++,cnt++){
                            if(d == 13){
                                int sos = cnt%7;
                                   // cout << cnt << endl;
                                if(day[sos] == "Fri" && (valid(date(d1,m1,y1),date(d,m,y)) && valid(date(d,m,y),date(d2,m2,y2)))){
                                    ans++;
                                }
                            }
                    }
                }
            }
       }
       cout << ans << endl;
    }
    return 0;

}
