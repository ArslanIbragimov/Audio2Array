#pragma once
#include <iostream>
#include <vector>
#include <sndfile.h>
#include <mpg123.h>
#include <fftw3.h>


class IAudioFileReader {
public:
    virtual std::vector<double> extractSamples(const std::string& filepath) = 0;
};