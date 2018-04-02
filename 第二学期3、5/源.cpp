#include<iostream>
using namespace std;

template<class T>

struct Node

{

	T data;

	struct Node<T>* next;

};

template <class T>
class LinkList

{

public:

	LinkList();//无参构造函数

			   //	LinkList(T a[], int n); //有参构造函数，使用含有n个元素的数组a初始化单链表

	~LinkList(); //析构

	void PrintList();    //打印

						 //	int GetLength();     //获取长度

						 //	Node<T>* Get(int i);    //查找

						 //	int Locate(T x);      //定位

						 //	void Insert(int i, T x);     //插入

						 //	T Delete(int i);     //删除

	void deleteDuplicates(); //删除重复元素




private:

	Node<T> *front;    //头指针

};

//定义无参构造函数
template<class T>
LinkList<T>::LinkList()
{
	int len;
	T in;
	cin >> len;
	front = new Node<T>;
	front->data = len;
	Node<T> * r = front;
	for (int i = 0; i < len; i++)
	{
		cin >> in;
		r->next = new Node<T>;
		r = r->next;
		r->data = in;

	}
	r->next = NULL;
	r = NULL;
}
//定义析构函数
template<class T>
LinkList<T>::~LinkList()
{
	Node<T> *r = front;
	while (r)
	{
		r = front->next;
		delete front;
		front = r;
	}
}
//定义遍历函数
template<class T>
void LinkList<T>::PrintList()
{
	if (front->next == NULL)
	{
		cout << "empty";
	}
	else
	{
		Node<T> *s = front->next;
		while (s)
		{
			cout << s->data << " ";
			s = s->next;
		}
	}

}

//定义删除重复元素函数
template<class T>
void LinkList<T>::deleteDuplicates()
{
	Node<T> * p = front;


	while (p->next&&p->next->next)
	{
		bool isIt = false;
		T now = p->next->data;
		Node<T> * q = p->next;
		while (q->next)
		{

			if (now == q->next->data)
			{
				isIt = true;
				Node<T> * t = q->next->next;
				delete q->next;
				q->next = t;
				t = NULL;
			}
			else
			{
				q = q->next;
			}
		}

		q = NULL;
		if (isIt)
		{
			Node<T> *temp = p->next->next;
			delete p->next;
			p->next = temp;
			temp = NULL;
		}
		else
		{
			p = p->next;
		}
	}
	p = NULL;

}
int main()

{

	LinkList <int>L; //初始化单链表

	L.deleteDuplicates();    //删除单链表中的重复元素

	L.PrintList();  //打印链表数值
					//	system("pause");
	return 0;

}
