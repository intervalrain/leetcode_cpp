#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

class Template {
  private:
    string pattern;
    unordered_map<string, string> registry;

    unordered_set<string> Collect(string key) {
        size_t left = 0;
        size_t right = -1;
        unordered_set<string> res;
        while ((left = key.find('%', right+1)) != string::npos) {
            right = key.find('%', left+1);
            int len = right-left-1;
            res.insert(key.substr(left, len));
        }
        return res;
    }

    string Replace(string v, string key, string val) {
        string res = v;
        string placeholder = "%" + key + "%";
        size_t pos = 0;
        while ((pos = res.find(placeholder, pos)) != string::npos) {
            res.replace(pos, placeholder.size(), val);
            pos += val.size();
        }
        return res;
    }

    bool Valid() {
        unordered_set<string> st;
        for (const auto& [key, val] : registry) {
            st.insert(key);
            for (const auto& next : Collect(key)) {
                st.insert(next);
            }
        }
        for (const auto& next : Collect(pattern)) {
            st.insert(next);
        }
        return st.size() == registry.size();
    }

    bool PreHandle() {
        unordered_map<string, unordered_set<string>> graph;
        unordered_map<string, int> indegree;

        queue<string> q;
        vector<string> order;

        for (const auto& [key, val] : registry) {
            graph[key] = Collect(val);
            indegree[key] = graph[key].size();
            if (indegree[key] == 0) {
                q.push(key);
            }
        }

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string curr = q.front();
                q.pop();
                order.push_back(curr);
                for (const auto& v : graph[curr]) {
                    if (--indegree[v] == 0) {
                        registry[v] = Replace(v, curr, registry[curr]);
                        q.push(v);
                    }
                }
            }
        }
        if (registry.size() != order.size()) {
            return false;
        }
        return true;
    }
    // A:[]    0
    // B:[A,E] 2
    // C:[E]   1
    // D:[F]   1
    // E:[]    0
    // F:[]    0
    // order: A,E,F,C,D,B

  public:
    Template(const string& pattern) {
        this->pattern = pattern;
    }

    void Register(const string& key, const string& val) {
        registry[key] = val;
    }
// A
// B->A,E
// C->E
// D->F
//
// A: "hello"
// B: "{A} {E}"
// C: "is {E}"
// D: "are {F}s"
// E: "Bob"
// F: "Car"
//
// A: "hello"
// B: "hello Bob"
// C: "is Bob"
// D: "are Cars"
// E: "Bob"
// F: "Car"
//
// pattern: "{B}, {E} {C}; {F}s {D}."
//             ^  ^
//  result: "hello Bob, {E} {C}; {F}s {D}."
// hello Bob, Bob is Bob; Cars are Cars.
    void Query() {
        if (!Valid()) {
            cout << "Error! (Key not register)" << endl;
            return;
        }

        if (!PreHandle()) {
            cout << "Error! (Infinite loop)" << endl;
            return;
        }
        string res;

        size_t left = 0;
        size_t right = -1;
        while ((left = pattern.find('%', right+1)) != string::npos) {
            int len = left-right-1;
            if (len)
                res += pattern.substr(right+1, len);
            right = pattern.find('%', left+1);
            if (right == string::npos) {
                cout << "Error! (Parenthesis not complete) " << endl;
                return;
            }
            string key = pattern.substr(left+1, right-left-1);
            res += registry[key];
        }
        res += pattern.substr(right+1);
        cout << res << endl;
    }
};
