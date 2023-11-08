#include <stdlib.h>
#include <iostream>
#include "list.h"

Item::Item(const Item* it) {
	SetNext(it->GetNext());
	SetPrev(it->GetPrev());
}

Item::Item() {
	SetNext(nullptr);
	SetPrev(nullptr);
}

Item::~Item() {
	if (list->GetIndex(this) != -1) list->Remove(list->GetIndex(this));
}

void Item::SetList(List* l) {
	list = l;
}

void Item::SetNext(Item* it) {
	next = it;
}

void Item::SetPrev(Item* it) {
	prev = it;
}

List* Item::GetList() const {
	return list;
}

Item* Item::GetNext() const {
	return next;
}

Item* Item::GetPrev() const {
	return prev;
}