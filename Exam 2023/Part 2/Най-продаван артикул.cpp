#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using u64 = unsigned long long;

struct OrdPair {
    i64 first;
    i64 second;
    
    bool operator<(const OrdPair& other) const {
        return first < other.first;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    i64 N;
    cin >> N;
    
    vector<OrdPair> changes;
    changes.reserve(N);
    
    unordered_map<i64, i64> counts;
    i64 maxCount = 0;
    i64 maxCountAt = -1;
    
    for(i64 i = 0; i < N; i++){
        i64 id, time;
        cin >> id >> time;

        counts[id]++;

        if(counts[id] >= maxCount){
            if(maxCountAt != id){
                changes.push_back({time, id});
            }
            
            maxCount = counts[id];
            maxCountAt = id;
        }
    }
    
    // for(auto i : changes) cout << i.second << " at time " << i.first << endl;
    // cout << endl;
    
    i64 Q;
    cin >> Q;
    
    for(i64 t = 0; t < Q; t++){
        i64 time;
        cin >> time;
        
        i64 ans = -1;
        
        auto lastChange = lower_bound(changes.begin(), changes.end(), OrdPair{time, -1});
        
        if(lastChange == changes.end()){
            // after the final sale
            ans = changes[changes.size() - 1].second;
        }else{
            if(lastChange->first == time){
                // exactly after a change
                ans = lastChange->second;
            }else{
                if(lastChange != changes.begin()){
                    // not before first sale, take previous
                    lastChange--;
                    ans = lastChange->second;
                }
            }
        }
        
        cout << ans << '\n';
        
        // cout << "last change for query " << time << " at index " << (lastChange - changes.begin()) << endl;
    }
    
    return 0;
}
