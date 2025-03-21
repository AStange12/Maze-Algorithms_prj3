//
// Created by aaron on 3/21/2025.
//

#ifndef MAZE3_MYDICTIONARY_H
#define MAZE3_MYDICTIONARY_H

#include <unordered_map>
#include <string>
#include "position.h"

using namespace std;

class MyDictionary {
private:
    unordered_map<string, Position*> dict;

public:
    // Inserts a key-value pair into the dictionary
    void insert(string key, Position* value) {
        dict[key] = value;
    }

    // Finds a value by key; returns nullptr if not found
    Position* find(string key) {
        for (pair<string, Position*> pair : dict) {  // Explicit type
            if (pair.first == key) {
                return pair.second;  // Return the corresponding Position* if key is found
            }
        }
        return nullptr;  // Return nullptr if key is not found
    }

    // Removes an entry from the dictionary
    void remove(string key) {
        dict.erase(key);
    }

    // Checks if a key exists in the dictionary
    bool exists(const std::string& key) const {
        return dict.find(key) != dict.end();
    }


};


#endif //MAZE3_MYDICTIONARY_H
