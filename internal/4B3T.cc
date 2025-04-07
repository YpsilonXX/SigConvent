#include "4B3T.hh"

void Conv4B3T::convert(int32_t param, std::vector<SBlock>& blocks)
{
    int8_t mode = param;
    /*delete old data*/
    this->output.clear();

    /*Run for all blocks of signal*/
    for(SBlock block : blocks)
    {   
        Out temp;
        /*Using table with mode-*/
        if (mode > 0)  
        {
            switch (block.sigblock)
            {
            case 0:
                temp.out1 = 0;
                temp.out2 = -1;
                temp.out3 = 1;
                break;

            case 1:
                temp.out1 = -1;
                temp.out2 = 1;
                temp.out3 = 0;
                break;
            
            case 2:
                temp.out1 = -1;
                temp.out2 = 0;
                temp.out3 = 1;
                break;
            
            case 3:
                temp.out1 = -1;
                temp.out2 = 1;
                temp.out3 = -1;
                break;

            case 4:
                temp.out1 = 0;
                temp.out2 = -1;
                temp.out3 = -1;
                break;

            case 5:
                temp.out1 = 0;
                temp.out2 = -1;
                temp.out3 = 0;
                break;

            case 6:
                temp.out1 = 0;
                temp.out2 = 0;
                temp.out3 = -1;
                break;

            case 7:
                temp.out1 = 1;
                temp.out2 = -1;
                temp.out3 = -1;
                break;

            case 8:
                temp.out1 = 0;
                temp.out2 = 1;
                temp.out3 = -1;
                break;

            case 9:
                temp.out1 = 1;
                temp.out2 = -1;
                temp.out3 = 0;
                break;

            case 10:
                temp.out1 = 1;
                temp.out2 = 0;
                temp.out3 = -1;
                break;

            case 11:
                temp.out1 = -1;
                temp.out2 = 0;
                temp.out3 = 0;
                break;

            case 12:
                temp.out1 = -1;
                temp.out2 = 0;
                temp.out3 = -1;
                break;

            case 13:
                temp.out1 = -1;
                temp.out2 = -1;
                temp.out3 = 0;
                break;

            case 14:
                temp.out1 = -1;
                temp.out2 = -1;
                temp.out3 = 1;
                break;

            case 15:
                temp.out1 = -1;
                temp.out2 = -1;
                temp.out3 = -1;
                break;
            
            default:
                std::cerr << CLI_RED_B << "Runtime error convertaion 4B3T mode-" << CLI_RESET << std::endl;
                return;
            }
        }
        else /*Using table with mode+*/
        {
            switch (block.sigblock)
            {
            case 0:
                temp.out1 = 0;
                temp.out2 = -1;
                temp.out3 = 1;
                break;

            case 1:
                temp.out1 = -1;
                temp.out2 = 1;
                temp.out3 = 0;
                break;
            
            case 2:
                temp.out1 = -1;
                temp.out2 = 0;
                temp.out3 = 1;
                break;
            
            case 3:
                temp.out1 = 1;
                temp.out2 = -1;
                temp.out3 = 1;
                break;

            case 4:
                temp.out1 = 0;
                temp.out2 = 1;
                temp.out3 = 1;
                break;

            case 5:
                temp.out1 = 0;
                temp.out2 = 1;
                temp.out3 = 0;
                break;

            case 6:
                temp.out1 = 0;
                temp.out2 = 0;
                temp.out3 = 1;
                break;

            case 7:
                temp.out1 = -1;
                temp.out2 = 1;
                temp.out3 = 1;
                break;

            case 8:
                temp.out1 = 0;
                temp.out2 = 1;
                temp.out3 = -1;
                break;

            case 9:
                temp.out1 = 1;
                temp.out2 = -1;
                temp.out3 = 0;
                break;

            case 10:
                temp.out1 = 1;
                temp.out2 = 0;
                temp.out3 = -1;
                break;

            case 11:
                temp.out1 = 1;
                temp.out2 = 0;
                temp.out3 = 0;
                break;

            case 12:
                temp.out1 = 1;
                temp.out2 = 0;
                temp.out3 = 1;
                break;

            case 13:
                temp.out1 = 1;
                temp.out2 = 1;
                temp.out3 = 0;
                break;

            case 14:
                temp.out1 = 1;
                temp.out2 = 1;
                temp.out3 = -1;
                break;

            case 15:
                temp.out1 = 1;
                temp.out2 = 1;
                temp.out3 = 1;
                break;
            
            default:
                std::cerr << CLI_RED_B << "Runtime error convertaion 4B3T mode+" << CLI_RESET << std::endl;
                return;
            }
        }

        /*update mode*/
        mode += temp.out1 + temp.out2 + temp.out3;
        this->output.emplace_back(temp);
    }
}

