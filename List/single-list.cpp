#include <iostream>


using namespace std;

template <typename T>
class List
{
private:
	template <typename T>
	class Node
	{
	public:
		T data;
		Node* pnext;
		Node(T data = T(), Node* pnext = nullptr)
		{
			this->data = data;
			this->pnext = pnext;
		}
	};

	int Size;
	Node<T>* head;
public:
	T GetSize()
	{
		return Size;
	}
	void push_back(T data);
	List();
	void Clear();
	void pop_front();
	void pop_back();
	void push_front(T data);
	T& operator[](int index);
	int insert(T data, int index);
	void removeAt(int index);

};

template <typename T>
List<T>::List()
{
	this->head = nullptr;
	this->Size = 0;
}

template <typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = head;
		while (current->pnext != nullptr)
		{
			current = current->pnext;
		}
		current->pnext = new Node<T>(data);

	}
	Size++;
}

template <typename T>
T& List<T>::operator[](int index)
{
	Node<T>* current = head;
	int count = 0;
	while (current != nullptr)
	{
		if (count == index)
		{
			return current->data;
		}
		count += 1;
		current = current->pnext;
	}
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pnext;
	delete temp;
	Size--;
}

template <typename T>
void List<T>::Clear()
{
	while (Size)
	{
		pop_front();
	}
}

template <typename T>
void List<T>::pop_back()
{
	Node<T>* current = head;
	while (current->pnext != nullptr)
	{
		current = current->pnext;
	}
	delete current;
	Size--;
}

template <typename T>
void List<T>::push_front(T data)
{
	Node<T>* temp = head;
	temp = new Node<T>(data, head);
	head = temp;
	Size++;
}

template <typename T>
int List<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
		return 0;
	}
	int count = 0;
	Node<T>* current = head;
	while (current != nullptr)
	{
		if (count == index - 1)
		{
			Node<T>* next = current->pnext;
			current->pnext = new Node<T>(data, next);
			Size++;
			return 0;
		}
		current = current->pnext;
		count++;
	}

}

template <typename T>
void List<T>::removeAt(int index)
{
	Node<T>* current = head;
	int count = 0;
	while (current != nullptr)
	{
		if (count == index - 1)
		{
			Node<T>* temp = current->pnext;
			current->pnext = (current->pnext)->pnext;
			delete temp;
			Size--;
		}
		count++;
		current = current->pnext;
	}
}