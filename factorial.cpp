#include <iostream>
#include <vector>

using byte = std::uint8_t;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Only one argument\n";
        return -1;
    }
    std::int64_t factorialValue = std::atoll(argv[1]);

	//represent the number as an array
    std::vector<byte> result = { 1 };
    std::uint64_t accumulate = 0;
	
    for (; factorialValue > 0; --factorialValue)
        for (size_t i = 0; ; ++i)
            if (i < result.size())
            {
				//complements 'accumulate' var. and store the new value in i pos.
                accumulate += static_cast<std::uint64_t>(result.at(i)) * factorialValue;
                result.at(i) = accumulate % 10;
                accumulate /= 10;
                if (accumulate == 0 && i == result.size() - 1)
                   break;
            }
            else
            {
				//create new pos. and set value
                result.emplace_back(accumulate % 10);
                accumulate /= 10;
                if (accumulate == 0)
                    break;
            }
	//console output
    for (auto it = result.rbegin(); it != result.rend(); ++it)
        std::cout << (int)(*it);
	
    return 0;
}