#!/usr/bin/env python3
## \file genGraphs.py
## \brief Parses timing data and plots performance of sorting algorithms.

import pandas as pd
import matplotlib.pyplot as plt

## \brief Container for parsed timing data.
data = {
    "Size": [],
    "Selection Sort": [],
    "Heap Sort": [],
    "Quick Sort": [],
    "Sort": []
}

## \brief Read the timing log and fill the data dict.
def parse_timing_file(filepath):
    """
    \details
    Opens the file at \p filepath, reads each line and:
        - If it starts with 'Datasets', extracts dataset size.
        - If it starts with '1', '2', '3' or '4', extracts the corresponding time.
    Populates and returns a dict with keys "Size", "Selection Sort", "Heap Sort", "Quick Sort", "Sort".
    """
    local_data = {
        "Size": [],
        "Selection Sort": [],
        "Heap Sort": [],
        "Quick Sort": [],
        "Sort": []
    }
    with open(filepath, "r") as f:
        lines = f.readlines()
        size = 0
        for line in lines:
            if not line:
                continue
            if "Datasets" in line:
                size = int(line[8:-2])
                local_data["Size"].append(size)
            elif ":" in line:
                _, time = line.split(": ")
                time = float(time)
                if line[0] == "1":
                    local_data["Selection Sort"].append(time)
                elif line[0] == "2":
                    local_data["Heap Sort"].append(time)
                elif line[0] == "3":
                    local_data["Quick Sort"].append(time)
                elif line[0] == "4":
                    local_data["Sort"].append(time)
    return local_data

## \brief Plot sorting algorithms on one graph.
## \param df pandas DataFrame with timing data.
def plotAll(df):
    plt.figure(figsize=(10, 6))
    plt.plot(df["Size"], df["Selection Sort"], label="Selection Sort", color="blue")
    plt.plot(df["Size"], df["Heap Sort"], label="Heap Sort")
    plt.plot(df["Size"], df["Quick Sort"], label="Quick Sort")
    plt.plot(df["Size"], df["Sort"], label="Sort")
    plt.xlabel("Dataset Size")
    plt.ylabel("Time (sec)")
    plt.title("All Sort")
    plt.legend()
    plt.grid(True)
    plt.show()

def plotSelectionSort(data):
    plt.figure(figsize=(10, 5))
    plt.plot(data["Size"], data["Selection Sort"], label="Selection Sort", color="red")
    plt.xlabel("Dataset Size")
    plt.ylabel("Time (sec)")
    plt.title("Only Selection Sort")
    plt.grid(True)
    plt.legend()
    plt.tight_layout()
    plt.show()

def plotOthers(data):
    plt.figure(figsize=(10, 5))
    plt.plot(data["Size"], data["Heap Sort"], label="Heap Sort", color="green")
    plt.plot(data["Size"], data["Quick Sort"], label="Quick Sort", color="blue")
    plt.plot(data["Size"], data["Sort"], label="Sort", color="red")
    plt.xlabel("Dataset Size")
    plt.ylabel("Time (sec)")
    plt.title("Others")
    plt.grid(True)
    plt.legend()
    plt.tight_layout()
    plt.show()


data = parse_timing_file("/Users/ekaterinagridneva/Desktop/hse/mp/sort-benchmark/info_time.txt")
df = pd.DataFrame(data)
plotAll(df)
plotSelectionSort(data)
plotOthers(data)
