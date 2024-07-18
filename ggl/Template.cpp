#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <regex>

class Template {
public:
    Template(const std::string& pattern) : pattern(pattern) {}

    void Register(const std::string& key, const std::string& val) {
        registry[key] = val;
    }

    void Query() {
        if (!PreHandle()) {
            std::cout << "Error" << std::endl; // Detected an infinite loop
            return;
        }

        std::string result = pattern;
        bool hasUnregisteredPlaceholder;
        do {
            hasUnregisteredPlaceholder = false;
            for (const auto& [key, val] : registry) {
                result = replace(result, key, val);
            }

            std::regex placeholder_regex("%([\\w]+)%");
            std::smatch match;
            std::string::const_iterator searchStart(result.cbegin());
            while (std::regex_search(searchStart, result.cend(), match, placeholder_regex)) {
                std::string placeholder = match[1].str();
                if (registry.find(placeholder) == registry.end()) {
                    hasUnregisteredPlaceholder = true;
                    break;
                }
                searchStart = match.suffix().first;
            }

            if (hasUnregisteredPlaceholder) {
              std::cout << "Error" << std::endl; // Unregistered placeholder found
                return;
            }
        } while (std::regex_search(result, std::regex("%\\w+%")));

        std::cout << result << std::endl;
    }

private:
    std::string pattern;
    std::unordered_map<std::string, std::string> registry;

    bool PreHandle() {
        std::unordered_map<std::string, std::vector<std::string>> graph;
        std::unordered_map<std::string, int> indegree;

        // Build graph and indegree map
        for (const auto& [key, val] : registry) {
            std::regex placeholder_regex("%([\\w]+)%");
            std::smatch match;
            std::string::const_iterator searchStart(val.cbegin());
            while (std::regex_search(searchStart, val.cend(), match, placeholder_regex)) {
                std::string dep = match[1].str();
                graph[dep].push_back(key);
                indegree[key]++;
                searchStart = match.suffix().first;
            }
            if (indegree.find(key) == indegree.end()) {
                indegree[key] = 0;
            }
        }

        // Topological sort using Kahn's algorithm
        std::queue<std::string> q;
        for (const auto& [key, degree] : indegree) {
            if (degree == 0) {
                q.push(key);
            }
        }

        int count = 0;
        std::vector<std::string> sortedOrder;
        while (!q.empty()) {
            std::string node = q.front();
            q.pop();
            sortedOrder.push_back(node);
            count++;
            for (const auto& neighbor : graph[node]) {
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If count doesn't match the number of nodes, there is a cycle
        if (count != indegree.size()) {
            return false;
        }

        // No cycle, reorder the registry based on sorted order
        std::unordered_map<std::string, std::string> sortedRegistry;
        for (const auto& key : sortedOrder) {
            sortedRegistry[key] = registry[key];
        }
        registry = sortedRegistry;

        return true;
    }

    std::string replace(const std::string& str, const std::string& key, const std::string& val) {
        std::string result = str;
        std::string placeholder = "%" + key + "%";
        size_t pos = 0;
        while ((pos = result.find(placeholder, pos)) != std::string::npos) {
            result.replace(pos, placeholder.length(), val);
            pos += val.length();
        }
        return result;
    }
};

