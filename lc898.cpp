class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> prev;
        for(int e:arr){
            unordered_set<int> cur;
            cur.insert(e);
            for(int a:prev){
                cur.insert(a|e);
            }
            result.insert(cur.begin(),cur.end());
            prev = cur;
        }
        return result.size();
    }
};