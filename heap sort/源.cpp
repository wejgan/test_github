#include <iostream>
#include <vector>
#include "Heap.h"

using namespace std;

void quicksort(vector<int> &cVec, int nstart, int nend)
{
    if (nstart >= nend)
        return;

    int nTarget = cVec[nstart];
    int nSpos = nstart;
    int nEpos = nend;
    while (nSpos < nEpos)
    {
        while (cVec[nEpos] > nTarget && nSpos < nEpos)
            nEpos--;
        while (cVec[nSpos] <= nTarget && nSpos < nEpos)
            nSpos++;

        if (nSpos == nEpos)
            break;
        std::swap(cVec[nSpos], cVec[nEpos]);
    }

    std::swap(cVec[nstart], cVec[nSpos]);
    quicksort(cVec, nstart, nSpos - 1);
    quicksort(cVec, nSpos + 1, nend);
}

void quicksort(vector<int> &cVec)
{
    quicksort(cVec, 0, cVec.size() - 1);
}

int main()
{
    vector<int>  cVec = { 8, 9, 6, 7, 5, 10, 12, -1, 6, 8, 3, 4, 6, 8, 7 };
    CHeap heap(cVec);
    heap.pop();
    heap.pop();
    heap.pop();
    heap.insert(5);
    heap.insert(200);
    heap.insert(7612);
    heap.insert(-2);

    int nSize = heap.size();
    for (int nIdx = 0; nIdx < nSize; nIdx++)
    {
        cout << heap.top() << " ";
        heap.pop();
    }
    cout << endl;

}