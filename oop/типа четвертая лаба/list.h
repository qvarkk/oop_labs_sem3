#ifndef LIST_H
#define LIST_H

#include "item.h"

class List {
private:
	struct Item* head;
	struct Item* tail;
public:
	List(const List*);
	List();
	~List();
	void SetHead(Item*);
	void SetTail(Item*);
	Item* GetHead() const;
	Item* GetTail() const;
	void Add(Item*);
	int Count();
	void PrintList();
	struct Item* GetItem(int);
	int GetIndex(Item*);
	void Insert(Item*, int);
	struct Item* Remove(int);
	void Delete(int);
	void Clear();
};

#endif 