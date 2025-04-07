#ifndef CONVSETT
#define CONVSETT
#include <iostream>
#include "defines.hh"

struct Settings
{
    /*Path to file with input*/
    std::string path_in;
    /*Path to output file*/
    std::string path_out;

    /*Start mode's value*/
    int8_t start_mode;
};

extern std::string main_label;

#endif//CONVSETT