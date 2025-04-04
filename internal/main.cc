#include <iostream>
#include <thread>
#include <chrono>

#include "signal.hh"
#include "defines.hh"
#include "base.hh"

int main()
{
    Signal sig;

    sig.read();
    sig.display();

    return 0;
}