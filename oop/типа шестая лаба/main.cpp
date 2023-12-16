#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "subj.h"

int main(void) {
    SubjList list;

    Base* item;
    int buffInt;
    std::string buffStr;
    do {
        std::cout << "1. Add Item\n2. Count\n3. Print List\n4. Print Item\n5. Search By Name\n6. Search By Distance\n7. Sort List\n8. Insert\n9. Delete\n10. Clear\n> ";
        std::cin >> buffInt;
        switch (buffInt) {
            case 1:
                std::cout << "Enter item type" << std::endl;\
                std::cout << "1. Star\n2. Planet\n> " << std::endl;
                std::cin >> buffInt;
                if (buffInt == 1 || buffInt == 2) {
                    item = Base::Create((ItemType)buffInt);
                    item->Input();
                    list.Add(item);
                    std::cout << "Item was added!\n" << std::endl;
                } else {
                    std::cout << "Wrong item type!\n" << std::endl;
                }
                break;
            case 2:
                std::cout << "There\'s " << list.Count() << " items in list\n" << std::endl;
                break;
            case 3:
                list.Print();
                break;
            case 4:
                std::cout << "Enter index: ";
                std::cin >> buffInt;
                item = (Base*)list.GetItem(buffInt);
                if (item) {
                    item->Print();
                }
                break;
            case 5:
                std::cout << "Enter name: ";
                std::cin >> buffStr;
                list.SearchByName(buffStr);
                break;
            case 6:
                {
                    std::cout << "Enter the interval";
                    int start = -1;
                    int end = -1;
                    std::cin >> start;
                    std::cin >> end;
                    list.SearchByDistance(start, end);
                    break;
                }
            case 7:
                list.Sort();
                break;
            case 8:
                std::cout << "Enter item type" << std::endl;\
                std::cout << "1. Star\n2. Planet\n> " << std::endl;
                std::cin >> buffInt;
                if (buffInt == 1 || buffInt == 2) {
                    item = item->Create((ItemType)buffInt);
                    item->Input();
                    list.Add(item);
                    std::cout << "Item was created!\n" << std::endl;
                } else {
                    std::cout << "Wrong item type!\n" << std::endl;
                }
                std::cout << "Enter insert index: ";
                std::cin >> buffInt;
                list.Insert(item, buffInt);
                std::cout << "Item was inserted!\n" << std::endl;
                break;
            case 9:
                std::cout << "Enter index: ";
                std::cin >> buffInt;
                list.Delete(buffInt);
                break;
            case 10:
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
