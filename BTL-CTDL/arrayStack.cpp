#ifndef __arrayStack__cpp
#define __arrayStack__cpp

template <class type>
class Stack{
	
	private:
		//thuoc tinh element de luu tong so phan tu trong stack
		//thuoc tinh capacity dun de the hien kha nang luu tru cua mang
		int element, capacity;
		// mang 1 chieu kieu du lieu tuy chon de luu tru cac phan tu
		type *array;

	public:
		
		Stack() // phuong thuc khoi tao de khoi tao cac gia tri
		{
			element = 0;
			capacity = 0;
			array = 0;
		}
		
		int size() // phuong thuc size de tra ve so phan tu hien co trong stack
		{
			return element;
		}
		
		bool empty() // phuong thuc empty kiem tra xem stack hien tai co phan tu khong
		{
			if(size() == 0){
				return true;
			} else return false;
		}
		
		type &top() // phuong thuc top tra ve gia tri tren cung cua stack
		{
			return array[element-1];
		}
		
		void push(type x) // phuong thuc push de them phan tu vao tren cung stack
		{
			if(element == capacity){
				capacity = capacity * 2 + 1;
				type *temp = new type[capacity];
				for(int i=0; i<element; i++){
					temp[i] = array[i];
				}
				if(array == 0){
					delete []array;
				}
				array = temp;
			}
			array[element++] = x;
		}
		
		void pop() // phuong thuc pop de xoa phan tu tren cung cua stack
		{
			element--;
		}
		
		~Stack() // ham huy de xoa bo nho khi huy doi tuong
		{
			delete []array;
		}
		
};
#endif
