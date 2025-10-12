#include <iostream>
#include <cstring>
using namespace std;
const int MAXLEN = 210;

class CHugeInt
{
	string number;

    string bigAdd(const string& num1, const string& num2) const {
        string result1, result;
        int carry = 0;
        int i = num1.length() - 1;
        int j = num2.length() - 1;

        while (i >= 0 || j >= 0 || carry >0){
            int sum = carry; //加进位
            
            // 加num1最后一位
            if(i >= 0){
                sum += num1[i] - '0';
                i--;
            }

            // 加num2最后一位
            if(j >= 0){
                sum += num2[j] - '0';
                j--;
            }

            //计算结果和新的进位
            carry = sum/10;
            result1.append(1, ((sum%10)+'0'));
        }

        // 反转结果
        for(int i=result1.length()-1; i>=0; i--){
            result.append(1, result1[i]);
        }

        // 处理结果为空的情况
        if (result.empty()) {
            result.append(1, '0');
        }

        return result;
    }

    public:
    CHugeInt(int n){
        number = to_string(n);
    }
    CHugeInt(const char* s){
        number = s;
    }
    CHugeInt(const string& in){
        number = in;
    }

    // 拷贝构造函数
    CHugeInt(const CHugeInt& other) : number(other.number) {}

    CHugeInt operator+(const CHugeInt& other) const {
        return CHugeInt(bigAdd(number, other.number));
    }

    CHugeInt operator+(int other) const {
        return operator+(CHugeInt(other));
    }

    CHugeInt& operator+=(const CHugeInt& other) {
        CHugeInt temp = operator+(other);
        number = temp.number;
        return *this;
    }

    CHugeInt& operator+=(int n) {
        CHugeInt temp = operator+(n);
        number = temp.number;
        return *this;
    }

    // 前置++
    CHugeInt& operator++() {
        CHugeInt temp = operator+(1);
        number = temp.number;
        return *this;
    }
    
    // 后置++
    CHugeInt operator++(int) {
        CHugeInt temp = *this;
        operator++();
        return temp;
    }

    //输入运算符重载
    friend ostream& operator<<(ostream& os, const CHugeInt& obj) {
        os << obj.number;
        return os;
    }
};

// 全局函数：int + CHugeInt
CHugeInt operator+(int n, const CHugeInt& obj){
    return CHugeInt(n).operator+(obj);
}

int main()
{
	char s[MAXLEN];
	int n;

	while (cin >> s >> n)
	{
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout << ++b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}

	return 0;
}
