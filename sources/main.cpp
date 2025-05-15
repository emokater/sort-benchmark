/**
 * \file  main.cpp
 * \brief Entry point: reading multiple datasets, sorting them, and saving the results.
 *
 * Iterates through CSV files with different array sizes specified
 * in the `sizes` array. For each file:
 * 1. Calls parserCSV to load data into a vector of Flower objects.
 * 2. Calls saveRes to sort the data, save the result, and measure execution time.
 */

#include "../headers/io.h"
#include <string>
#include <vector>

int main() {
    vector<Flower> tmp;
    string base = "/Users/ekaterinagridneva/Desktop/hse/mp/sort-benchmark/datasets/dataset_";
    string sizes[10] = {"100", "200", "500", "1000", "2000", "5000", "10000", "20000", "50000", "100000"};
    
    for (int i = 0; i < 10; ++i) {
        string path = base + sizes[i] + ".csv" ;
        tmp = parserCSV(path);
        saveRes(tmp, tmp.size());
    }

    return 0;
}