#pragma once
#include "ReaderInterface.h"

class AudioConverter {
public:
    AudioConverter(IAudioFileReader* reader);
    std::vector<double> loadSamples(const std::string& filepath);

private:
    IAudioFileReader* reader_;
};