#include "LRU.hpp"

int main(){
    LRU_cache lru(100);
    lru.put("1", "1_");
    lru.put("2", "2_");
    lru.get("1");
    lru.put("qewtyiqrqweirfgfhdv", "ksjdfguysfdctgcguydsguy_");
    lru.erase("qewtyiqrqweirfgfhdv");
    std::cout << lru.get("qewtyiqrqweirfgfhdv") << std::endl;

    return 0;
}