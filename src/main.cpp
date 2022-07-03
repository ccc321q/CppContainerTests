
#include <array>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>

void print_array(const std::array<int, 4>& arr_to_print)
{
    for (int i : arr_to_print) // by value
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

void sorted_array()
{
    std::array<int, 4> my_arr = {2, 4, 3, 54};

    std::cout << "Unsorted array:" << std::endl;
    print_array(my_arr);

    std::sort(my_arr.begin(), my_arr.end());

    std::cout << "Sorted array:" << std::endl;
    print_array(my_arr);
}

void chrono()
{
    std::cout << "Chrono: starting timing of 1 billion additions..." << std::endl;

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    for (int i = 0; i < 1000000000; i++)
    {
        ;
    }
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "elapsed seconds: " << elapsed_seconds.count() << std::endl;
}

void testVectorIntCopy(unsigned int size)
{
    std::vector<unsigned int> vec1, vec2;
    std::chrono::time_point<std::chrono::system_clock> start, end;

    vec1.reserve(size);
    vec2.reserve(size);

    // Fill vector
    for (unsigned int i = 0; i < size; ++i)
    {
        vec1.push_back(i);
    }

    // Test copy
    start = std::chrono::system_clock::now();
    vec2 = vec1;
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed seconds: " << elapsed_seconds.count() << std::endl;
}


int main()
{
    //sorted_array();
    //chrono();
    testVectorIntCopy(1000000);
    testVectorIntCopy(10000000);
}
