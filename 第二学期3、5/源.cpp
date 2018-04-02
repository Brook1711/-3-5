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

	LinkList();//�޲ι��캯��

			   //	LinkList(T a[], int n); //�вι��캯����ʹ�ú���n��Ԫ�ص�����a��ʼ��������

	~LinkList(); //����

	void PrintList();    //��ӡ

						 //	int GetLength();     //��ȡ����

						 //	Node<T>* Get(int i);    //����

						 //	int Locate(T x);      //��λ

						 //	void Insert(int i, T x);     //����

						 //	T Delete(int i);     //ɾ��

	void deleteDuplicates(); //ɾ���ظ�Ԫ��




private:

	Node<T> *front;    //ͷָ��

};

//�����޲ι��캯��
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
//������������
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
//�����������
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

//����ɾ���ظ�Ԫ�غ���
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

	LinkList <int>L; //��ʼ��������

	L.deleteDuplicates();    //ɾ���������е��ظ�Ԫ��

	L.PrintList();  //��ӡ������ֵ
					//	system("pause");
	return 0;

}
