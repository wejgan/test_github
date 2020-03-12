#pragma once

#include <iostream>
#include <vector>

using namespace std;

class CHeap
{
public:
    CHeap();
    CHeap(const vector<int> &cVec);
    ~CHeap();

    int top() const;
    void pop();
    void insert(int nVal);
    int  size() const;
private:
    void sift_up(int nPos);
    void sift_down(int nPos);

    void Build_heap();
private:
    vector<int> m_cVec;
    unsigned int m_dwSize;  /* 记录堆中元素个数 */
};


