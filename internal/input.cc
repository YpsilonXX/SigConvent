#include "input.hh"

namespace ypskeys{
    #ifdef _WIN32

        Key readKey() {
            int ch = _getch();

            if (ch == 0 || ch == 224) {
                int code = _getch();
                switch (code) {
                    case 72: return { KeyType::ArrowUp, 0 };
                    case 80: return { KeyType::ArrowDown, 0 };
                    case 75: return { KeyType::ArrowLeft, 0 };
                    case 77: return { KeyType::ArrowRight, 0 };
                    default: return { KeyType::Unknown, 0 };
                }
            } else if (ch == 13) {
                return { KeyType::Enter, 0 };
            } else if (ch == 27) {
                return { KeyType::Escape, 0 };
            } else if (ch == 8) {
                return { KeyType::Backspace, 0 };
            } else {
                return { KeyType::Character, static_cast<char>(ch) };
            }
        }

    #else  // Linux/macOS

        void setRawMode(bool enable) {
            static struct termios oldt, newt;
            static bool initialized = false;

            if (!initialized) {
                tcgetattr(STDIN_FILENO, &oldt);
                newt = oldt;
                newt.c_lflag &= ~(ICANON | ECHO);
                initialized = true;
            }

            tcsetattr(STDIN_FILENO, TCSANOW, enable ? &newt : &oldt);
        }

        Key readKey() {
            setRawMode(true);

            char ch;
            read(STDIN_FILENO, &ch, 1);

            if (ch == 27) { // ESC
                char seq[2];
                if (read(STDIN_FILENO, &seq[0], 1) == 0) {
                    setRawMode(false);
                    return { KeyType::Escape, 0 };
                }
                if (read(STDIN_FILENO, &seq[1], 1) == 0) {
                    setRawMode(false);
                    return { KeyType::Unknown, 0 };
                }

                if (seq[0] == '[') {
                    switch (seq[1]) {
                        case 'A': setRawMode(false); return { KeyType::ArrowUp, 0 };
                        case 'B': setRawMode(false); return { KeyType::ArrowDown, 0 };
                        case 'C': setRawMode(false); return { KeyType::ArrowRight, 0 };
                        case 'D': setRawMode(false); return { KeyType::ArrowLeft, 0 };
                    }
                }

                setRawMode(false);
                return { KeyType::Unknown, 0 };
            } else if (ch == 10 || ch == 13) {
                setRawMode(false);
                return { KeyType::Enter, 0 };
            } else if (ch == 127 || ch == 8) {
                setRawMode(false);
                return { KeyType::Backspace, 0 };
            } else {
                setRawMode(false);
                return { KeyType::Character, ch };
            }
        }

    #endif
}