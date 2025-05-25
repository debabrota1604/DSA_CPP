// C++ Program to demonstrate how to implement the quick sort algorithm
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& vec, int low, int high) {
   // Selecting last element as the pivot
   int pivot = vec[high];

   // Index of element just before the last element used for swapping
   int pivotIndex = (low - 1);

   for (int current = low; current <= high - 1; current++) {
       // If current element is smaller than or equal to pivot
       if (vec[current] <= pivot) {
           pivotIndex++;
           swap(vec[pivotIndex], vec[current]);
       }
   }

   // Put pivot to its position
   swap(vec[pivotIndex + 1], vec[high]);

   // Return the point of partition
   return (pivotIndex + 1);
}

void quickSort(vector<int>& vec, int low, int high) {
   if (low < high) {
       // pi is Partitioning Index, arr[p] is now at right place
       int partitionIndex = partition(vec, low, high);

       // Separately sort elements before and after the Partition Index pi
       quickSort(vec, low, partitionIndex - 1);
       quickSort(vec, partitionIndex + 1, high);
   }
}

int main() {
   vector<int> numbers = {10, 7, 8, 9, 1, 5};
   int size = numbers.size();
   
     // Calling quicksort for the vector vec
   quickSort(numbers, 0, size - 1);

   for (auto num : numbers) {
       cout << num << " ";
   }
    cout << endl;
   return 0;
}