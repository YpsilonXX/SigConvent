#ifndef SIGCONVAPP
#define SIGCONVAPP

#include <vector>
#include <cctype>
#include <filesystem>

#include "signal.hh"
#include "defines.hh"
#include "base.hh"
#include "4B3T.hh"
#include "FOMOT.hh"
#include "settings.hh"
#include "input.hh"


class App
{
private:
    /*App preferences*/
    Settings settings;

    /*Signal to convert*/
    Signal signal;

    /**
     * Draw main menu and get user's choice
     *      1 - 4b3t
     *      2 - fomot
     *      3 - switch output
     *      4 - in path
     *      5 - out path
     *      0 - exit
     */
    int8_t main_menu();

    /**
     * Convert to 4B3T with users actions
     */
    void _4b3t_convert();

    /**
     * Convert to fomot with users actions
     */
    void _fomot_convert();

    /**
     * Set path for input file with users actions
     */
    void set_in_path();

    /**
     * Set path for output file with users actions
     */
    void set_out_path();

    /**
     * Switch output format
     */
    void switch_output();
    /**
     * Message to display to downside
     */
    std::string msg_to_display;
    /**
     * Converter 4b3t
     */
    Conv4B3T c4B3T;
    /**
     * Converter FOMOT
     */
    ConvFOMOT cFOMOT;
public:

    App();

    void run();

};

#endif//SIGCONVAPP