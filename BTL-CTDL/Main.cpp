#include<iostream>
#include "Expression.cpp"

//#include<stack>
//#include "sllStack.cpp"
#include "arrayStack.cpp"

using namespace std;

class KyPhapBaLan{
	private:
		// khai bao 2 bien ky tu. Bien "in" de lay du lieu dau vao, bien "out" de luu du lieu dau ra
		string in, out;
		
	public:
		
		KyPhapBaLan(string x) // phuong thuc khoi tao KyPhapBaLan de gan du lieu cho bien "in"
		{
			this->in = x;
		}
		
		int UuTien(char x) // ham UuTien de xet do uu tien cua cac phep toan
		{
			if(x == '^'){
				return 4;
			}
			if(x == '*' || x == '/'){
				return 3;
			}
			if(x == '+' || x == '-'){
				return 2;
			}
			if(x == '(' || x == ')'){
				return 1;
			}
		}
				
		void HauTo() // phuong thuc HauTo de chuyen cac bieu thuc tu trung to sang hau to
		{
			Stack<char> s;
			for(auto i:in){
				if((i < '0' || i > '9') && i != '+' && i != '-' && i != '*' && i != '/' 
										&& i != '(' && i != ')' && i != '^'){
					cout << "Error.";
					exit(0);
				}
				if('0' <= i && i <= '9'){
					out.push_back(i);
				} else {
					out.push_back(' ');
					if(i == '('){
						s.push(i);
					} else {
						if(i == ')'){
							while(s.top() != '('){
								out.push_back(s.top());
								s.pop();
							}
							s.pop();
						} else {
							while(!s.empty() && UuTien(i) <= UuTien(s.top())){
								out.push_back(s.top());
								s.pop();
								out.push_back(' ');
							}
							s.push(i);
						}
					}
				}
			}
			out.push_back(' ');
			while(!s.empty()){
				out.push_back(s.top());
				out.push_back(' ');
				s.pop();
			}
		}
		
		string getOut() // phuong thuc getOut dung de lay ra bieu thuc hau to
		{
			return out;
		}
};

int main()
{
	string input, output;
	cout << "Nhap vao 1 bieu thuc: ";
	getline(cin, input);
	KyPhapBaLan KyPhapBaLan(input);
	KyPhapBaLan.HauTo();
	output = KyPhapBaLan.getOut();
	cout << "Bieu thuc sau khi chuyen tu trung to sang hau to: " << output << endl;
	
	Expression bieuThuc(output);
	bieuThuc.Calculated();
	cout << "Ket qua cua bieu thuc la: ";
	bieuThuc.Display();
	return 0;
}

