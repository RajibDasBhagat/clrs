// how many people must be their in a room before there is a 50% chance
// that two of them were born on the same day
// k = no of people to find
// n = no of days
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;


int main(){

    double people,days,pairs;
    cout<<"No of days: ";
    cin>>days;
    cout<<"No of pairs: ";
    cin>>pairs;
    people = (1+ sqrt(1+(8 * log(pairs) )* days))/2;

    cout<<ceil(people)<<" peoples";

    return 0;
}
