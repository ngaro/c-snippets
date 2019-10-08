#include <stdio.h> /* printf */

/* printf("\xE2\x98\xA0"); unicode */
/* key discovery: braille in unicode is arranged based on the binary form of 
 * last two hexadecimal digits...?
*/

// 0 3
// 1 4
// 2 5
// 6 7

void getBraille (int* bools, char* string) {

    // first six bools

    char delta = 0;
    char scale = 1;

    for (int i = 0; i < 6; ++i) {

        scale = (char)(i ? (scale << 1) : 1);
        if (bools[i]) delta += scale;

    }

    string[2] = delta - 128;

    // last two bools

    if (bools[6] == bools[7]) {
        string[1] = bools[6] ? '\xA3' : '\xA0';
    } else {
        string[1] = bools[6] ? '\xA0' : '\xA2';
    }

}

int main (void) {

    int idk[8] = {0, 0, 1, 1, 1, 1, 0, 1};

    char braille[4] = {'\xE2',0,0,0};
    
    getBraille(idk,braille);
    printf("%s",braille);

    return 0;

}
