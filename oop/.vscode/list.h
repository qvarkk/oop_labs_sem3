#ifndef LIST_H
#define LIST_M
#include "item.h"

class List {
private:
    Item* head;
    Item* tail;
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
    Item* GetItem(int);
    int GetIndex(Item*);
    Item* Remove(int);
    void Delete(int);
    void Clear();
    void Insert(Item*, int);
};

#endif
#pragma once