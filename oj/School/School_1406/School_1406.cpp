#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
using namespace std;


int main(){
    fstream infile;
    infile.open("data.txt", ios::in);

    fstream outfile;
    outfile.open("result.txt", ios::out);

    string firstline;
    getline(infile, firstline);

    string input_a, input_b;
    getline(infile, input_a, ' ');
    getline(infile, input_b);

    double a, b;
    a = stod(input_a);
    b = stod(input_b);

    outfile <<"x y\n";
    for(int i=0; i<12; i++){
        double x = i*0.1;
        outfile << x <<' ' <<(a*sin(x)+b*cos(x)) <<endl;
    }

    infile.close();
    outfile.close();

    return 0;
}