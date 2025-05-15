/**
 * \file  io.h
 * \brief Interface for input/output functions:
 *        parsing CSV files and saving sorting results.
 */

#ifndef IO_H
#define IO_H

#include "flower.h"
#include <string>
#include <vector>

/// \brief          Reads a CSV file and returns a vector of Flower objects.
/// \param filename Path to the input CSV file.
/// \throws         runtime_error if the file cannot be opened.
/// \return         Vector of Flower objects loaded from the file.
///
/// \details
/// The function opens the given CSV file and discards the first line (assumed to be a header).  
/// Each subsequent line must contain exactly four comma-separated fields:
/// 1. name  
/// 2. color  
/// 3. smell  
/// 4. regions — a list of one or more region names enclosed in square brackets, e.g. `[Region1,Region2,…]`  
///
/// Internally, the parser locates the first three commas to extract the name, color and smell fields.  
/// It then strips the surrounding brackets from the remaining substring and splits it on commas to obtain each region.  
/// A `Flower` is constructed with these values and appended to the result vector.  
/// If the file contains no data lines (only a header or is empty), an empty vector is returned.
vector<Flower> parserCSV(string filename);

/**
 * \brief        Saves a sorted array of flowers to a CSV file and measures the time.
 * \param source Constant reference to the vector of Flower objects.
 * \param size   Size of the array.
 * \throws       runtime_error In case of a file write error.
 * 
 * \details
 * The function performs four sorts on copies of the input data:
 * - Selection sort
 * - Heap sort
 * - Quick sort
 * - std::sort (introsort)
 *
 * It first creates four separate vectors (tmp1–tmp4) from \p source so that each
 * algorithm works on the same initial dataset.  It then builds a base filepath
 * using the provided \p size, and appends algorithm-specific suffixes:
 * \code
 *   sorted_data/<size>_selectSort.txt
 *   sorted_data/<size>_heapSort.txt
 *   sorted_data/<size>_quickSort.txt
 *   sorted_data/<size>_sort.txt
 * \endcode
 *
 * A master timing log ("info_time.txt") is opened in append mode.  For each
 * algorithm:
 * 1. The function records the start time using std::chrono::high_resolution_clock.
 * 2. It invokes the sort (selectSort, heapSort, quickSort, or std::sort).
 * 3. It records the end time and computes the elapsed duration in seconds.
 * 4. It writes a labeled line with the algorithm number and elapsed time to the
 *    timing log.
 * 5. It opens the corresponding output file and writes each Flower in sorted
 *    order, one per line, with fields separated by spaces:
 *    \code
 *      Name Color Smell Region1 Region2 …
 *    \endcode
 * 6. Closes the file before proceeding to the next algorithm.
 *
 * If opening or writing to any of the files fails, the function throws a
 * std::runtime_error indicating which path could not be accessed.
 */
void saveRes(const std::vector<Flower>& source, long size);

#endif