#include "app.hh"

int8_t App::main_menu()
{
    std::cout << CLI_GREEN_B << main_label << std::endl << std::endl;

    std::cout << CLI_GREEN_B << "-----------------------------------------------------" << CLI_RESET << std::endl;
    std::cout << CLI_MAGENTA_B << "\t\t1." << CLI_YELLOW_B << "Convert to 4B3T" << CLI_RESET << std::endl;
    std::cout << CLI_MAGENTA_B << "\t\t2." << CLI_YELLOW_B << "Convert to FOMOT" << CLI_RESET << std::endl;
    std::cout << CLI_MAGENTA_B << "\t\t3." << CLI_YELLOW_B << "Switch console/file output" << CLI_RESET << std::endl;
    std::cout << CLI_MAGENTA_B << "\t\t4." << CLI_YELLOW_B << "Set input path" << CLI_RESET << std::endl;
    std::cout << CLI_MAGENTA_B << "\t\t5." << CLI_YELLOW_B << "Set output path" << CLI_RESET << std::endl;
    std::cout << CLI_MAGENTA_B << "\t\t0." << CLI_YELLOW_B << "EXIT" << CLI_RESET << std::endl;
    std::cout << CLI_GREEN_B << "-----------------------------------------------------" << CLI_RESET << std::endl;


    return 0;
}

void App::run()
{
    this->main_menu();
}