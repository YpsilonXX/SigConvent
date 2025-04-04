#include "signal.hh"

void Signal::read()
{
    std::string buff;

    /*Delete old data*/
    this->blocks.clear();

    /*Get line with signal*/
    std::cout << CLI_GREEN << "---------New Signal---------" << CLI_RESET << std::endl;
    std::cout << "Enter signal (with 0 or 1): " << std::endl;
    std::getline(std::cin, buff);
    std::cout << CLI_GREEN << "----------------------------" << CLI_RESET << std::endl;

    /**
     * Group bits with size = 4
     */
    size_t i = 0;
    while(i < buff.size()/4)
    {
        SBlock temp_block; uint8_t temp = 0;
        
        for(int j = 0; j < 4; j++)//Setting bits
        {
            switch (buff[i+j])
            {
            case '0':
                temp = ypsbit::clear_bit(temp, j);
                break;
            case '1':
                temp = ypsbit::set_bit(temp, j);
                break;
            default:
                std::cerr << CLI_RED_B << "Error input: only '0' or '1' for signal" << CLI_RESET << std::endl;
                return;
                break;
            }
        }

        temp_block.sigblock = temp;
        this->blocks.emplace_back(temp_block);
    }

}

void Signal::display()
{
    
}