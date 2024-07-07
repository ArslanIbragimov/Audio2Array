#include "AudioConverter.h"

AudioConverter::AudioConverter(IAudioFileReader* reader) : reader_(reader) {}

std::vector<double> AudioConverter::loadSamples(const std::string& filepath) {
    return reader_->extractSamples(filepath);
}