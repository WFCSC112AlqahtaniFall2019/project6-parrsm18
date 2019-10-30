#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>
#include "BinaryInsertionSort.h"
#include "Node.h"
#include "LinkedList.h"
using namespace std;

int main() {
    for (int i = 0; i < 100; i++) {

        int seed, length;
        //cin >> seed >> length;
        cin >> length;
        seed = length;
        srand(seed);

        vector<int> v(length);
        LinkedList list;


        // generate vector of random integers
        for (int i = 0; i < v.size(); i++) {
            v[i] = rand() % 100;
            list.Append(v[i]); //Copies values into linked list
        }

        // binary insertion sort
        clock_t start_binaryInsertionSort = clock();
        insertionSort(v, v.size());
        clock_t end_binaryInsertionSort = clock();

        // check if sorted
        for (int i = 1; i < v.size(); i++) {
            assert(v[i - 1] <= v[i]);
        }

        // print out sorted list
        /*cout << "List after binary insertion sort: " << endl;
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;*/

        // FINISH ME
        //cout << "List before linked list insertion sort" << endl;
        //list.PrintList();
        //cout << "List after linked list insertion sort: " << endl;

        //Insertion sort using linked list
        clock_t start_linkedListInsertionSort = clock();
        list.Sort();
        clock_t end_linkedListInsertionSort = clock();

        double elapsed_binaryInsertionSort =
                double(end_binaryInsertionSort - start_binaryInsertionSort) / CLOCKS_PER_SEC;
        double elapsed_linkedListInsertionSort =
                double(end_linkedListInsertionSort - start_linkedListInsertionSort) / CLOCKS_PER_SEC;
        //list.PrintList();

        cout << length << " " << elapsed_binaryInsertionSort << " " << elapsed_linkedListInsertionSort << endl;
    }
}
