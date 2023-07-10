#include <fstream>
#include <vector>
#include <cstdint>
#include <iostream>
#include <filesystem>

int main(int argc, char* argv[])
{
    if (argc <= 1 || !std::filesystem::exists(argv[1]))
    {
        std::cerr << "You need to provide a valid file as the first argument."
            << std::endl; 
        return 1;
    }

    std::ifstream file(argv[1], std::ios::binary);

    // Stop eating new lines in binary mode!!!
    file.unsetf(std::ios::skipws);

    // get its size:
    std::streampos fileSize;

    file.seekg(0, std::ios::end);
    fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // reserve capacity
    std::vector<uint8_t> vec;
    vec.reserve(fileSize);

    // read the data:
    vec.insert(vec.begin(),
               std::istream_iterator<uint8_t>(file),
               std::istream_iterator<uint8_t>());

    const int number_per_line{15};

    for (int i = 0; i < vec.size(); ++i)
    {
        if (i % (number_per_line - 1) == 0 && i != 0)
        {
            std::cout << (unsigned int)vec[i] << ",";
            std::cout << std::endl;
        }
        else
        {
            std::cout << (unsigned int)vec[i] << ", ";
        }
    }

    std::cout << "Size is: " << vec.size() << std::endl;

    return 0;
}
