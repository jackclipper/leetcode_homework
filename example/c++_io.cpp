#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream outfile;
    outfile.open("data.txt", ios::out); //建立文件输出流对象
    /*也可以写成
    * ofstream outfile("data.txt", ios::out | ios::app);
    * 在定义且初始化时打开文件
    * * */
    ifstream infile;
    infile.open("data1.txt", ios::in);  //建立文件输入流对象
    /*也可以写成
    * ifstream infile("data1.txt", ios::in);
    * 在定义且初始化时打开文件
    * * */
    fstream iofile("data1.txt", ios::in | ios::out | ios::binary); //又读又写

    //bool is_open(); 调用成员函数检查

    //void close(); 调用成员函数关闭文件

    /*状态标识符的验证函数
    * eof() 到达文件末尾返回true
    * bad() 出错返回true
    * fail() 除了bad的情况之外，出现格式错误也返回true
    * good() 以上任何一个函数返回true，该函数返回false
    * clear() 重置检查状态
    * * * * * */

    return 0;
}