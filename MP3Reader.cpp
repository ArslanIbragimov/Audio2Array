#include "MP3Reader.h"

std::vector<double> MP3FileReader::extractSamples(const std::string& filepath) {
    mpg123_handle* mh = mpg123_new(NULL, NULL);
    if (!mh) {
        throw std::runtime_error("Failed to initialize mpg123");
    }

    if (mpg123_open(mh, filepath.c_str()) != MPG123_OK) {
        throw std::runtime_error("Failed to open MP3 file");
    }

    long rate;
    int channels, encoding;
    mpg123_getformat(mh, &rate, &channels, &encoding);

    std::vector<double> samples;
    unsigned char buffer[8192];
    size_t done;
    while (mpg123_read(mh, buffer, sizeof(buffer), &done) == MPG123_OK) {
        for (size_t index = 0; index < done; ++index) {
            samples.push_back(buffer[index] / 128.0 - 1.0);  // Normalize samples to [-1.0, 1.0]
        }
    }

    mpg123_close(mh);
    mpg123_delete(mh);
    return samples;
}