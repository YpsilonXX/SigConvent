#ifndef YPSBASE
#define YPSBASE

#include <iostream>
#include <cstdint>

/*Очистка консоли*/
void clearConsole();

namespace ypsbit
{
    /**
     * Get value of bit
     * \param src source
     * \param pos position
     * \return 0 or 1
     */
    uint16_t get_bit(uint8_t src, uint8_t pos);

     /**
     * Set bit
     * \param src source
     * \param pos position
     * \return Edit src
     */
    uint8_t set_bit(uint8_t src, uint8_t pos);

    /**
     * Clear bit
     * \param src source
     * \param pos position
     * \return Edit src
     */
    uint8_t clear_bit(uint8_t, uint8_t pos);
}

#endif//YPSBASE