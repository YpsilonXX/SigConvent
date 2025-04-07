#ifndef YPS4B3T
#define YPS4B3T

#include "baseconverter.hh"

class Conv4B3T : public baseconvert
{
protected:

    /**
     * Convertion to new type. Writing to this->output
     * \param param Any parameters. For 4B3T or FOMOT -> param = start mode.
     * \param blocks Input signal
     */
    void convert(int32_t param, std::vector<SBlock>& blocks) override;
public:
    /**
     * Convert to new type. Output to console
     * \param param Any parameters. For 4B3T or FOMOT -> param = start mode.
     * \param blocks Input signal
     */
    void convert_to_console(int32_t param, std::vector<SBlock>& blocks) override;

    /**
     * Convert to new type. Output to file
     * \param param Any parameters. For 4B3T or FOMOT -> param = start mode.
     * \param blocks Input signal
     * \param path Path to output file
     */
    void convert_to_file(int32_t param, std::vector<SBlock>& blocks, std::string path) override;


};

#endif//YPS4B3T