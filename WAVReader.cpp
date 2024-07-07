#include "WAVReader.h"

std::vector<double> WAVFileReader::extractSamples(const std::string& filepath) {
    //Creating object for sound file (@inputfile) manipulations
    SF_INFO soundfile;
    //Copying all input file data to our object @soundfile
    SNDFILE* inputfile = sf_open(filepath.c_str(), SFM_READ, &soundfile);
    //Open is successful check
    if (!inputfile) {
        sf_close(inputfile);
        throw std::runtime_error("Failed to open WAV file");
    }
    //Creating samples vector, whose size is equal channels count times frames count of @soundfile
    std::vector<double> samples(soundfile.channels * soundfile.frames);
    sf_readf_double(inputfile, samples.data(), soundfile.frames);
    if (sf_readf_double(inputfile, samples.data(), soundfile.frames) < soundfile.frames) {
        sf_close(inputfile);
        throw std::runtime_error("Failed to read all frames from WAV file");
    }

    //Closing input file, @soundfile or object, whose was manipulated, closing is not needed, because he was allocated is stack 
    //                                                                                        and not intended for open files 
    sf_close(inputfile);
    //return data
    return samples;
}