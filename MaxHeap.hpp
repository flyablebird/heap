#ifndef	__MAXHEAP__H
#define	__MAXHEAP__H
/***
Created at2022-11-28 16:31:35
author	qiaohao
***/

#include <string>
#include <iostream>
#include <functional>
#include <iterator>
#include <algorithm>

void print(std::size_t d)
{
    std::cout<<d<<std::endl;
}

template <typename Iter,typename Cmp = std::greater<typename Iter::value_type>>
class BaseHeap
{
public:
    BaseHeap(Iter start, Iter end)
        :m_start(start), m_end(end)
    {

    }
    void Build()
    {
        for (auto pos = m_end - 1; pos > m_start; --pos)
        {
            Heapify(pos);
        }
        Heapify(m_start);
    }
    void Sort()
    {
        Build();
        for (auto pos = m_end - 1; pos > m_start;)
        {
			std::iter_swap(m_start,pos--);
            --m_end;
			Heapify(m_start);
        }
    }

protected:
    Iter Parent(const Iter& child)
    {
        auto temp = (std::distance(m_start,child) - 1) / 2;
        return m_start + temp;
    }
    Iter Left(const Iter& parent)
    {
        auto temp = 2 * std::distance(m_start,parent) + 1;
        return std::distance(m_start, m_end) > temp ? m_start + temp : m_end;
    }
    Iter Right(const Iter& parent)
    {
        auto temp = 2 * std::distance(m_start,parent) + 2;
        return std::distance(m_start, m_end) > temp ? m_start + temp : m_end;
    }

    void Heapify(Iter parent)
    {
        Iter l = Left(parent);
        Iter r = Right(parent);
        Iter* plargest = &parent;
        auto cmp = Cmp();
        if (l < m_end && cmp(*l, **plargest))
        {
            plargest = &l;
        }
        if (r < m_end && cmp(*r, **plargest))
        {
            plargest = &r;
        }
        if (*plargest != parent)
        {
            std::iter_swap(*plargest, parent);
            Heapify(*plargest);
        }
    }

private:
    Iter m_start;
    Iter m_end;

};

#endif
