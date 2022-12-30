#include "LRU.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define FILE_LEN_MAX 10

int main(int argc, char *argv[])
{
    unsigned int file_mask = atoi(argv[1]);
    std::string filename = argv[2];
    std::vector<int> arr(FILE_LEN_MAX+1);
    std::string s;
    std::ifstream file(filename);

    int i = 0;
    while (std::getline(file, s) && (i < FILE_LEN_MAX))
    {
        const int tmp{std::stoi(s)};
        arr[i] = tmp;
        
        ++i;
    }
    file.close();

    // main program
    LRU_cache lru(arr[0]);
    lru.put("1", "1_");
    lru.put("2", "2_");
    lru.get("1");
    lru.put("qewtyiqrqweirfgfhdv", "ksjdfguysfdctgcguydsguy_");
    lru.erase("qewtyiqrqweirfgfhdv");
    std::cout << lru.get("qewtyiqrqweirfgfhdv") << std::endl;

    return 0;
}
