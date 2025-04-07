#include <iostream>
#include <thread>
#include <chrono>

#include "signal.hh"
#include "defines.hh"
#include "base.hh"
#include "4B3T.hh"
#include "FOMOT.hh"

int main()
{
    Signal sig;

    sig.fread("../build/in.txt");
    sig.display();

    ConvFOMOT con;
    std::vector<SBlock> signal = sig.get_blocks();
    con.convert_to_console(0, signal);
    con.convert_to_console(0, signal);
    con.convert_to_file(0, signal, "../build/out.txt");

    return 0;
}