void Conv4B3T::convert_to_console(int32_t param, std::vector<SBlock>& blocks)
{
    /*Make convertation to new type*/
    this->convert(param, blocks);

    /*Base print to console*/
    std::cout << CLI_YELLOW_B << "4B3T convert print: " << CLI_RESET << std::endl;
    int8_t i = 0;
    for(Out& figure : this->output)
    {
        std::cout << CLI_BLUE_B << "|" << CLI_RESET;
        /*Print bits*/
        switch((int16_t)figure.out1)
        {
            case 1:
            case 0:
                std::cout << " " << (int16_t)figure.out1 << " ";
                break;
            case -1:
                std::cout << (int16_t)figure.out1 << " ";
                break;

            default:
                std::cerr << CLI_RED_B << "Error to print 4B3T" << CLI_RESET << std::endl;
                return;
        }

        switch((int16_t)figure.out2)
        {
            case 1:
            case 0:
                std::cout << " " << (int16_t)figure.out2 << " ";
                break;
            case -1:
                std::cout << (int16_t)figure.out2 << " ";
                break;

            default:
                std::cerr << CLI_RED_B << "Error to print 4B3T" << CLI_RESET << std::endl;
                return;
        }

        switch((int16_t)figure.out3)
        {
            case 1:
            case 0:
                std::cout << " " << (int16_t)figure.out3 << " ";
                break;
            case -1:
                std::cout << (int16_t)figure.out3 << " ";
                break;

            default:
                std::cerr << CLI_RED_B << "Error to print 4B3T" << CLI_RESET << std::endl;
                return;
        }

        /*Allignment*/
        i++;
        if(i > 3)
        {
            std::cout << CLI_BLUE_B << "|" << CLI_RESET << std::endl << std::endl;
            i = 0;
        }
    }

    /*Allignment*/
    if(this->output.size() % 4 != 0)
        std::cout << CLI_BLUE_B << "|" << CLI_RESET << std::endl;
}

void Conv4B3T::convert_to_file(int32_t param, std::vector<SBlock>& blocks, std::string path)
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
    file << "4B3T convert print: " << "\n";
    int8_t i = 0;
    for(Out& figure : this->output)
    {
        file << "|";
        /*Print bits*/
        switch((int16_t)figure.out1)
        {
            case 1:
            case 0:
                file << " " << (int16_t)figure.out1 << " ";
                break;
            case -1:
                file << (int16_t)figure.out1 << " ";
                break;

            default:
                std::cerr << CLI_RED_B << "Error to print 4B3T" << CLI_RESET << std::endl;
                return;
        }

        switch((int16_t)figure.out2)
        {
            case 1:
            case 0:
                file << " " << (int16_t)figure.out2 << " ";
                break;
            case -1:
                file << (int16_t)figure.out2 << " ";
                break;

            default:
                std::cerr << CLI_RED_B << "Error to print 4B3T" << CLI_RESET << std::endl;
                return;
        }

        switch((int16_t)figure.out3)
        {
            case 1:
            case 0:
                file << " " << (int16_t)figure.out3 << " ";
                break;
            case -1:
                file << (int16_t)figure.out3 << " ";
                break;

            default:
                std::cerr << CLI_RED_B << "Error to print 4B3T" << CLI_RESET << std::endl;
                return;
        }

        /*Allignment*/
        i++;
        if(i > 3)
        {
            file << "|" << std::endl << std::endl;
            i = 0;
        }
    }

    /*Allignment*/
    if(this->output.size() % 4 != 0)
        file << "|" << std::endl;

}