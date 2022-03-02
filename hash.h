#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <utility>

template<typename KEY_CLASS, typename VALUE_CLASS>
class HASH_NODE {
public:
	KEY_CLASS key;
	VALUE_CLASS value;
	HASH_NODE *left, *right;
	HASH_NODE() : key(), value(), left(nullptr), right(nullptr) {}
	HASH_NODE(const KEY_CLASS &key) : key(key), value(), left(nullptr), right(nullptr) {}
	HASH_NODE(const KEY_CLASS &key, const VALUE_CLASS &value) : key(key), value(value), left(nullptr), right(nullptr) {}
	void operator = (const VALUE_CLASS &obj) { this->value = obj; }
};

template<typename KEY_CLASS, typename VALUE_CLASS>
class hash {
private:
	HASH_NODE<KEY_CLASS, VALUE_CLASS> *head;
public:
	hash() : head(nullptr) {}
	HASH_NODE<KEY_CLASS,VALUE_CLASS>* insert(KEY_CLASS key, VALUE_CLASS value);
	VALUE_CLASS& find(const KEY_CLASS &key);
	VALUE_CLASS& operator [] (const KEY_CLASS& obj);
};


template<typename KEY_CLASS, typename VALUE_CLASS>
HASH_NODE<KEY_CLASS,VALUE_CLASS>* hash<KEY_CLASS, VALUE_CLASS>::insert(KEY_CLASS key, VALUE_CLASS value) {
	if(!head) {
		head = new HASH_NODE<KEY_CLASS, VALUE_CLASS>(key,value);
		return head;
	}
	HASH_NODE<KEY_CLASS, VALUE_CLASS> *curr = head;
	while(true) {
		if(key > curr->key) {
			if(curr->right)
				curr = curr->right;
			else {
				curr->right = new HASH_NODE<KEY_CLASS, VALUE_CLASS>(key,value);
				return curr->right;
			}
		}
		else if(key < curr->key) {
			if(curr->left)
				curr = curr->left;
			else {
				curr->left = new HASH_NODE<KEY_CLASS, VALUE_CLASS>(key,value);
				return curr->left;
			}
		}
		else {
			curr->value = value;
			return curr;
		}
	}
}

template<typename KEY_CLASS, typename VALUE_CLASS>
VALUE_CLASS& hash<KEY_CLASS, VALUE_CLASS>::find(const KEY_CLASS &key) {
	HASH_NODE<KEY_CLASS, VALUE_CLASS> *curr = head;
	while(curr) {
		if(key == curr->key) {
			return curr->value;
		}
		else if(key > curr->key)
			curr = curr->right;
		else
			curr = curr->left;
	}
	return insert(key,VALUE_CLASS())->value;
}

template<typename KEY_CLASS, typename VALUE_CLASS>
VALUE_CLASS& hash<KEY_CLASS, VALUE_CLASS>::operator [] (const KEY_CLASS &key) {
	return find(key);
}

#endif