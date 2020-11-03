#pragma once
#include "TestFrame.h"

#include <iostream>
using namespace std;

template<class Key,class Value>
class HashNode
{
public:
    Key    _key;
    Value  _value;
    HashNode *next;

    HashNode(Key key, Value value)
    {
        _key = key;
        _value = value;
        next = NULL;
    }
    ~HashNode()
    {

    }
    HashNode& operator=(const HashNode& node)
    {
        _key  = node._key;
        _value = node._value;
        next = node.next;
        return *this;
    }
};

class HashFunc
{
public:
	int operator()(const string& key) 
	{
		int hash = 0;
		for (int i = 0;i<key.length();++i)
		{
			hash = hash << 7 ^ key[i];
		}
		return (hash & 0x7FFFFFFF);
	}
};

class EqualKey
{
public:
    bool operator()(const string & A, const string & B)
    {
        if (A.compare(B) == 0)
            return true;
        else
            return false;
    }
};

template<class Key,class Value,class HashFunc,class EqualKey>
class HashMap
{
public:
	HashMap(int size);
	~HashMap();

	bool insert(const Key& key,const Value& value);
	bool del(const Key& key);

	Value& find(const Key& key);

	Value& operator[](const Key& key);
private:
	HashFunc hash;
	EqualKey equal;
	HashNode<Key, Value>**table;
	unsigned int _size;

	Value valueNull;
};


template<class Key,class Value,class HashFunc,class EqualKey>
HashMap<Key, Value, HashFunc, EqualKey>::HashMap(int size) :_size(size), hash(), equal()
{
	//table = new HashNode<Key, Value>*[_size];
	table = new HashNode<Key, Value>*[_size];
	for (unsigned i = 0;i < _size; i++)
	{
		table[i] = nullptr;
	}
}

template<class Key,class Value,class HashFunc,class EqualKey>
HashMap<Key, Value, HashFunc, EqualKey>::~HashMap()
{
	for (unsigned i =0;i <_size;i++)
	{
		HashNode<Key, Value>* currentNUll = table[i];
		while (currentNUll)
		{
			HashNode<Key, Value> *temp = currentNUll;
			currentNUll = temp->next;
			delete temp;
		}
	}

	delete table;
}

template<class Key,class Value,class HashFunc,class EqualKey>
bool HashMap<Key, Value, HashFunc, EqualKey>::insert(const Key& key,const Value& value)
{
	//这里的添加是属于从头结点处的添加
	int index = hash(key) % _size;
	HashNode<Key, Value>* node = new HashNode<Key, Value>(key, value);

	node->next = table[index];

	//移动表头指针
	table[index] = node;
	return true;
}


template <class Key, class Value, class HashFunc, class EqualKey>
bool HashMap<Key, Value, HashFunc, EqualKey>::del(const Key& key)
{
	//只在这一个连上进行删除
    unsigned index = hash(key) % _size;
    HashNode<Key, Value> * node = table[index];
    HashNode<Key, Value> * prev = NULL;
    while (node)
    {
        if (node->_key == key)
        {
            if (prev == NULL)
            {
                table[index] = node->next;
            }
            else
            {
                prev->next = node->next;
            }
            delete node;
            return true;
        }
        prev = node;
        node = node->next;
    }
    return false;
}

template <class Key, class Value, class HashFunc, class EqualKey>
Value& HashMap<Key, Value, HashFunc, EqualKey>::find(const Key& key)
{
    unsigned  index = hash(key) % _size;
    if (table[index] == NULL)
        return valueNull;
    else
    {
        HashNode<Key, Value> * node = table[index];
        while (node)
        {
            if (node->_key == key)
                return node->_value;
            node = node->next;
        }
    }
}


template <class Key, class Value, class HashFunc, class EqualKey>
Value& HashMap<Key, Value, HashFunc, EqualKey>::operator [](const Key& key)
{
    return find(key);
}

void TestHashMap()
{
	cout << "TestHashMap"<<endl;
	HashMap<string, string, HashFunc, EqualKey> hashmap(100);

	hashmap.insert("hello", "world");
	hashmap.insert("hello", "world");
	hashmap.insert("why", "dream");

}

//RegisterStruct TestHashMapRS(&TestHashMap);