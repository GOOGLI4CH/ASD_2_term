#pragma once
#include <iostream>

class person
{
public:
	int number;
	std::string owner;
	person(int num = 0, std::string lodgers = "")
	{
		this->number = num;
		this->owner = lodgers;
	}
};

template<class Data, class Key>
class HashTable
{
private:
	class Node
	{
	public:
		Data value;
		Key key;
		Node* next;
		Node* prev;

		Node(Data value, Key key, Node* next = nullptr, Node* prev = nullptr)
		{
			this->value = value;
			this->key = key;
			this->next = next;
			this->prev = prev;
		}
	};

	Node** table;
	int size;
	int capacity;

	int hash(const Key& key) const
	{
		return static_cast<int>(key) % capacity;
	}

public:
	HashTable(const int);
	~HashTable();
	void insert(const Data&, const Key&);
	void printNode(Node*);
	void remove(const Key&);
	void print();
	Node* search(const Key&);

	friend std::ostream& operator<<(std::ostream& out, const person& value);
};