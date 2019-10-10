#include <iostream>
#include "heap.h"
#include <string>
#include <vector>
#include <queue>

int main()
{
    std::vector<int> vector_data;
    std::deque<int> deque_data;

    std::ifstream infile;
    infile.open ("data.txt");
    std::string data;
    while(!infile.eof())
    {
        getline(infile, data, '\n');
        vector_data.push_back(stoi(data));
        deque_data.push_back(stoi(data));
    }
    infile.close();

    heap<int> my_vector_heap(vector_data);
    heap<int> my_deque_heap(deque_data);

    my_deque_heap.print();

    return 0;
}

