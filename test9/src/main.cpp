#include "../includes/huff.hpp"
#include <fstream>

int main(int argc, char *argv[])
{
    std::string filename;
    if (argc != 2)
    {
        filename = "input.txt";
    }
    else
    {
        filename = argv[1];
    }

    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open())
    {
        std::cout << "Error: Could not open file " << filename << std::endl;
        return 1;
    }
    std::string input;
    std::map<char, long long> freq;
    while (file.good())
    {
        char c = file.get();
        if (file.eof())
        {
            break;
        }
        input += c;
        freq[c]++;
    }
    file.close();
    std::cout << "Input: " << input << "\n";
    HuffmanTree tree(freq);
    std::string encoded = tree.encode(input);
    std::ofstream outfile(filename + ".huff", std::ios::binary);
    outfile.write(encoded.data(), encoded.size());
    outfile.close();
    std::string decoded = tree.decode(encoded);
    std::cout << "Decoded: " << decoded << "\n";
    file.close();
    std::cout << "\n\n";
    tree.show();
    return 0;
}