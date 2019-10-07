class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        queue<int> q;
        vector<int> res(deck.size(),0);
        for(int i=0;i<deck.size(); i++) q.push(i);
        for(int i=0; i<deck.size(); i++) {
            res[q.front()] = deck[i];
            q.pop();
            if(!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        return res;
    }
};