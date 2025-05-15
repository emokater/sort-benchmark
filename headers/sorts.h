/// \file  sorts.h
/// \brief Implementation of various sorting algorithms (selection sort, heap sort, and quick sort), as well as the auxiliary function mySwap.

#ifndef SORTS_H
#define SORTS_H

/// \brief   Auxiliary swap function.
/// \param x First array element.
/// \param y Second array element.
template <typename T> void mySwap(T& x, T& y) {
    T temp = x;
    x = y;
    y = temp;
}

/// \brief       Selection Sort algorithm.
/// \tparam      T Any type supporting < and = operators.
/// \param data  Array of size elements.
/// \param size  Number of elements.
template<class T> void selectSort(T data[], long size) {
    T x; // min el
    long k; // his index
    for (long i = 0; i < size - 1; ++i) {
        x = data[i];
        k = i;
        for (long j = i + 1; j < size; ++j) {
            if (data[j] < x) {
                k = j;
                x = data[j];
            }
        }

        data[k] = data[i];
        data[i] = x;
    }
}

/// \brief      "Heapify" operation for heap.
/// \tparam     T Any type supporting > operator.
/// \param data Heap array with n elements.
/// \param k    Index of the root of the subheap.
/// \param n    Size of the array.
template<class T> void downHeap(T data[], long k, long n) {
    while (true) {
        long left = 2 * k + 1;
        long right = 2 * k + 2;
        long largest = k;

        if (left < n && data[left] > data[largest]) {
            largest = left;
        }

        if (right < n && data[right] > data[largest]) {
            largest = right;
        }

        if (largest == k) { break; }

        mySwap(data[k], data[largest]);
        k = largest;
    }
}

/// \brief      Heap Sort algorithm.
/// \tparam     T Any type supporting > operator.
/// \param data Array of size elements.
/// \param size Number of elements.
template<class T> void heapSort(T data[], long size) {
    long i;

    for(i = size/2 - 1; i >= 0; --i) {
        downHeap(data, i, size - 1);
    }

    for(i = size - 1; i > 0; --i) {
        mySwap(data[i], data[0]);
        downHeap(data, 0, i - 1);
    }
}

/// \brief      Quick Sort algorithm.
/// \tparam     T Any type supporting <, > and assignment.
/// \param data Pointer to the first element of the array.
/// \param n    Number of elements.
template<class T> void quickSort(T* data, long n) {
    long i = 0, j = n - 1;
    T p = data[n >> 1];

    while (i <= j) {
        while (data[i] < p) { i++; }
        while (data[j] > p) { j--; }

        if (i <= j) {
            mySwap(data[i], data[j]);
            i++;
            j--;
        }
    }

    if (i < n) {
        quickSort(data + i, n - i);
    }

    if (j > 0) {
        quickSort(data, j + 1);
    }
}

#endif