#pragma once
#include "ReaderInterface.h"
#include <vector>
#include <string>

class WAVFileReader : public IAudioFileReader {
public:
	std::vector<double> extractSamples(const std::string& filepath) override;

};