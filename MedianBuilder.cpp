#include "MedianBuilder.h"
#include <cstddef>

#ifdef MEDIANMAP
#include "MedianMap.h"
#elif MEDIANMAPV2
#include "MedianMapV2.h"
#endif

MedianInterface * MedianBuilder::createMedianInstance()
{
    MedianInterface * result = NULL;
#ifdef MEDIANMAP
    result = new MedianMap;
#elif MEDIANMAPV2
    result = new MedianMapV2;
#endif

    return result;
}
