#include <iostream>
#include "include/hash_map.h"

int main()
{
    HashMap<int, int> map;

    map.insert(1, 100);
    map.insert(2, 200);
    map.insert(3, 300);

    std::cout << "Size: " << map.size() << '\n';
    std::cout << "Capacity: " << map.capacity() << '\n';
    std::cout << "Load Factor: " << map.loadFactor() << '\n';

    std::cout << "Key 1: " << map.get(1) << '\n';
    std::cout << "Key 2: " << map.get(2) << '\n';
    std::cout << "Key 3: " << map.get(3) << '\n';

    if (map.contains(2))
    {
        std::cout << "Key 2 exists.\n";
    }

    map.remove(2);

    std::cout << "After removing key 2\n";
    std::cout << "Size: " << map.size() << '\n';

    if (!map.contains(2))
    {
        std::cout << "Key 2 removed successfully.\n";
    }

    map.clear();

    std::cout << "After clear()\n";
    std::cout << "Size: " << map.size() << '\n';
    std::cout << "Is Empty: " << std::boolalpha << map.isEmpty() << '\n';

    return 0;
}