#include "secret_handshake.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char **commands(size_t number) {
  const char **handshakes = malloc(sizeof(char));  
  handshakes[0] = NULL;

  if ((number & 0x1) != 0) {
    handshakes[0] = "wink";
  }

  if ((number & 0x2) != 0) {
    if (handshakes[0] == NULL) {
      handshakes[0] = "double blink";
    } else {
      handshakes = realloc(handshakes, sizeof(char)*2);
      handshakes[1] = "double blink";
    }
  }

  if ((number & 0x4) != 0) {
    if (handshakes[0] == NULL) {
      handshakes[0] = "close your eyes";
    } else {
      handshakes = realloc(handshakes, sizeof(char)*3);
      handshakes[2] = "close your eyes";
    }
  }

  if ((number & 0x8) != 0) {
    if (handshakes[0] == NULL) {
      handshakes[0] = "jump";
    } else {
      handshakes = realloc(handshakes, sizeof(char)*4);
      handshakes[3] = "jump";
    }
  }

  if ((number & 0x10) != 0) {
  //   const char **rev_handshakes = malloc(sizeof(char));
  //   rev_handshakes[0] = NULL;

  //   int len = 0;
  //   while (handshakes[len] != NULL) {
  //     len += 1;
  //   }

  //   for (int i = len; i > 0; i -= 1) {
  //     if (rev_handshakes[(len-1)-i] == NULL) {
  //       rev_handshakes[i - len] = handshakes[i-1];
  //     } else {
  //       rev_handshakes = realloc(rev_handshakes, sizeof(char)*(len-1));
  //     }
  //   }

  //   return rev_handshakes;
  }

  return handshakes;
}
