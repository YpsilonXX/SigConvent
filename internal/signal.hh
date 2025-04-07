#ifndef YPSSIGNAL
#define YPSSIGNAL
#include <iostream>
#include <cstdint>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

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

    /**
     * Read to this->block from buff (for read(), fread())
     * \param buff Signal to read
     */
    void read_to_block_from_buff(std::string& buff);

public:

    /**
     * Read signal from console. Removing spaces if exist
     */
    void read();
    /**
     * Read signal from file
     * \param path File with signal
     */
    void fread(std::string path = "in.txt");
    /**
     * Get signal blocks
     * \return blocks's vector
     */
    std::vector<SBlock> get_blocks();
    /**
     * Display signal in console
     */
    void display();
    /**
     * Draw signal in console
     */
    void draw();
};

#endif//YPSSIGNAL