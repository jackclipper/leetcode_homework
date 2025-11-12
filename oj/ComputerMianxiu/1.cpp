#include <iostream>
using namespace std;
int main(){
    char in[1000];
    int end = 0;
    for(int i=0; i<1000; i++){
        char temp;
        cin >>temp;
        if(temp == '#'){
            end = temp;
            break;
        }
        else{
            in[i]=temp;
        }
    }

    int result=0;
    for(int i=0; i<end; i++){
        if(in[i] == 'A' || in[i] == 'B' || in[i] == 'C' || 
        in[i] == 'a' || in[i] == 'b' || in[i] == 'c'){
            result++;
        }
    } 

    cout <<result;

    return 0;
}