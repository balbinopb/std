#include "DLL.h"


int main() {
    List songList;
    address P, found;
    int n;
    string title;

    createList(songList);

    cout << "Enter number of songs: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "Enter song title " << i + 1 << ": ";
        getline(cin, title);
        if (createNewElmt(title, P)) {
            insertLast(songList, P);
        }
    }

    cout << "Enter song to search: ";
    getline(cin, title);
    found = findLagu(title, songList);

    if (found != NULL) {
        cout << "Song '" << title << "' found in the list." << endl;
    } else {
        cout << "Song '" << title << "' not found in the list." << endl;
    }

    return 0;
}
