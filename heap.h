//
#ifndef CS1103_PC2_201902_HEAP_H
#define CS1103_PC2_201902_HEAP_H

#include <fstream>
#include <vector>
#include <deque>

template <class T>
class heap
{
private:
    std::vector<T> data;

    void heapify(std::vector<T> &data_list, T i)
    {
        int vector_size = data_list.size();

        int largest = i;
        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;

        if (left_child < vector_size && data_list[left_child] > data_list[largest])
            largest = left_child;

        if (right_child < vector_size && data_list[right_child] > data_list[largest])
            largest = right_child;

        if (largest != i)
        {
            iter_swap(data_list.begin()+i, data_list.begin() + largest);
            heapify(data_list, largest);
        }

    }
public:
    explicit heap(std::vector<T> data_list)
    {
        data = data_list;
        heapify(data, 0);

    }

    explicit heap(std::deque <T> data_list)
    {
        for (auto value = data_list.cbegin(); value != data_list.cend(); ++value)
            data.push_back(*value);
        heapify(data, 0);
    }

    T get_max()
    {
        return data[0];
    }

    void insert(T item)
    {
        data.push_back(item);
        heapify();
    }

    void insert(T items, ...)
    {

    }
    void print()
    {
        for (auto &item : data)
            std::cout << item << std::endl;
    }
};

#endif //CS1103_PC2_201902_HEAP_H

