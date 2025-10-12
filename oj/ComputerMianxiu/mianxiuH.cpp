#include <iostream>
using namespace std;

int main(){
    int in[10];
    for(int i=0; i<10; i++){
        cin >>in[i];
    }
    for(int n=1; n<10; n++){
        cout <<n <<"  ";
        for(int i=0; i<(10-n); i++){
            if(in[i] > in[i+1]){
                int t = in[i+1];
                in[i+1] = in[i];
                in[i] = t;
            }
        }
        for(int i=0; i<(10-n); i++){
            cout <<" " <<in[i];
        }
        cout <<endl;
    }
    cout <<"sorted:";
    for(int i=0; i<10; i++){
        cout <<" " <<in[i];
    }
    return 0;
}