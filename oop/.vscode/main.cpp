#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

const char* const menuActions[11] = { "(none)", "Add Item", "Count", "Print List", "Delete", "Insert", "Clear", "Exit" };

int DoMenu(const char* const* s, int len) {
    int i;
    for (i = 1; i <= len; i++) {
        std::cout << i << ". " << s[i] << std::endl;
    }
    std::cout << "> ";
    fflush(stdin);
    std::cin >> i;
    return i<0 || i>len ? 0 : i;
}

int main(void) {
    List list;
    Item* item = NULL;

    int buffInt;
    do {
        buffInt = DoMenu(menuActions, 7);
        switch (buffInt) {
	        case 1:
				item = new Item;
				list.Add(item);
	            std::cout << "Item was added!\n" << std::endl;
	            break;
	        case 2:
	            std::cout << "There\'s " << list.Count() << " items in list\n" << std::endl;
	            break;
	        case 3:
	            list.PrintList();
	            break;
	        case 4:
	            std::cout << "Enter index: ";
	            std::cin >> buffInt;
	            list.Delete(buffInt);
	            break;
	        case 5:
	 			std::cout << "Enter index: ";
	 			std::cin >> buffInt;
	 			item = new Item;
	 			list.Insert(item, buffInt);
	            break;
	        case 6:
	            list.Clear();
	            break;
	        case 7:
				return 0;
	        default:
	            std::cout << "Wrong option!\n" << std::endl;
	            break;
        }
    } while (1);
}