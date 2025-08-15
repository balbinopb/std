#include "list.h"

int main() {
    List L;
    createList_103012350551(L);

    int menuOption;
    do {
        menuOption = selectMenu_103012350551();
        switch (menuOption) {
            case 1: {
                int n;
                cout << "Enter number of data to add: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    infotype x;
                    cout << "Enter data type (0 = int, 1 = char, 2 = string): ";
                    cin >> x.dataType;
                    if (x.dataType == 0) {
                        cout << "Enter integer: ";
                        cin >> x.intData;
                    } else if (x.dataType == 1) {
                        cout << "Enter character: ";
                        cin >> x.charData;
                    } else if (x.dataType == 2) {
                        cout << "Enter string (visitor name): ";
                        cin >> x.stringData;
                    }
                    createNewElement_103012350551(L, x);
                }
                break;
            }
            case 2:
                showAll_103012350551(L);
                break;
            case 3: {
                address minAddress = findMin_103012350551(L);
                if (minAddress != nullptr) {
                    cout << "Minimum integer value: " << info(minAddress).intData << endl;
                } else {
                    cout << "List contains no integers!" << endl;
                }
                break;
            }
            case 4: {
                int value;
                cout << "Enter integer to insert in the middle: ";
                cin >> value;
                showMiddle_103012350551(L, value);
                break;
            }
            case 5:
                cout << "Consonant percentage: " << consonantPercentage_103012350551(L) << "%" << endl;
                break;
            case 6: {
                int k;
                cout << "Enter K: ";
                cin >> k;
                showFirsttK_103012350551(L, k);
                break;
            }
            case 7: {
                address shortest = shortestName_103012350551(L);
                if (shortest != nullptr) {
                    cout << "Visitor with the shortest name: " << info(shortest).stringData << endl;
                } else {
                    cout << "No visitor names available in the list!" << endl;
                }
                break;
            }
            case 8: {
                int k;
                char c;
                cout << "Enter K: ";
                cin >> k;
                cout << "Enter starting character: ";
                cin >> c;
                showFirstKNameC_103012350551(L, k, c);
                break;
            }
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid option! Try again." << endl;
                break;
        }
    } while (menuOption != 0);

    return 0;
}
