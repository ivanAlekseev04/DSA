#include <bits/stdc++.h>
using namespace std;

struct Stock {
    size_t frequency;
    size_t lastSoldTime;

    Stock() : frequency(0), lastSoldTime(0) {}
    Stock(size_t frequency, size_t lastSoldTime) : frequency(frequency), lastSoldTime(lastSoldTime) {}
};
struct Input {
    size_t numberStock;
    size_t time;

    Input() : numberStock(0), time(0) {}
    Input(size_t numberStock, size_t time) : numberStock(numberStock), time(time) {}
};

struct Cmp2 {
        bool operator()(const Stock& f, const Stock& s) const {
            if(f.frequency == s.frequency)
                return f.lastSoldTime > s.lastSoldTime; 

            return f.frequency > s.frequency;
        }
};
struct Cmp1 {
    bool operator()(const Input& f, const Input& s) const {
        return f.time > s.time;
    }
};

size_t requestsCount;
priority_queue<size_t, vector<size_t>, greater<size_t>> requestsSorted;
vector<size_t> requests;
unordered_map<size_t, long long> result;

unordered_map<size_t, size_t> lastSold;
unordered_map<size_t, size_t> frequency;

size_t stocksCount;
priority_queue<Input, vector<Input>, Cmp1> input;
map<Stock, size_t, Cmp2> sortedStocks;

void getMostFrequent(size_t tillTime) {
    while(!input.empty()) {
        auto cur = input.top();

        if(cur.time <= tillTime) { // TODO: not sure about "<="
            sortedStocks.erase(Stock(frequency[cur.numberStock], lastSold[cur.numberStock]));
            
            frequency[cur.numberStock]++;
            lastSold[cur.numberStock] = cur.time;
            
            sortedStocks.insert(make_pair(Stock(frequency[cur.numberStock], lastSold[cur.numberStock]), cur.numberStock));

            input.pop();
        } else {
            break;
        }
    }

    if(sortedStocks.empty()) {
        result.insert(make_pair(tillTime, -1));
    } else {
        result.insert(make_pair(tillTime, sortedStocks.begin()->second));
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    cin >> stocksCount;

    for(size_t i = 0, stock = 0, time = 0; i < stocksCount; i++) {
        cin >> stock >> time;
        input.push(Input(stock, time));
    }

    cin >> requestsCount;
    requests = vector<size_t>(requestsCount);

    for(size_t i = 0; i < requestsCount; i++) {
        cin >> requests[i];
        requestsSorted.push(requests[i]);
    }

    while(!requestsSorted.empty()) {
        size_t toProcess = requestsSorted.top();
        requestsSorted.pop();

        getMostFrequent(toProcess);
    }

    for(auto it : requests) {
        cout << result[it] << '\n';
    }
}
