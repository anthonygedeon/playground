#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER 40
#define INVALID -1

const char BASE64_ENCODER_LUT[65] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 
        'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 
        'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 
        'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 
        'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 
        't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', 
        '2', '3', '4', '5', '6', '7', '8', '9', '+', 
        '/', '=', 
};

/**
 *
 */
const char *ascii_to_binary(const char *ascii) {
    switch (*ascii) {
        case 'a':
            return "01100001";
        case 'b':
            return "01100010";
        case 'c':
            return "01100011";
        case 'd':
            return "01100100";
        case 'e':
            return "01100101";
        case 'f':
            return "01100110";
        case 'g':
            return "01100111";
        case 'h':
            return "01101000";
        case 'i':
            return "01101001";
        case 'j':
            return "01101010";
        case 'k':
            return "01101011";
        case 'l':
            return "01101100";
        case 'm':
            return "01101101";
        case 'n':
            return "01101110";
        case 'o':
            return "01101111";
        case 'p':
            return "01110000";
        case 'q':
            return "01110001";
        case 'r':
            return "01110010";
        case 's':
            return "01110011";
        case 't':
            return "01110100";
        case 'u':
            return "01110101";
        case 'v':
            return "01110110";
        case 'w':
            return "01110111";
        case 'x':
            return "01111000";
        case 'y':
            return "01111001";
        case 'z':
            return "01111010";
        case 'A':
            return "01000001";
        case 'B':
            return "01000010";
        case 'C':
            return "01000011";
        case 'D':
            return "01000100";
        case 'E':
            return "01000101";
        case 'F':
            return "01000110";
        case 'G':
            return "01000111";
        case 'H':
            return "01001000";
        case 'I':
            return "01001001";
        case 'J':
            return "01001010";
        case 'K':
            return "01001011";
        case 'L':
            return "01001100";
        case 'M':
            return "01001101";
        case 'N':
            return "01001110";
        case 'O':
            return "01001111";
        case 'P':
            return "01010000";
        case 'Q':
            return "01010001";
        case 'R':
            return "01010010";
        case 'S':
            return "01010011";
        case 'T':
            return "01010100";
        case 'U':
            return "01010101";
        case 'V':
            return "01010110";
        case 'W':
            return "01010111";
        case 'X':
            return "01011000";
        case 'Y':
            return "01011001";
        case 'Z':
            return "01011010";
        case '0':
            return "00110000";
        case '1':
            return "00110001";
        case '2':
            return "00110010";
        case '3':
            return "00110011";
        case '4':
            return "00110100";
        case '5':
            return "00110101";
        case '6':
            return "00110110";
        case '7':
            return "00110111";
        case '8':
            return "00111000";
        case '9':
            return "00111001";
        case ',':
             return "00101100";
        case ' ':
             return "00100000";
        case '!':
             return "00100001";
    }
    return "";
}

/**
 * Slice string from start to end.
 *
 * @param buffer - copy characters from buffer into `result`.
 * @param start - index to start at.
 * @param end - index to end at.
 *
 * @return the sliced string
 */
char *str_slice(char *buffer, int start, int end) {
    char *result = malloc(10 * sizeof(buffer));
    strncpy(result, buffer + start, end);
    return result;
}

/**
 * Convert Base 2 to Base 10.
 * 
 * @param input the binary number as a char string.
 *
 * @return the decimal equivalent of the binary number.
 */
int convert(const char *input) {
    int sum = 0;
    for (size_t i = strlen(input); i > 0; i--) {
        if (input[i-1] != *"0" && input[i-1] != *"1") {
            return INVALID;
        }
        size_t rev_i = strlen(input)-i; // count from 0 to len(input)
        if (input[i-1] == *"0") {
            continue;
        }
        sum += pow(2, rev_i);
    }
    return sum;
}

/**
 *
 */
char *base64(const char *input) {
        
    char *result = malloc(1000 * sizeof(char) * strlen(input));

    char *binary = malloc(100 * sizeof(char) * strlen(input));
        
    int counter = 0;

    for (const char *i = input; *i != '\0'; i++) {
        strcat(binary, ascii_to_binary(i));
    }

    for (int i = 0; i < (int)strlen(binary); i += 6) {
        char *slice = str_slice(binary, i, 6);
        counter++;
        
        if (counter == 4) {
                counter = 0;                
        } 

        if (strlen(slice) < 6 ) {
            while (strlen(slice) - 6 != 0)  {
                strcat(slice, "0");
            }
        }

        int base64_decimal = convert(slice);
        strncat(result, &BASE64_ENCODER_LUT[base64_decimal], 1);
    }

    if (counter != 0) {
        for (int i = 0;  i < (4 - counter); i++) {
                strcat(result, "=");
        }
    }
    
    return result;
}

int main(void) {

        assert(!strcmp("TWFu", base64("Man")));
        assert(!strcmp("aGVsbG8=", base64("hello")));
        assert(!strcmp("YQ==", base64("a")));
        assert(!strcmp("Z29vZGJ5ZQ==", base64("goodbye")));
        assert(!strcmp("SGVsbG8sIFdvcmxkIQ==", base64("Hello, World!")));

        return 0;
}
