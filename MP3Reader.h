#pragma once
#include "ReaderInterface.h"
#include <vector>
#include <string>

class MP3FileReader : public IAudioFileReader {
public:
	std::vector<double> extractSamples(const std::string& filepath) override;
};