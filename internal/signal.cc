#include "signal.hh"

void Signal::read_to_block_from_buff(std::string& buff)
{
    if(buff.size() % 4 != 0)
        std::cout << CLI_YELLOW_B << "Warning: Size of signal in not multiplied by 4" << CLI_RESET << std::endl;

    /**
     * Group bits with size = 4
     */
    size_t i = 0;
    while(i < buff.size()/4)
    {
        SBlock temp_block; uint8_t temp = 0;
        
        for(size_t j = 0; j < 4; j++)//Setting bits
        {
            switch (buff[4*i+j])
            {
            case '0':
                temp = ypsbit::clear_bit(temp, 3-j);
                break;
            case '1':
                temp = ypsbit::set_bit(temp, 3-j);
                break;
            default:
                std::cerr << CLI_RED_B << "Error input: only '0' or '1' for signal" << CLI_RESET << std::endl;
                return;
                break;
            }
        }

        temp_block.sigblock = temp;
        this->blocks.emplace_back(temp_block);
        i++;
    }

    /*Allignment*/
    if(this->blocks.size() % 4 != 0)
    {
        uint8_t shift = this->blocks.size() % 4;
        for(size_t i = 0; i < 4 - shift; i++)
        {
            SBlock temp_block; uint8_t temp = 0;
            temp_block.sigblock = temp;
            this->blocks.emplace_back(temp_block);
        }
    }
}

void Signal::read()
{
    std::string buff;

    /*Delete old data*/
    this->blocks.clear();

    /*Get line with signal*/
    std::cout << CLI_GREEN << "---------New Signal---------" << CLI_RESET << std::endl;
    std::cout << "Enter signal (with 0 or 1): " << std::endl;
    std::getline(std::cin, buff);
    buff.erase(std::remove(buff.begin(), buff.end(), ' '), buff.end()); //Remove spaces if exist
    std::cout << CLI_GREEN << "----------------------------" << CLI_RESET << std::endl;

    this->read_to_block_from_buff(buff);
}

void Signal::fread(std::string path)
{
    std::ifstream file(path);
    if(!file.is_open())
    {
        std::cerr << CLI_RED_B << "Error to open file(fread)" << CLI_RESET << std::endl;
    }
    std::stringstream buffer;

    buffer << file.rdbuf();
    std::string signal = buffer.str();
    signal.erase(std::remove(signal.begin(), signal.end(), ' '), signal.end());//Remove spaces if exist

    this->read_to_block_from_buff(signal);
}

std::vector<SBlock> Signal::get_blocks()
{
    return this->blocks;
}

void Signal::display()
{
    std::cout << CLI_GREEN << "---------Signal Out---------" << CLI_RESET << std::endl;
    for(size_t i = 0; i < this->blocks.size()/4; i++)
    {
        std::cout << CLI_MAGENTA_B << i*4 << ":\t" << CLI_RESET;
        for(size_t j = 0; j < 4; j++)
        {
            std::cout << ypsbit::get_bit(this->blocks[i*4 + j].sigblock, 3);
            std::cout << ypsbit::get_bit(this->blocks[i*4 + j].sigblock, 2);
            std::cout << ypsbit::get_bit(this->blocks[i*4 + j].sigblock, 1);
            std::cout << ypsbit::get_bit(this->blocks[i*4 + j].sigblock, 0) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << CLI_GREEN << "----------------------------" << CLI_RESET << std::endl;
}