#include "fun.h"
#include <cctype>
#include <cmath>

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    const char *wordStart = nullptr;
    bool inWord = false;

    while (*str) {
        if (std::isspace(*str)) {
            if (inWord) {
                inWord = false;
                const char *ptr = wordStart;
                bool hasDigit = false;
                while (ptr < str) {
                    if (std::isdigit(*ptr)) {
                        hasDigit = true;
                        break;
                    }
                    ptr++;
                }
                if (!hasDigit) {
                    count++;
                }
            }
        } else {
            if (!inWord) {
                inWord = true;
                wordStart = str;
            }
        }
        str++;
    }

    if (inWord) {
        const char *ptr = wordStart;
        bool hasDigit = false;
        while (*ptr) {
            if (std::isdigit(*ptr)) {
                hasDigit = true;
                break;
            }
            ptr++;
        }
        if (!hasDigit) {
            count++;
        }
    }

    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool startUppercase = false;

    while (*str) {
        if (std::isspace(*str)) {
            if (inWord) {
                inWord = false;
                if (startUppercase) {
                    bool onlyLowercase = true;
                    const char *ptr = str - 1;
                    while (ptr >= str - 1 - count) {
                        if (!std::islower(*ptr)) {
                            onlyLowercase = false;
                            break;
                        }
                        ptr--;
                    }
                    if (onlyLowercase) {
                        count++;
                    }
                }
            }
        } else {
            if (!inWord) {
                inWord = true;
                startUppercase = std::isupper(*str);
            }
        }
        str++;
    }

    if (inWord && startUppercase) {
        bool onlyLowercase = true;
        const char *ptr = str - 1;
        while (ptr >= str - 1 - count) {
            if (!std::islower(*ptr)) {
                onlyLowercase = false;
                break;
            }
            ptr--;
        }
        if (onlyLowercase) {
            count++;
        }
    }

    return count;
}

unsigned int faStr3(const char *str) {
    unsigned int sumLength = 0;
    unsigned int wordCount = 0;
    bool inWord = false;

    while (*str) {
        if (isspace(*str)) {
            inWord = false;
        } else {
            if (!inWord) {
                ++wordCount;
            }
            ++sumLength;
            inWord = true;
        }
        ++str;
    }

    return (sumLength + wordCount - 1) / wordCount;
}
