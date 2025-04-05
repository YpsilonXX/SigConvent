#include "base.hh"

void clearConsole() {
    std::cout << "\033[2J\033[1;1H"; // Очистка и курсор в 1,1
}

namespace ypsbit
{
    uint16_t get_bit(uint8_t src, uint8_t pos)
    {
        return (src >> pos) & 1;
    }

    uint8_t set_bit(uint8_t src, uint8_t pos)
    {
        return src | (1 << pos);
    }

    uint8_t clear_bit(uint8_t src, uint8_t pos)
    {
        return src & ~(1 << pos);
    }
}