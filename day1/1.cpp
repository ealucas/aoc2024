#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>

int main() {
    std::vector<int> listA;
    std::vector<int> listB;

    // read lists
    int a, b;
    while (std::cin >> a >> b) {
        listA.push_back(a);
        listB.push_back(b);
    }

    // sort lists
    std::sort(listA.begin(), listA.end());
    std::sort(listB.begin(), listB.end());
   
    // calculate distances & numbers frequency in the second list
    int totalDistance = 0;
    std::map<int, int> map;

    for (int i = 0; i < listA.size(); ++i) {
      totalDistance += std::abs(listA[i] - listB[i]);
      map[listB[i]]++;
    }

    std::cout << totalDistance << std::endl;
    
    // calculate similarity score

    int similarityScore = 0;
    for (int i : listA){
      similarityScore += i *  map[i];
    }
    
    std::cout << similarityScore << std::endl;

    return 0;
}
