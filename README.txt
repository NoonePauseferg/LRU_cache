[DISTRIBUTION]  : https://docs.google.com/spreadsheets/d/1SBwOcvxeQsJSgYD9QoMnDZc5UwioBjbNM4z8Ojmn25Y/edit#gid=0
[INFO]          : https://en.wikipedia.org/wiki/Cache_replacement_policies#Least_recently_used_(LRU)
[TASK]          : LRU-кэш

####################################################################################################
    Реализуйте LRU-кэш с парами ключ-значение (std::string).
    В конструкторе кэша указывается максимальный размер в байтах. Должны быть реализованы методы:
    - Put(K, V) - положить новый <K,V> или обновить старый
    - Erase(K)
    - Get(K) - получить V по ключу. Должен работать за O(1).

    Если K.size() + V.size() > MAX, то в операции отказывается, но при этом контейнер должен остаться
    в том же состоянии, что и до нее.

    Иначе - происходит вытесенение “старых” элементов (к ключам которых дольше всего не обращались) до
    того, как будет достаточно места. Обратите внимание, Get() “омолаживает” ключ.
 #################################################################################################### 


 [FUNCTIONAL REQUIREMENTS]:
    1) Initialization : LRUcache_ a(size_t N);
    2) Put, Erase, Get methods as explained above
    3) cout method with and without complexity
    3) easy to track memory usage, need method that shows how much memory used and how much bytes are free

[NON-FUNCTIONAL REQUIREMENTS]:
    1) Time complexity for Get(K) is O(1) -> hash tables
    2) Need fast erase and put -> linked list (old elements at the tail, fresh elements at the begin)
    3) Need to track memory of cache 

[REALIZATION DETAILS]:
    1) LinkedList, need two methods add to the end and remove node; head and tail - dummy nodes
    2) ...

 #################################################################################################### 

 Сборка:
    mkdir tmp
    cd tmp
    cmake ..
    make