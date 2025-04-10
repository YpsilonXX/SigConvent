#ifndef YPSINPUT
#define YPSINPUT

/**
 *  Используется #ifdef _WIN32 для выбора платформы.
 *
 *  На Windows применяем _getch() дважды для спецклавиш.
 *
 *  На Linux/macOS включаем "raw mode" через termios, ловим escape-последовательности.
 *
 *  Всё обёрнуто в readKey() — универсальную функцию.
 */

#include <iostream>

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <string.h>
#endif
namespace ypskeys{
    enum class KeyType {
        Character,
        ArrowUp,
        ArrowDown,
        ArrowLeft,
        ArrowRight,
        Enter,
        Backspace,
        Escape,
        Unknown
    };

    struct Key {
        KeyType type;
        char ch;  // Только если тип == Character
    };

    #ifndef _WIN32
        void setRawMode(bool enable);
    #endif

    Key readKey();
}
#endif//YPSINPUT