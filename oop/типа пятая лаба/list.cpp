#include <cstdlib>
#include <iostream>
#include "list.h"
#include "item.h"

List::List(const List* l) {
    SetHead(l->GetHead());
    SetTail(l->GetTail());
}

List::List() {
    SetHead(nullptr);
    SetTail(nullptr);
}

List::~List() {
    Clear();
}

void List::SetHead(Item* item) {
    head = item;
}

void List::SetTail(Item* item) {
    tail = item;
}

Item* List::GetHead() const {
    return head;
}

Item* List::GetTail() const {
    return tail;
}

void List::Add(Item* item) {
    if (GetHead() == nullptr) {
        SetHead(item);
        SetTail(item);
        item->SetNext(nullptr);
        item->SetPrev(nullptr);
    }
    else {
        tail->SetNext(item);
        item->SetPrev(tail);
        SetTail(item);
        item->SetNext(nullptr);
    }
}

int List::Count() {
    int i;
    Item* curr;
    for (curr = head, i = 0; curr; curr = curr->GetNext()) {
        i++;
    }
    return i;
}

void List::PrintList() {
    Item* curr;
    int i = 0;
    for (curr = head; curr != NULL; curr = curr->GetNext()) {
        std::cout << i << ". " << curr << "\t" << curr->GetPrev() << "\t" << curr->GetNext() << std::endl;
        i++;
    }
    std::cout << "\n";
}

Item* List::GetItem(int index) {
    Item* curr;
    int counter = 0;
    for (curr = head; curr; curr = curr->GetNext()) {
        if (counter == index)
            break;
        counter++;
    }
    return curr;
}

int List::GetIndex(Item* item) {
    Item* curr;
    int counter = 0;
    for (curr = head; curr != nullptr; curr = curr->GetNext()) {
        if (curr == item)
            break;
        counter++;
    }
    if (curr) return counter;
    else return -1;
}

void List::Insert(Item* item, int index) {
    Item* itemAtPos = GetItem(index);
    if (itemAtPos == NULL) {
        Add(item);
    }
    else if (index == 0) {
        head->SetPrev(item);
        item->SetNext(head);
        head = item;
        item->SetPrev(nullptr);
    }
    else {
        item->SetNext(itemAtPos);
        item->SetPrev(itemAtPos->GetPrev());
        itemAtPos->GetPrev()->SetNext(item);
        itemAtPos->SetPrev(item);
    }
}

Item* List::Remove(int index) {
    Item* item = GetItem(index);

    std::cout << item << std::endl;

    if (item == nullptr)
        return nullptr;

    if (head == tail) {
        SetHead(nullptr);
        SetTail(nullptr);
    }
    else if (item == head) {
        SetHead(item->GetNext());
        item->GetNext()->SetPrev(nullptr);
    }
    else if (item == tail) {
        SetTail(item->GetPrev());
        item->GetPrev()->SetNext(nullptr);
    }
    else {
        item->GetNext()->SetPrev(item->GetPrev());
        item->GetPrev()->SetNext(item->GetNext());
        item->SetPrev(NULL);
        item->SetNext(NULL);
    }
    item->SetList(nullptr);
    return item;
}

void List::Delete(int index) {
    Item* item = Remove(index);
    if (item) {
        delete item;
        item = nullptr;
    }
}

void List::Clear() {
    while (head) {
        std::cout << "Clearing" << std::endl;
        Delete(0);
    }
}