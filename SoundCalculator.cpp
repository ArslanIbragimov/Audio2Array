#include "SoundCalculator.h"

template <typename T>
static double constexpr calculateDuration(const T bitrate, const T size, bool sizeIsBit) {
    return sizeIsBit ? size / bitrate : size * 1000 / bitrate;
}