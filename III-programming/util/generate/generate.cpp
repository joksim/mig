#include "generate.h"
#include <cstdlib>
namespace MIG {
    auto generator = []() -> uint { return rand() % 10000; };

    ::std::vector<int> generate_random_vector_values(uint num, int range_from=0, int range_to=10000) {
        std::vector<int> v(num);
        generate(v.begin(), v.end(), generator);
        return v;
    }
}