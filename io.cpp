/// \file  io.cpp
/// \brief Implementation of functions for parsing and exporting the sorted array to a file.

#include "io.h"
#include "sorts.h"
#include <fstream>
#include <chrono>
#include <algorithm>
#include <stdexcept>

// /// \copydoc parserCSV()
vector<Flower> parserCSV(string filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Cannot open CSV file: " + filename);
    }

    vector<Flower> tmp_vector;
    string line;

    if (!getline(file, line)) {
        return tmp_vector;
    }

    string name, color, smell, regions_str;
    vector<string> regions;

    while(getline(file, line)) {
        regions.clear();
        int ind1 = -1, ind2 = -1, ind3 = -1; 

        for (int i = 0; i < line.size(); ++i) {
            if (line[i] == ',') {
                if (ind1 == -1) {
                    ind1 = i;
                } else if (ind2 == -1) {
                    ind2 = i;
                } else {
                    ind3 = i;
                    break;
                }
            }
        }

        name = line.substr(0, ind1);
        color = line.substr(ind1 + 1, ind2 - ind1 - 1);
        smell = line.substr(ind2 + 1, ind3 - ind2 - 1);
        regions_str = line.substr(ind3 + 3, line.size() - 2 - ind3 - 3);

        ind1 = -1, ind2 = -1;

        for (int j = 0; j < regions_str.size(); ++j) {
            if (regions_str[j] == ',') {
                if (ind1 == -1) {
                    ind1 = j;
                } else {
                    ind2 = j;
                    break;
                } 
            }
        }

        if (ind1 == -1) {
            string region1 = regions_str;
            regions.push_back(region1);
        } else if (ind2 == -1) {
            string region1 = regions_str.substr(1, ind1 - 2);
            string region2 = regions_str.substr(ind1 + 3, regions_str.size() - ind1 - 4);
            regions.push_back(region1);
            regions.push_back(region2);
        } else {
            string region1 = regions_str.substr(1, ind1 - 2);
            string region2 = regions_str.substr(ind1 + 3, ind2 - ind1 - 4);
            string region3 = regions_str.substr(ind2 + 3, regions_str.size() - ind2 - 4);
            regions.push_back(region1);
            regions.push_back(region2);
            regions.push_back(region3);
        }

        Flower tmp(name, color, smell, regions);
        tmp_vector.push_back(tmp);
    }

    return tmp_vector;
}

// /// \copydoc saveRes()
void saveRes(const std::vector<Flower>& source, long size) {
    vector<Flower> tmp1 = source;
    vector<Flower> tmp2 = source;
    vector<Flower> tmp3 = source;
    vector<Flower> tmp4 = source;

    string size_str = to_string(size);
    string base = "/Users/ekaterinagridneva/Desktop/hse/mp/sorted_data/" + size_str;

    string pathSelect, pathHeap, pathQuick, pathSort;
    pathSelect = base + "_selectSort.txt";
    pathHeap = base + "_heapSort.txt";
    pathQuick = base + "_quickSort.txt";
    pathSort = base + "_sort.txt";

    ofstream fout("/Users/ekaterinagridneva/Desktop/hse/mp/info_time.txt", ofstream::app);
    if (!fout.is_open()) {
        throw std::runtime_error("Cannot open file for writing");
    }

    fout << "Datasets" << size << ":" << endl;

    ofstream fout1(pathSelect);
    if (!fout1.is_open()) {
        throw std::runtime_error("Cannot open file for writing: " + pathSelect);
    }

    Flower* data1 = tmp1.data();

    auto start = chrono::high_resolution_clock::now();
    selectSort(data1, size);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    fout << "1. Selection sort time: " << duration.count() << endl;

    for (long i = 0; i < size; ++i) {
        fout1 << data1[i].GetName() << " " << data1[i].GetColor() << " " << data1[i].GetSmell();

        int cntReg = data1[i].GetRegions().size();

        for (int j = 0; j < cntReg; ++j) {
            fout1 << " " << data1[i].GetRegions()[j];
        }
        fout1 << endl;
    }
    fout1.close();

    ofstream fout2(pathHeap);
    if (!fout2.is_open()) {
        throw std::runtime_error("Cannot open file for writing: " + pathHeap);
    }

    Flower* data2 = tmp2.data();

    start = chrono::high_resolution_clock::now();
    heapSort(data2, size);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    fout << "2. Heap sort time: " << duration.count() << endl;

    for (long i = 0; i < size; ++i) {
        fout2 << data2[i].GetName() << " " << data2[i].GetColor() << " " << data2[i].GetSmell();
        int cntReg = data2[i].GetRegions().size();
        for (int j = 0; j < cntReg; ++j) {
            fout2 << " " << data2[i].GetRegions()[j];
        }
        fout2 << endl;
    }
    fout2.close();

    ofstream fout3(pathQuick);
    if (!fout3.is_open()) {
        throw std::runtime_error("Cannot open file for writing: " + pathQuick);
    } 

    Flower* data3 = tmp3.data();

    start = chrono::high_resolution_clock::now();
    quickSort(data3, size);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    fout << "3. Quick sort time: " << duration.count() << endl;

    for (long i = 0; i < size; ++i) {
        fout3 << data3[i].GetName() << " " << data3[i].GetColor() << " " << data3[i].GetSmell();
        int cntReg = data3[i].GetRegions().size();
        for (int j = 0; j < cntReg; ++j) {
            fout3 << " " << data3[i].GetRegions()[j];
        }
        fout3 << endl;
    }
    fout3.close();

    start = chrono::high_resolution_clock::now();
    sort(tmp4.begin(), tmp4.end());
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    fout << "4. Sort time: " << duration.count() << endl;

    ofstream fout4(pathSort);
    if (!fout4.is_open()) {
        throw std::runtime_error("Cannot open file for writing: ");
    }

    Flower* data4 = tmp4.data();

    for (long i = 0; i < size; ++i) {
        fout4 << data4[i].GetName() << " " << data4[i].GetColor() << " " << data4[i].GetSmell();
        int cntReg = data4[i].GetRegions().size();
        for (int j = 0; j < cntReg; ++j) {
            fout4 << " " << data4[i].GetRegions()[j];
        }
        fout4 << endl;
    }
    fout4.close();

    fout << endl << endl;
    fout.close();
}

