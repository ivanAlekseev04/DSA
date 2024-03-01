#include <iostream>

// Simple rule: every time you use "cin >>", then just call "cin.ignore()" for proper use of "getline(char* str, int size, char delim)"
// (!) After "getline()" you don't need to call "cin.ignore()"

struct Student {
    char name[11] = {};
    int points = 0;
};

int main() {
    int size;

    cin >> size;

    Student* arr = new Student[size];

    cin.ignore();

    char name[11]{};
    for(int i = 0; i < size; i++) {
        cin.getline(name, 10);

        strcpy(arr[i].name, name);
    }

    // cin.ignore(); // Will produce stuck and will work as a cin >> does

    int val = 0;
    for(int i = 0; i < size; i++) {
        cin >> val;

        arr[i].points = val;
    }

    for(int i = 0; i < size; i++) {
        cout << arr[i].name << " " << arr[i].points << '\n';
    }

    // When using N times "getline()", after every call use cin.ignore()
    /*
      string first, second;
      getline(std::cin, first);
      cin.ignore();
      getline(std::cin, second);
    */
}
