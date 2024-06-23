#include "Vector.hpp"
#include <fstream>

template <typename T> void writeVector(std::ofstream &ofs, const Vector<T> &arr)
{
    size_t size = arr.getSize();
    ofs.write((char *)&size, sizeof(size));
    for (size_t i = 0; i < arr.getSize(); i++)
    {
        arr[i].writeToFile(ofs);
    }
}

template <typename T> void readVector(std::ifstream &ifs, Vector<T> &arr)
{
    size_t size;
    ifs.read((char *)size, sizeof(size));
    Vector<T> temp(size);

    for (size_t i = 0; i < size; i++)
    {
        temp[i].readFromFile(ifs);
    }

    arr = std::move(temp);
}