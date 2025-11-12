#include <iostream>
#include <cmath>

using namespace std;

class Point{
private:
    double x, y;

public:
    Point() {};

    // START 本题提交时从这里开始，之前的部分无需提交

    void setPoint(double a, double b){
        x = a;
        y = b;
    }

    void display(){
        cout <<"Point(" <<x <<"," <<y <<")" <<endl;
    }

    double getSum(){
        return (x+y);
    }

    double getDistance(){
        return sqrt(x*x + y*y);
    }


    // END 本题提交到这里结束，之后的部分无需提交
};

int main(){

    Point p;

    double a, b;

    cin >> a >> b;

    p.setPoint(a, b); // 设置点坐标

    p.display(); // 显示点坐标

    cout << p.getSum() << endl; // 输出坐标和

    cout << p.getDistance() << endl; // 输出距离

    return 0;
}