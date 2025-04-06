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


};

#endif//YPS4B3T