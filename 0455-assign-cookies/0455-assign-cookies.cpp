// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         sort(g.begin(), g.end());
//         sort(s.begin(), s.end());

//         int i = g.size() - 1; // largest greed child
//         int j = s.size() - 1; // largest cookie
//         int count = 0;
//         while (i >= 0 && j >= 0) {
//             if (s[j] >= g[i]) {
//                 count++;
//                 i--;
//                 j--;
//             } else {
//                 // largest cookie bhi is child ko satisfy nahi kar sakti
//                 i--;
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0; // child pointer
        int j = 0; // cookie pointer
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                i++; // child satisfied
            }
            j++; // move to next cookie
        }
        return i;
    }
};        