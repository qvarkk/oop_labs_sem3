#ifndef ITEM_H
#define ITEM_H

class List;

class Item {
	friend class List;
private:
	List* list;
	Item* next;
	Item* prev;
public:
	Item(const Item*);
	Item();
	~Item();
	void SetList(List*);
	void SetNext(Item*);
	void SetPrev(Item*);
	Item* GetNext() const;
	Item* GetPrev() const;
	List* GetList() const;
};

#endif