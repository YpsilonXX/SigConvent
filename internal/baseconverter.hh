#ifndef BASECONVERTER
#define BASECONVERTER
#include <cstdint>
#include <vector>
#include <iostream>
#include <fstream>

#include "defines.hh"
#include "signal.hh"

struct Out
{
    int8_t out1 : 4;
    int8_t out2 : 4; 
    int8_t out3 : 4;
};

class baseconvert
{
protected:
    std::vector<Out> output;

    /**
     * Convertion to new type. Writing to this->output
     * \param param Any parameters. For 4B3T or FOMOT -> param = start mode.
     * \param blocks Input signal
     */
    virtual void convert(int32_t param, std::vector<SBlock>& blocks) = 0;

public:
    
    /**
     * Convert to new type. Output to console
     * \param param Any parameters. For 4B3T or FOMOT -> param = start mode.
     * \param blocks Input signal
     */
    virtual void convert_to_console(int32_t param, std::vector<SBlock>& blocks);

    /**
     * Convert to new type. Output to file
     * \param param Any parameters. For 4B3T or FOMOT -> param = start mode.
     * \param blocks Input signal
     * \param path Path to output file
     */
    virtual void convert_to_file(int32_t param, std::vector<SBlock>& blocks, std::string path);

};

#endif//BASECONVERTER