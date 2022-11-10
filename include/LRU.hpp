//g++ -std=c++20 LRU.cpp -o LRU && ./LRU
#pragma once
#include <iostream>
#include <unordered_map>

class LRU_cache{

private:
    struct Node{
        std::string key;
        std::string val;
        Node* next = nullptr;
        Node* prev = nullptr;
        size_t size;
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    size_t capacity;
    size_t used_memory;
    std::unordered_map<std::string, Node*> node_map;

public:
    LRU_cache(size_t sz);
    virtual ~LRU_cache();

    std::string get(const std::string& key);
    void put(const std::string& key, const std::string& val);
    void erase(const std::string& key);
    size_t _used_memory() const;
    bool is_in(const std::string& key) const;

private:
    void add(Node* node){
        Node* head_next = head->next;
        head->next = node;
        node->prev = head;
        node->next = head_next;
        head_next->prev = node;
    }

    void remove(Node* node) {
        Node* next_node = node->next;
        Node* prev_node = node->prev;
        next_node->prev = prev_node;
        prev_node->next = next_node;
    }
};
