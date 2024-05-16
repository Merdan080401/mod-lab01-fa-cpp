#include "fun.h"
#include <cctype>
#include <cmath>

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool inWord = false;

    while (*str) {
        if (isspace(*str)) {
            inWord = false;
        } else {
            if (!isdigit(*str) && !inWord) {
                ++count;
            }
            inWord = true;
        }
        ++str;
    }

    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool inWord = false;

    while (*str) {
        if (isspace(*str)) {
            inWord = false;
        } else {
            if (isupper(*str) && !inWord) {
                ++count;
            } else if (inWord && !islower(*str)) {
                inWord = false;
            }
            inWord = true;
        }
        ++str;
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
