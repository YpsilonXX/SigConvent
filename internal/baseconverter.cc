#include "baseconverter.hh"

void baseconvert::convert_to_console(int32_t param, std::vector<SBlock>& blocks)
{
    /*Make convertation to new type*/
    this->convert(param, blocks);

    /*Base print to console*/
    std::cout << CLI_YELLOW_B << "Base convert print (not override): " << CLI_RESET << std::endl;
    int8_t i = 0;
    for(Out& figure : this->output)
    {
        std::cout << CLI_BLUE_B << "|" << CLI_RESET;
        /*Print bits*/
        std::cout << (int16_t)figure.out1;
        std::cout << (int16_t)figure.out2;
        std::cout << (int16_t)figure.out3;

        /*Allignment*/
        i++;
        if(i > 3)
        {
            std::cout << CLI_BLUE_B << "|" << CLI_RESET << std::endl;
            i = 0;
        }
    }
    std::cout << CLI_BLUE_B << "|" << CLI_RESET << std::endl;
}

void baseconvert::convert_to_file(int32_t param, std::vector<SBlock>& blocks, std::string path)
{
    /*Make convertation to new type*/
    this->convert(param, blocks);

    /*Base print to file*/
    std::ofstream file(path);
    if(!file.is_open())
    {
        std::cerr << CLI_RED_B << "Error to open file (convertion)" << CLI_RESET << std::endl;
        return;
    }
    file << "Base convert print (not override): " << "\n";
    int8_t i = 0;
    for(Out& figure : this->output)
    {
        file << "|";
        /*Print bits*/
        file << (int16_t)figure.out1;
        file << (int16_t)figure.out2;
        file << (int16_t)figure.out3;

        /*Allignment*/
        i++;
        if(i > 3)
        {
            file <<  "|"  << "\n";
            i = 0;
        }
    }
    file << "|" << "\n";
}
