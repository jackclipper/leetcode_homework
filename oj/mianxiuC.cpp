#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >>n;
    string in;
    cin >>in;
    for(int i=0; i<n; i++){
        if(in[i] == 'A'){
            i++;
            while(i<n){
                cout <<in[i++];
            }
        }
    }
    return 0;
}