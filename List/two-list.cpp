#include <iostream>

using namespace std;

template<typename T>
class List
{
private:
	class Node
	{
	public:
		Node* pnext;
		Node* pprev;
		T data;
		Node(T data = T(), Node* pprev = nullptr, Node* pnext = nullptr) :data(data), pprev(pprev), pnext(pnext) {};
	};
	Node* head;
	Node* tail;
	int size;
public:
	List();
	void push_back(T data);
	T& operator[](int index);

};

template<typename T>
List<T>::List()
{
	head = tail = nullptr;
	size = 0;
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node(data);
		tail = head;
	}
	else
	{
		Node* current = head;
		while (current->pnext != nullptr)
		{
			current = current->pnext;
		}
		current->pnext = new Node(data,current);
	}
	size++;
}
template <typename T>
T& List<T>::operator[](int index)
{
	if (index < (size - 1) / 2)
	{
		int count = 0;
		Node* current = head;
		while (current != nullptr)
		{
			if (count == index)
			{
				return current->data;
			}
			current = current->pnext;
			count++;
		}
	}
}

int main()
{
	List<int> arr;
	arr.push_back(32);
	arr.push_back(31254);
	cout << arr[1];
}