class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Store all words for O(1) lookup
        unordered_set<string> words(wordList.begin(), wordList.end());

        // If end word doesn't exist, transformation is impossible
        if (!words.count(endWord))
            return 0;

        queue<string> q;
        q.push(beginWord);
        // Mark beginWord as visited
        words.erase(beginWord);
        int level = 1;
        while (!q.empty()) {
            int size = q.size();
            // Process all words at the current transformation level
            while (size--) {
                string word = q.front();
                q.pop();

                // If we reached the target word
                if (word == endWord)
                    return level;

                // Try changing every character
                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];

                    // Replace with every lowercase letter
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == original)
                            continue;
                        word[i] = ch;

                        // Valid transformation found
                        if (words.count(word)) {
                            q.push(word);
                            words.erase(word); // mark visited
                        }
                    }
                    // Restore original character
                    word[i] = original;
                }
            }
            // One transformation level completed
            level++;
        }
        return 0;
    }
};