#include <bits/stdc++.h>
using namespace std;

struct Person {
    size_t initialIndex;
    size_t enter;
    size_t exit;
    long long tableIndex; 

    Person(size_t initialIndex, size_t enter, size_t exit) {
        this->initialIndex = initialIndex;
        this->enter = enter;
        this->exit = exit;
    }
    Person() : enter(0), exit(0), initialIndex(0), tableIndex(-1) {}
};

struct Cmp1 {
    bool operator()(const Person& f, const Person& s) const {
        return f.enter > s.enter;
    }
};
struct Cmp2 {
    bool operator()(const Person& f, const Person& s) const {
        return f.exit > s.exit;
    }
};

int countFriends;

priority_queue<Person, vector<Person>, Cmp1> friendsToEnter;
priority_queue<Person, vector<Person>, Cmp2> friendsToExit;
priority_queue<size_t, vector<size_t>, greater<size_t>> freeTables;

int main() {    
    cin >> countFriends;

    size_t enterT, exitT;
    for(int i = 0; i < countFriends; i++) {
        cin >> enterT >> exitT;
        friendsToEnter.push(Person(i, enterT, exitT));
    }

    size_t searchedIndex;
    cin >> searchedIndex;

    freeTables.push(0);

    size_t traversedTables = 0;
    while(!friendsToEnter.empty()) {
        auto curFriend = friendsToEnter.top();
        friendsToEnter.pop();

        traversedTables++;

        while(!friendsToExit.empty() && 
            curFriend.enter >= friendsToExit.top().exit) {

            freeTables.push(friendsToExit.top().tableIndex);
            friendsToExit.pop();
        }

        if(curFriend.initialIndex == searchedIndex) {
            cout << freeTables.top() << '\n';
            break;
        } else {
            curFriend.tableIndex = freeTables.top();
            freeTables.pop();

            freeTables.push(traversedTables);

            friendsToExit.push(curFriend);
        }
    }
}
