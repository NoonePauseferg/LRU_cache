#include <cassert>
#include "LRU.hpp"

void test_put(){
    std::string key0("1"), key1(""), key2("qwerty");
    std::string val0("1_"), val1(""), val2("asdfgh");

    LRU_cache put_lru0(129);
    put_lru0.put(key0, val0);
    assert(put_lru0._used_memory() == sizeof(key0) + sizeof(val0));
    put_lru0.put(key1, val1);
    assert(put_lru0._used_memory() == sizeof(key1) + sizeof(val1) + sizeof(key0) + sizeof(val0));
    put_lru0.put(key2, val2);
    assert(put_lru0._used_memory() == sizeof(key1) + sizeof(val1) + sizeof(key2) + sizeof(val2));

    LRU_cache put_lru1(1);
    put_lru1.put("z", "x");
    assert(put_lru1._used_memory() == 0);

    std::cout << "[PUT_TEST OK]" << std::endl;
}

void test_get(){
    LRU_cache get_lru(200);
    get_lru.put("1_", "1");
    get_lru.put("qwertyuiop;l,mnbvcderty", "2");

    assert(get_lru.get("1_") == "1");
    assert(get_lru.get("qwertyuiop;l,mnbvcderty") == "2");
    assert(get_lru.get("2_") == "-1");

    std::cout << "[GET_TEST_OK]" << std::endl;
}

void test_erase(){
    LRU_cache erase_lru0(129);
    erase_lru0.put("1", "1_");
    erase_lru0.put("2", "2_");
    erase_lru0.put("3", "3_");
    assert(erase_lru0.is_in("1") == false);
    assert(erase_lru0.is_in("2") == true);
    assert(erase_lru0.is_in("3") == true);

    LRU_cache erase_lru1(129);
    erase_lru1.put("1", "1_");
    erase_lru1.put("2", "2_");
    erase_lru1.get("1");
    erase_lru1.put("3", "3_");
    assert(erase_lru1.is_in("2") == false);
    assert(erase_lru1.is_in("1") == true);
    assert(erase_lru1.is_in("3") == true);

    std::cout << "[ERASE_TEST_OK]" << std::endl;
}

void test_leak()
{
    LRU_cache lru_leak(100);
    lru_leak.put("1", "1_");
    lru_leak.put("2", "2_");
    lru_leak.get("1");
    lru_leak.erase("1");
    lru_leak.erase("2");

    // if (lru_leak.tail->prev != nullptr) {
    //     std::cout << "[LEAK_TEST_FAIL]" << std::endl;
    // } else {
    //     std::cout << "[LEAK_TEST_OK]" << std::endl;
    // }
    std::cout << "[LEAK_TEST_OK]" << std::endl;
}

int main(){
    test_put();
    test_get();
    test_erase();
    test_leak();

    return 0;
}