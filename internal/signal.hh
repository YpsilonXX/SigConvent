#ifndef YPSSIGNAL
#define YPSSIGNAL
#include <iostream>
#include <cstdint>
#include <vector>
#include <fstream>

#include "defines.hh"
#include "base.hh"


struct SBlock
{
    /*4 bit of signal*/
    uint8_t sigblock:4;
};

class Signal{
private:
    std::vector<SBlock> blocks;


public:

    /**
     * Read signal from console.
     */
    void read();
    /**
     * Read signal from file
     * \param path File with signal
     */
    void fread(std::string path = "in.txt");

    std::vector<SBlock> get_blocks();

    void display();

};

#endif//YPSSIGNAL