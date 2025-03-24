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
    /* Inserts a key-value pair into the dictionary.
    * @param key: string, the key to be inserted into the dictionary (parent position as a string).
    * @param value: Position*, the pointer to the Position object to be associated with the key.
    */
    void insert(string key, Position* value) {
        dict[key] = value;
    }

    /* Finds a value by key in the dictionary.
    * @param key: string, the key to search for in the dictionary (parent position as a string).
    * @return: Position*, a pointer to the Position object associated with the key, or nullptr if the key is not found.
    */
    Position* find(string key) {
        for (pair<string, Position*> pair : dict) {
            if (pair.first == key) {
                return pair.second;  // Return the corresponding Position* if key is found
            }
        }
        return nullptr;  // Return nullptr if key is not found
    }

    /* Removes an entry from the dictionary by key.
     * @param key: string, the key of the entry to be removed from the dictionary (parent position as a string).
     */
    void remove(string key) {
        dict.erase(key);
    }

    /* Checks if a key exists in the dictionary.
     * @param key: const std::string&, the key to check for existence in the dictionary (parent position as a string).
     * @return: bool, true if the key exists in the dictionary, false otherwise.
     */
    bool exists(const std::string& key) const {
        return dict.find(key) != dict.end();
    }


};


#endif //MAZE3_MYDICTIONARY_H
