#include "main.h"


int main() {
    try {

        WAVFileReader wavReader;
        AudioConverter wavConverter(&wavReader);

        std::string wavFile = "smooth_loud.wav";

        std::vector<double> wavData = wavConverter.loadSamples(wavFile);
        std::cout << "WAV Data: ";
        for (size_t i = 0; i < 5000 && i < wavData.size(); ++i) {
            printf("%.20f\t\n", wavData[i]);
        }
        
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}