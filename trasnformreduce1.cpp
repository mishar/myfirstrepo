#include <array>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <string>
//using namespace std;

int main()
{
  std::array coll{3, 1, 7, 5, 4, 1, 6, 3};
  std::unordered_map<int, std::string> umap;
  umap[1] = "Mishar";
  umap[2] = " jAVED";
  for (const auto &[key,val] : umap) {
      std::cout << key << " :" << val << std::endl;
  }

  auto twice = [] (int v) { return v*2; };
  
  // process sum of doubled values of elements:
  std::cout << "sum of doubles: "
       << std::transform_reduce(coll.cbegin(), coll.cend(),  // range
                                0,
                                std::plus{}, twice)
       << '\n';

  // process sum of squared values:
  std::cout << "sum of squared: "
       << std::transform_reduce(coll.cbegin(), coll.cend(),  // range
                                0L,
                                std::plus{},
                                [] (auto v) {
                                  return v * v;
                                })
       << '\n';
}
