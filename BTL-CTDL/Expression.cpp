#include<iostream>
#include<cmath>
#include<iomanip>

//#include<stack>
//#include "sllStack.cpp"
#include "arrayStack.cpp"

#ifndef __Expression__cpp
#define __Expression__cpp

using namespace std;

class Expression{
	private:
		string out; 	 //bien dau vao
		int temp;		 //bien luu gia tri tam thoi
		double value;	 //bien luu gia tri cuoi cung
	public:
		// ham tao de khoi tao gia tri cho cac bien
		Expression(string x); 
		// ham Operation tra ve ket qua phu thuoc vao toan tu: +, -, *, /, ^
		double Operation(double a, double b, char p);
		// ham Calculated xu ly chuoi ky tu dau vao thanh ket qua cuoi cung
		void Calculated();
		// ham display de in ket qua ra man hinh
		void Display();
};

Expression::Expression(string x)
{
	temp = 0;
	value = 0.0;
	this->out = x;
}

double Expression::Operation(double a, double b, char p)
{
	if(p == '+'){
		return a+b;
	}
	if(p == '-'){
		return a-b;
	}
	if(p == '*'){
		return a*b;
	}
	if(p == '/'){
		return 1.0*a/b;
	}
	if(p == '^'){
		return pow(a, b);
	}
}

void Expression::Calculated()
{
	Stack<double> s;
	for(int i=0; i < out.length(); i++){
		if(out[i] == ' '){
			continue;
		}
		if('0' <= out[i] && out[i] <= '9'){
			temp = temp*10 + ((int)out[i]-(int)'0');
			if(out[i+1] == ' '){
				s.push(temp*1.0);
				temp = 0;
			}
		}
		if(out[i] == '+' || out[i] == '-' || out[i] == '*' || out[i] == '/' || out[i] == '^'){
			double number = s.top();
			s.pop();
			s.top() = Operation(s.top(), number, out[i]);
		}
	}
	value = s.top();
}

void Expression::Display()
{
	cout << setprecision(2) << fixed << value;
}

#endif
