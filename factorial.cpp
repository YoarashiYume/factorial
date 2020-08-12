#include <iostream>
#include <vector>
//#define DEBUG
int main(int argc, char* argv[])
{
    typedef unsigned char byte;
#ifndef DEBUG
    if (argc != 2)
    {
        std::cout << "Only one argument\n";
        return -1;
    }
    int factorialValue = std::atoi(argv[1]);
#else
    int factorialValue = 5;
#endif
    std::vector<byte> result = { 1 };
    unsigned int accumulate = 0;
    for (; factorialValue > 0; --factorialValue)
        for (size_t i = 0; ; ++i)
            if (i < result.size())
            {
                accumulate += (int)result.at(i) * factorialValue;
                result.at(i) = accumulate % 10;
                accumulate /= 10;
                if (accumulate == 0 && i == result.size() - 1)
                   break;
            }
            else
            {
                result.push_back(accumulate % 10);
                accumulate /= 10;
                if (accumulate == 0)
                    break;
            }
    for (auto it = result.rbegin(); it != result.rend(); ++it)
        std::cout << (int)(*it);
    return 0;
}