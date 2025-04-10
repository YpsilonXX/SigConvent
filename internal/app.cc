#include "app.hh"

App::App()
{
    this->settings.in_file = false;
    this->settings.start_mode = 0;
    this->settings.path_in = "in.txt";
    this->settings.path_out = "out.txt";
}

int8_t App::main_menu()
{
    uint8_t active_position = 0; ypskeys::Key last_key;
    clearConsole();

    while(true)
    {
        /*Main print*/
        std::cout << CLI_GREEN_B << main_label << std::endl << std::endl;

        std::cout << CLI_GREEN_B << "-----------------------------------------------------" << CLI_RESET << std::endl;
        std::cout << (active_position==0 ? CLI_RED_B : CLI_MAGENTA_B) << "\t\t1." << CLI_YELLOW_B << "Convert to 4B3T" << CLI_RESET << std::endl;
        std::cout << (active_position==1 ? CLI_RED_B : CLI_MAGENTA_B) << "\t\t2." << CLI_YELLOW_B << "Convert to FOMOT" << CLI_RESET << std::endl;
        std::cout << (active_position==2 ? CLI_RED_B : CLI_MAGENTA_B) << "\t\t3." << CLI_YELLOW_B << "Switch console/file output" << CLI_RESET << std::endl;
        std::cout << (active_position==3 ? CLI_RED_B : CLI_MAGENTA_B) << "\t\t4." << CLI_YELLOW_B << "Set input path" << CLI_RESET << std::endl;
        std::cout << (active_position==4 ? CLI_RED_B : CLI_MAGENTA_B) << "\t\t5." << CLI_YELLOW_B << "Set output path" << CLI_RESET << std::endl;
        std::cout << (active_position==5 ? CLI_RED_B : CLI_MAGENTA_B) << "\t\t0." << CLI_YELLOW_B << "EXIT" << CLI_RESET << std::endl;
        std::cout << CLI_GREEN_B << "-----------------------------------------------------" << CLI_RESET << std::endl;
        /*Msg print*/
        if(this->msg_to_display.size() != 0)
        {
            std::cout << CLI_GREEN_B << this->msg_to_display << std::endl;
            std::cout << CLI_GREEN_B << "-----------------------------------------------------" << CLI_RESET << std::endl;
        }

        /*Read action from user*/
        last_key = ypskeys::readKey();
        /*If it's special key*/
        if(last_key.type != ypskeys::KeyType::Character && last_key.type != ypskeys::KeyType::Unknown)
        {
            switch(last_key.type)
            {
                case ypskeys::KeyType::ArrowDown:
                    active_position = (active_position != 5 ? active_position + 1 : 0);
                    break;

                case ypskeys::KeyType::ArrowUp:
                    active_position = (active_position != 0 ? active_position - 1 : 5);
                    break;

                case ypskeys::KeyType::Enter:
                    return active_position;
                    break;
                
                case ypskeys::KeyType::Escape:
                    return 0;
                    break;
            }
        }

        /*Write down a message*/
        switch (active_position)
        {
        case 5:
            this->msg_to_display = "Exit from programm";
            break;

        case 0:
            this->msg_to_display = "Convert signal to 4B3T" + (this->settings.in_file ? yps_text_in_file : "");
            break;

        case 1:
            this->msg_to_display = "Convert signal to FOMOT" + (this->settings.in_file ? yps_text_in_file : "");
            break;

        case 2:
            this->msg_to_display = "Switch type of output. Now: " + (this->settings.in_file ? yps_text_in_file : yps_text_in_console);
            break;

        case 3:
            this->msg_to_display = "Enter path for input file. Now: " + this->settings.path_in;
            break;

        case 4:
            this->msg_to_display = "Enter path for output file. Now: " + this->settings.path_out;
            break;
            
        default:
            this->msg_to_display.clear();
            break;
        }

        clearConsole();
    }

    return 0;
}

