#include "MedianMap.h"

MedianMap::MedianMap() :
        m_median(0)
{

}

void MedianMap::add(const int val)
{
    m_container.insert(std::pair<int, int>(val, 0));

    if (m_container.size() % 2 != 0)
    {
        size_t medianIndex = m_container.size() / 2;
        containerType::iterator it = getIterByIndex(medianIndex);

        m_median = it->first;
    }
    else
    {
        size_t medianIndex = m_container.size() / 2 - 1;
        containerType::iterator it = getIterByIndex(medianIndex);

        double sum = it->first;
        ++it;
        sum += it->first;

        m_median = sum / 2;
    }
}

double MedianMap::getMedian() const
{
    return m_median;
}

void MedianMap::clear()
{
    m_container.clear();
    m_median = 0;
}

MedianMap::containerType::iterator MedianMap::getIterByIndex(size_t index)
{
    containerType::iterator it = m_container.begin();
    for (size_t i = 0; i < index; i++, ++it)
    {
    }
    return it;
}
