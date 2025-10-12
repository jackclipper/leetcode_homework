#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int main(){
    ifstream complex;
    complex.open("complex.txt", ios::in);

    ofstream mod;
    mod.open("mod.txt", ios::out);

    double comp[10][2];

    string first_line;
    getline(complex, first_line);

    for(int i=0; i<10; i++){
        complex >>comp[i][0] >>comp[i][1];
    }
    
    complex.close();

    mod <<"模：" <<endl;
    for(int i=0; i<10; i++){
        mod <<sqrt(comp[i][0] * comp[i][0] + comp[i][1] * comp[i][1]) <<endl;
    }

    mod.close();

    return 0;
}