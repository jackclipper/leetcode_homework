#include <iostream>
using namespace std;

int main(){
    int n;
    cin >>n;

    double sum=0;
    for(int i=0; i<n; i++){
        double temp;
        cin >>temp;
        sum+=temp;
    }

    double pj=(sum/n);
    cout <<pj;

    return 0;
}