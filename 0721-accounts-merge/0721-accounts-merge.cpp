class Solution {
public:
    vector<int> parent, rank1;

    int find(int x){
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int s1 = find(x);
        int s2 = find(y);

        if(s1 == s2) return;

        if(rank1[s1] < rank1[s2]){
            parent[s1] = s2;
        }
        else if(rank1[s1] > rank1[s2]){
            parent[s2] = s1;
        }
        else{
            parent[s2] = s1;
            rank1[s1]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        parent.resize(n);
        rank1.resize(n,0);

        for(int i=0; i<n; i++)
            parent[i] = i;

        unordered_map<string,int> mp;

        for(int i=0; i<n; i++){

            for(int j=1; j<accounts[i].size(); j++){

                string mail = accounts[i][j];

                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }
                else{
                    Union(i, mp[mail]);
                }
            }
        }

        unordered_map<int, vector<string>> merged;

        for(auto &it : mp){

            string mail = it.first;
            int accNo = it.second;

            int root = find(accNo);

            merged[root].push_back(mail);
        }

        vector<vector<string>> ans;

        for(auto &it : merged){

            int root = it.first;
            vector<string> mails = it.second;

            sort(mails.begin(), mails.end());

            vector<string> temp;

            temp.push_back(accounts[root][0]);

            for(auto &mail : mails){
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};