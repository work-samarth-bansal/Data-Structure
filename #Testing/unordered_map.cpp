#include <iostream>
#include <unordered_map>

int main() {
    std::string s = "example";
    std::unordered_map<char, int> umap;

    for (auto x : s)
        umap[x]++;

    for (auto x : umap)
        std::cout << x.first << " " << x.second << std::endl;

    return 0;
}
