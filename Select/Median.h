#include <vector>
#include <utility>

class Median{
    static int Partition(std::vector<int> & numbers, int start, int end);
    static int RandomizedPartition(std::vector<int> & numbers, int start, int end);
    public:
    static int Minimum(std::vector<int> numbers);
    static int Maximium(std::vector<int> numbers);
    static std::pair<int, int> MinMax(std::vector<int> numbers);
    static int Select(std::vector<int> & numbers, int start, int end, int k);
};