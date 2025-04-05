#include <iostream>
#include <thread>
#include <chrono>

#include "signal.hh"
#include "defines.hh"
#include "base.hh"

int main()
{
    Signal sig;


    sig.fread();
    sig.display();

    return 0;
}