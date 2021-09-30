#include <iostream>
#include <cassert>
#include <queue>

template<class T>
struct QUEUE {
private:
	struct Node {
		T data;
		Node *next;
		Node() : next(nullptr) {}
		Node(T data) : data(data), next(nullptr) {}
	};
	Node *head;
	Node *tail;
	int Size;
public:
	static const char *className() {
		return "QUEUE";
	}
	QUEUE() : head(nullptr), tail(nullptr), Size(0) {}
	void push(T data);
	void pop();
	T &front();
	T &back();
	T &operator [] (int idx);
	void print();
	int size();
};

template<class T>
void QUEUE<T>::push(T data) {
	if(tail) {
		tail->next = new Node(data);
		tail = tail->next;
	}
	else {
		head = new Node(data);
		tail = head;
	}
	Size++;
}

template<class T>
void QUEUE<T>::pop() {
	if(head) {
		if(head != tail) {
			head = head->next;
			Size--;
		}
		else {
			head = nullptr;
			tail = nullptr;
		}
	}
}

template<class T>
T &QUEUE<T>::front() {
	return head->data;
}

template<class T>
T &QUEUE<T>::back() {
	return tail->data;
}

template<class T>
T &QUEUE<T>::operator[] (int idx) {
	assert(idx >= 0 && idx < Size);
	Node *temp = head;
	while(idx--) temp = temp->next;
	return temp->data;
}

template<class T>
void QUEUE<T>::print() {
	Node *temp = head;
	while(temp) {
		std::cout << temp->data << (temp == tail ? '\n' : ' ');
		temp = temp->next;
	}
}

template <class T>
int QUEUE<T>::size() {
	return Size;
}

int main() {

	return 0;
}