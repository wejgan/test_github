#include "Heap.h"


CHeap::CHeap()
:m_cVec(0), m_dwSize(0)
{
}


CHeap::~CHeap()
{
}


CHeap::CHeap(const vector<int> &cVec)
:m_cVec(cVec), m_dwSize(cVec.size())
{
    Build_heap();
}


/*  规定: 当前节点的Id：n，其左节点ID：(n+1)*2-1, 右节点ID：(n+1)*2 */
/* 堆的大小为n, 叶子节点的ID为：n/2, n/2+1, ..., n-1 */
void CHeap::sift_down(int nPos)
{
    if (m_dwSize == 0 || m_cVec.size() == 0)
        return;

    int nLeftP, nRightP;
    int nleftVal, nRightVal;
    while (nPos < m_dwSize / 2)
    {
        nLeftP = (nPos + 1) * 2 - 1;
        nRightP = (nPos + 1) * 2;

        nRightVal = 0x80000000;
        nleftVal = m_cVec[nLeftP];
        if (nRightP < m_dwSize)
            nRightVal = m_cVec[nRightP];

        if (m_cVec[nPos] >= nleftVal && m_cVec[nPos] >= nRightVal)
            return;

        if (nRightVal > nleftVal)
        {
            std::swap(m_cVec[nPos], m_cVec[nRightP]);
            nPos = nRightP;
        }
        else
        {
            std::swap(m_cVec[nPos], m_cVec[nLeftP]);
            nPos = nLeftP;
        }
    }
}

void CHeap::sift_up(int nPos)
{
    if (nPos >= m_dwSize)
        return;

    int nParentP;
    while (nPos > 0)
    {
        nParentP = (nPos - 1) / 2;
        if (m_cVec[nPos] <= m_cVec[nParentP])
            return;
        std::swap(m_cVec[nPos], m_cVec[nParentP]);
        nPos = nParentP;
    }
}


void  CHeap::Build_heap()
{
    if (m_dwSize == 0)
        return;

    int nIdx = m_dwSize / 2 - 1;
    for (; nIdx >= 0; nIdx--)
        sift_down(nIdx);
}

void CHeap::insert(int nVal)
{
    if (m_dwSize == m_cVec.size())
        m_cVec.push_back(nVal);
    else
        m_cVec[m_dwSize] = nVal;
    m_dwSize++;

    sift_up(m_dwSize - 1);
}

int CHeap::top() const
{
    if (m_dwSize)
        return m_cVec[0];
    return -1;
}
#if 0
void CHeap::pop()
{
    if (m_dwSize <= 0)
        return;

    std::swap(m_cVec[0], m_cVec[m_dwSize - 1]);
    m_dwSize--;
    sift_down(0);
}

int CHeap::size() const
{
    return m_dwSize;
}
#endif


#if 0
void CHeap::pop()
{
    if (m_dwSize <= 0)
        return;

    std::swap(m_cVec[0], m_cVec[m_dwSize - 1]);
    m_dwSize--;
    sift_down(0);
}

int CHeap::size() const
{
    return m_dwSize;
}
#endif

#if 0
void CHeap::pop()
{
    if (m_dwSize <= 0)
        return;

    std::swap(m_cVec[0], m_cVec[m_dwSize - 1]);
    m_dwSize--;
    sift_down(0);
}

int CHeap::size() const
{
    return m_dwSize;
}
#endif
