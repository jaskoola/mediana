#include "MedianMapV2.h"

MedianMapV2::MedianMapV2() :
        m_median(0)
{
}

void MedianMapV2::add(const int val)
{
    m_container.insert(std::pair<int, int>(val, 0));

    if (m_container.size() == 1)
    {
        m_medianIterator = m_container.begin();
        m_median = val;
    }
    else if (m_container.size() % 2 != 0)
    {
        if (val >= m_medianIterator->first)
        {
            ++m_medianIterator;
        }
        m_median = m_medianIterator->first;
    }
    else
    {
        double sum = m_medianIterator->first;
        if (val >= m_medianIterator->first)
        {
            containerType::iterator nextElementIterator = m_medianIterator;
            ++nextElementIterator;
            sum += nextElementIterator->first;
        }
        else
        {
            --m_medianIterator;
            sum += m_medianIterator->first;
        }

        m_median = sum / 2;
    }
}

double MedianMapV2::getMedian() const
{
    return m_median;
}

void MedianMapV2::clear()
{
    m_container.clear();
    m_median = 0;
}
