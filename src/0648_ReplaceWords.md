## 648. Replace Words
<span style="color:orange">Medium</span>

In English, we have a concept called **root**, which can be followed by some other word to form another longer word - let's call this word **derivative**. For example, when the **root** `"help"` is followed by the word `"ful"`, we can form a derivative `"helpful"`.

Given a `dictionary` consisting of many **roots** and a `sentence` consisting of words separated by spaces, replace all the derivatives in the sentence with the **root** forming it. If a derivative can be replaced by more than one **root**, replace it with the **root** that **has the shortest length**.

Return *the `sentence`* after the replacement.

 

**Example 1:**
```
Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
```
**Example 2:**
```
Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"
```
 
**Constraints:**

+ `1 <= dictionary.length <= 1000`
+ `1 <= dictionary[i].length <= 100`
+ `dictionary[i]` consists of only lower-case letters.
+ `1 <= sentence.length <= 10^6`
+ `sentence` consists of only lower-case letters and spaces.
+ The number of words in `sentence` is in the range `[1, 1000]`
+ The length of each word in `sentence` is in the range `[1, 1000]`
+ Every two consecutive words in `sentence` will be separated by exactly one space.
+ `sentence` does not have leading or trailing spaces.

**My solution:**
+ hash table
```cpp
class Solution {
public:
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        map<int, unordered_set<string>> map;
        int minLen = INT_MAX;
        for (const auto& word : dictionary) {
            int len = word.size();
            map[len].insert(word);
            minLen = min(minLen, len);
        }
    
        auto arr = split(sentence, ' ');
        
        vector<string> res;
        for (const auto& word : arr) {
            if (word.size() <= minLen) {
                res.push_back(word);
            } else {
                bool used = false;
                for (const auto& [n, set] : map) {
                    if (set.count(word.substr(0, n))) {
                        res.push_back(word.substr(0, n));
                        used = true;
                        break;
                    }
                }
                if (!used) {
                    res.push_back(word);
                }
            }
        }
        return join(res, " ");
    }
    string join(vector<string>& res, string del) {
        string s;
        for (int i = 0; i < res.size()-1; i++) {
            s += res[i] + del;
        }
        s += res.back();
        return s;
    }
    
    vector<string> split(string s, char del) {
        vector<string> res;
        int n = s.size();
        int left = 0, right = 0;
        while (right < n) {
            if (s[right] == del) {
                res.push_back(s.substr(left, right-left));
                left = right+1;
            }
            right++;
        }
        if (right > left) res.push_back(s.substr(left, right-left));
        return res;
    } 
};
```