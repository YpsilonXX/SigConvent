#ifndef SIGCONVAPP
#define SIGCONVAPP

#include "signal.hh"
#include "defines.hh"
#include "base.hh"
#include "4B3T.hh"
#include "FOMOT.hh"
#include "settings.hh"

class App
{
private:
    /*App preferences*/
    Settings settings;

    /*Signal to convert*/
    Signal signal;

    /**
     * Draw main menu and get user's choice
     */
    int8_t main_menu();

    /**
     * Message to display to downside
     */
    std::string msg_to_display;
public:

    void run();

};

#endif//SIGCONVAPP