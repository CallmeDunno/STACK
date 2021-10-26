#ifndef __sllStack__cpp
#define __sllStack__cpp

template <class type>
struct node
{
	// khai bao bien element kieu tu chon
	type element;
	// khai bao con tro pNext
	node<type> *pNext;
};

template <class type>
class Stack{
	
	private:
		// khai bao bien numOfEle de luu so phan tu hien co trong stack
		int numOfEle;
		// khai bao con tro pHead
		node<type> *pHead;

	public:
		
		Stack() // ham tao de khoi tao cac gia tri
		{
			numOfEle = 0;
			pHead = 0;
		}
		
		int size() // phuong thuc size de tra ve so phan tu co trong stack
		{
			return numOfEle;
		}
		
		bool empty() // phuong thuc empty kiem tra xem stack hien tai co phan tu khong
		{
			if(pHead == 0){
				return true;
			} else return false;
		}
		
		void push(type x) // phuong thuc push de them phan tu vao tren cung stack
		{
			node<type> *p = new node<type>;
			p->element = x;
			p->pNext = pHead;
			pHead = p;
			numOfEle++;
		}
		
		void pop() // phuong thuc pop de xoa phan tu tren cung cua stack
		{
			pHead = pHead->pNext;
			numOfEle--;
		}
		
		type &top() // phuong thuc top tra ve gia tri tren cung cua stack
		{
			return pHead->element;
		}
		
		~Stack() // ham huy de xoa bo nho khi huy doi tuong
		{
		 	delete pHead;
		}
};

#endif
