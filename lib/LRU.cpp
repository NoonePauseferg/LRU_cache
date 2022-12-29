#include "LRU.hpp"

LRU_cache::LRU_cache(size_t sz){
    head = new Node;
    tail = new Node;
    capacity = sz;
    used_memory = 0;
    head->next = tail;
    tail->prev  = head;
}

LRU_cache::~LRU_cache(){
        for (auto cur : node_map){
            delete cur.second;
        }
        delete head;
        delete tail;
    }

size_t LRU_cache::_used_memory() const{
    return used_memory;
}

bool LRU_cache::is_in(const std::string& key) const{
    if (node_map.find(key) != node_map.end()){
        return true;
    }
    return false;
}

std::string LRU_cache::get(const std::string& key){
        if (node_map.find(key) == node_map.end()){
            return "-1";
        }
        Node* node = node_map[key];
        remove(node);
        add(node);
        return node->val;
    }

void LRU_cache::put(const std::string& key, const std::string& val){
        if (node_map.find(key) != node_map.end()){
            Node* node = node_map[key];
            node->val=val;
            node->size = sizeof(key) + sizeof(val);
            remove(node);
            add(node);
        }
        else{
            size_t cur_size = sizeof(key) + sizeof(val);
            if (cur_size > capacity){
                // std::cout << "[MEMORY OWERFLOW] cur_size: " << cur_size << ",capacity_size: " << capacity << std::endl;
                return;
            }
            while (used_memory + cur_size > capacity){
                Node* cur = tail->prev;
                node_map.erase(cur->key);
                used_memory -= cur->size;
                remove(cur);
                delete cur;
            }
            Node* node = new Node;
            node->key = key;
            node->val = val;
            node->size = cur_size;
            used_memory += cur_size;
            node_map[key] = node;
            add(node);
        }
    }

void LRU_cache::erase(const std::string& key){
    if (node_map.find(key) != node_map.end()){
        Node* node = node_map[key];
        node_map.erase(key);
        remove(node);
        delete node;
    }
}