void App::_4b3t_convert()
{
    ypskeys::Key last_key;

    if(this->settings.in_file)
    {
        clearConsole();
        this->signal.fread(this->settings.path_in);

        std::cout << CLI_GREEN_B << "-----------------------------------------------------" << CLI_RESET << std::endl;
        std::cout << CLI_YELLOW_B << "Start sum: " << CLI_BLUE_B << (int16_t)this->settings.start_mode << CLI_RESET << std::endl;
        std::cout << CLI_GREEN_B << "-----------------------------------------------------" << CLI_RESET << std::endl;

        this->signal.display();
        std::vector<SBlock> buff = this->signal.get_blocks();
        this->c4B3T.convert_to_file(this->settings.start_mode, buff, this->settings.path_out);
    }
    else
    {
        clearConsole();
        this->signal.read();

        std::cout << CLI_YELLOW_B << "Enter start sum from -2 to 3 (default = 0): " << std::endl;

        int8_t user_mode;
        std::cin >> user_mode;
        if(user_mode > -3 && user_mode < 4)
            this->settings.start_mode = user_mode;
        clearConsole();

        std::cout << CLI_GREEN_B << "-----------------------------------------------------" << CLI_RESET << std::endl;
        std::cout << CLI_YELLOW_B << "Start sum: " << CLI_BLUE_B << (int16_t)this->settings.start_mode << CLI_RESET << std::endl;
        std::cout << CLI_GREEN_B << "-----------------------------------------------------" << CLI_RESET << std::endl;

        this->signal.display();
        std::vector<SBlock> buff = this->signal.get_blocks();
        this->c4B3T.convert_to_file(this->settings.start_mode, buff, this->settings.path_out);
    }

    std::cout << "\n\n\n";
    std::cout << CLI_GREEN_B << "-----------------------------------------------------" << CLI_RESET << std::endl;
    std::cout << CLI_YELLOW_B << "Press any button (not power off!) to continue " << CLI_RESET << std::endl;
    std::cout << CLI_GREEN_B << "-----------------------------------------------------" << CLI_RESET << std::endl;

    ypskeys::readKey();
}

void App::_fomot_convert()
{
    if(this->settings.in_file)
    {
        clearConsole();
        this->signal.fread(this->settings.path_in);

        std::cout << CLI_YELLOW_B << "Enter start sum from -1 to 2 (default = 0): " << std::endl;

        int8_t user_mode;
        std::cin >> user_mode;
        if(user_mode > -2 && user_mode < 3)
            this->settings.start_mode = user_mode;
        clearConsole();

        std::cout << CLI_GREEN_B << "-----------------------------------------------------" << CLI_RESET << std::endl;
        std::cout << CLI_YELLOW_B << "Start sum: " << CLI_BLUE_B << (int16_t)this->settings.start_mode << CLI_RESET << std::endl;
        std::cout << CLI_GREEN_B << "-----------------------------------------------------" << CLI_RESET << std::endl;

        this->signal.display();
        std::vector<SBlock> buff = this->signal.get_blocks();
        this->cFOMOT.convert_to_file(this->settings.start_mode, buff, this->settings.path_out);
    }
    else
    {
        clearConsole();
        this->signal.read();

        std::cout << CLI_YELLOW_B << "Enter start sum from -1 to 2 (default = 0): " << std::endl;

        int8_t user_mode;
        std::cin >> user_mode;
        if(user_mode > -2 && user_mode < 3)
            this->settings.start_mode = user_mode;
        clearConsole();

        std::cout << CLI_GREEN_B << "-----------------------------------------------------" << CLI_RESET << std::endl;
        std::cout << CLI_YELLOW_B << "Start sum: " << CLI_BLUE_B << (int16_t)this->settings.start_mode << CLI_RESET << std::endl;
        std::cout << CLI_GREEN_B << "-----------------------------------------------------" << CLI_RESET << std::endl;

        this->signal.display();
        std::vector<SBlock> buff = this->signal.get_blocks();
        this->cFOMOT.convert_to_console(this->settings.start_mode, buff);
    }

    std::cout << "\n\n\n";
    std::cout << CLI_GREEN_B << "-----------------------------------------------------" << CLI_RESET << std::endl;
    std::cout << CLI_YELLOW_B << "Press any button (not power off!) to continue " << CLI_RESET << std::endl;
    std::cout << CLI_GREEN_B << "-----------------------------------------------------" << CLI_RESET << std::endl;

    ypskeys::readKey();
}

void App::set_in_path()
{
    clearConsole();
    std::cout << CLI_YELLOW_B << "Write path to input file:  " << CLI_RESET << std::endl;
    std::string buff;
    std::cin >> buff;

    /*Check file exist*/
    if(std::filesystem::exists(buff))
    {
        this->settings.path_in = buff;
        this->msg_to_display = "Path added successful";
    }
    else
        this->msg_to_display = "Path not exist";
} 

void App::set_out_path()
{
    clearConsole();
    std::cout << CLI_YELLOW_B << "Write path to input file:  " << CLI_RESET << std::endl;
    std::string buff;
    std::cin >> buff;

    /*Create directory if not exist*/
    std::filesystem::create_directories(buff);
    this->settings.path_out = buff;
    this->msg_to_display = "Path added successful";
}

void App::switch_output()
{
    this->settings.in_file = !this->settings.in_file;
}

void App::run()
{
    /*Start message*/
    this->msg_to_display = "Convert signal to 4B3T" + (this->settings.in_file ? yps_text_in_file : "");
    while(true)
    {
        switch(this->main_menu())
        {
            case 0:
                this->_4b3t_convert();
                break;
            
            case 1:
                this->_fomot_convert();
                break;

            case 2:
                this->switch_output();
                break;
            
            case 3:
                this->set_in_path();
                break;
            
            case 4:
                this->set_out_path();
                break;

            case 5:
            default:
                return;
                break;
            
                
        }
    }   
}