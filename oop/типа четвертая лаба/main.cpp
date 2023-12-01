#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

const char* const menuActions[7] = { "(none)", "Add Item", "Count", "Print List", "Insert", "Delete", "Clear" };
// const char* const typeNames[3] = { "(unknown)", "Star", "Planet" };

int main(void) {
    List list;

    int buffInt;
    do {
        std::cout << "1. Add Item\n2. Count\n3. Print List\n4. Insert\n5. Delete\n6. Clear\n> ";
        std::cin >> buffInt;
        switch (buffInt) {
        case 1:
            list.Add(new Item);
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
            list.Insert(new Item, buffInt);
            std::cout << "Item was inserted!\n" << std::endl;
            break;
        case 5:
            std::cout << "Enter index: ";
            std::cin >> buffInt;
            list.Delete(buffInt);
            break;
        case 6:
            list.Clear();
            std::cout << "List was cleared\n" << std::endl;
            break;
        case -1:
            return 0;
            break;
        default:
            std::cout << "Wrong option!\n" << std::endl;
            break;
        }
    } while (1);
}
