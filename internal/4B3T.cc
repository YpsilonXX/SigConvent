#include "4B3T.hh"

void Conv4B3T::convert(int32_t param, std::vector<SBlock>& blocks)
{
    int8_t mode = param;

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