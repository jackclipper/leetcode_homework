#include <iostream>
using namespace std;

int main(){
    int a[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >>a[i][j];
        }
    }
    
    int max_len[3];
    for(int i=0; i<3; i++){
        int max=a[0][i];
        for(int j=1; j<3; j++){
            if(abs(a[j][i]) > abs(max)){
                max = a[j][i];
            }
        }
        int bt=0, temp=abs(max);
        if(max < 0){
            bt=1;
        }
        if(max = 0){
            bt=1;
        }
        else{
            while(temp != 0){
                temp/=10;
                bt++;
            }
        }
        max_len[i]=bt;
    }

    //注意不要操作原始数组
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int temp=a[i][j];
            int temp_len=0;
            if(temp <= 0){
                temp_len=1;
            }
            if(temp == 0){
                temp_len=1;
            }
            else{
                int t=abs(temp);
                while(t != 0){
                    t/=10;
                    temp_len++;
                }
            }
            cout <<a[i][j];
            if(j == 2){
                continue;
            }
            for(int k=temp_len; k<=max_len[j]; k++){
                cout <<' ';
            }
        }
        cout <<endl;
    }
    return 0;
}