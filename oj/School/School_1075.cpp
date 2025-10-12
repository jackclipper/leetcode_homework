#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//最大公约数算法
int gcd(int a, int b){
    if(a == 0){
        return b;
    }
    if(b == 0){
        return a;
    }
    if(a>b){
        return gcd(a%b, b);
    }
    else{
        return gcd(b%a, a);
    }
}

class Fraction{
    private:
    int numerator, denominator;
    public:
    //构造函数
    Fraction(int num=1, int den=1){
        numerator = num;
        denominator = den;
    }
    //赋值函数
    void is(int num, int den){
        numerator = num;
        denominator = den;
    }
    //分数负号默认放到分子上
    //重载+
    Fraction operator+(Fraction other){
        int den_uns = denominator*other.denominator;
        int num_uns = numerator*other.denominator+other.numerator*denominator;
        int gcd_num;
        if(num_uns>=0){
            gcd_num = gcd(den_uns, num_uns);
        }
        else{
            gcd_num = gcd(den_uns, -num_uns);
        }
        Fraction result(num_uns/gcd_num, den_uns/gcd_num);
        return result;
    }
    //重载-
    Fraction operator-(Fraction other){
        int den_uns = denominator*other.denominator;
        int num_uns = numerator*other.denominator-other.numerator*denominator;
        int gcd_num;
        if(num_uns>=0){
            gcd_num = gcd(den_uns, num_uns);
        }
        else{
            gcd_num = gcd(den_uns, -num_uns);
        }
        Fraction result(num_uns/gcd_num, den_uns/gcd_num);
        return result;
    }
    //重载*
    Fraction operator*(Fraction other){
        int den_uns = denominator*other.denominator;
        int num_uns = numerator*other.numerator;
        int gcd_num;
        if(num_uns>=0){
            gcd_num = gcd(den_uns, num_uns);
        }
        else{
            gcd_num = gcd(den_uns, -num_uns);
        }
        Fraction result(num_uns/gcd_num, den_uns/gcd_num);
        return result;
    }
    //重载/
    Fraction operator/(Fraction other){
        int den_uns = denominator*other.numerator;
        int num_uns = numerator*other.denominator;
        int gcd_num;
        if(den_uns<0){
            den_uns = -den_uns;
            num_uns = -num_uns;
        }
        if(num_uns>=0){
            gcd_num = gcd(den_uns, num_uns);
        }
        else{
            gcd_num = gcd(den_uns, -num_uns);
        }
        Fraction result(num_uns/gcd_num, den_uns/gcd_num);
        return result;
    }
    //重载==
    bool operator==(Fraction other){
        if(denominator == other.denominator && numerator == other.numerator){
            return true;
        }
        else{
            return false;
        }
    }
    //返回double类型值
    double exact(){
        return double(numerator)/denominator;
    }
    //返回分子
    int give_num(){
        return numerator;
    }
    //返回分母
    int give_den(){
        return denominator;
    }

    friend ostream& operator<<(ostream& os, Fraction& obj);

};

ostream& operator<<(ostream& os, Fraction& obj){
    os <<obj.give_num() <<'/' <<obj.give_den();
    return os;
}

int main(){
    int n;
    cin >>n;
    string input_first[n][2], input_second[n][2], input_operator[n];
    
    //利用getline读入
    for(int i=0; i<n; i++){
        getline(cin, input_first[i][0], '/');
        getline(cin, input_first[i][1], ' ');
        getline(cin, input_operator[i], ' ');
        getline(cin, input_second[i][0], '/');
        getline(cin, input_second[i][1], '\n');
    }

    //转换数据
    Fraction raw_data[n][2];
    for(int i=0; i<n; i++){
        raw_data[i][0].is(stoi(input_first[i][0]), stoi(input_first[i][1]));
        raw_data[i][1].is(stoi(input_second[i][0]), stoi(input_second[i][1]));
    }

    //处理数据
    cout <<fixed <<setprecision(6); //设置精度
    for(int i=0; i<n; i++){
        if(input_operator[i] == "+"){
            Fraction result = raw_data[i][0]+raw_data[i][1];
            cout <<result <<'(' <<result.exact()  <<')' <<endl;
        }
        else if(input_operator[i] == "-"){
            Fraction result = raw_data[i][0]-raw_data[i][1];
            cout <<result <<'(' <<result.exact()  <<')' <<endl;
        }
        if(input_operator[i] == "*"){
            Fraction result = raw_data[i][0]*raw_data[i][1];
            cout <<result <<'(' <<result.exact()  <<')' <<endl;
        }
        if(input_operator[i] == "/"){
            Fraction result = raw_data[i][0]/raw_data[i][1];
            cout <<result <<'(' <<result.exact()  <<')' <<endl;
        }
    }

    return 0;
}