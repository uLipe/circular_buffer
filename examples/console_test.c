/**
 * @brief simple console test with circular buffer
 */

#include <stdio.h>
#include <stdlib.h>
#include "circular_buffer.h"

/* declare a buffer */
CIRCULAR_BUFFER_DECLARE(console_buffer);



/**
 * @brief circular buffer test application
 */
 int main(int argc, char **argv)
 {
    unsigned char data = {0};
    int size = 0;

    printf("How much characteres you want to put?  ");
    scanf("%d", &size);
    for(unsigned int i = 0; i < size; ++i) {
      printf("Enter the %d value:  ",i);
      scanf("%hu", &data);

      /* put the new byte on buffer
       * NOTE! We dont need to manage our buffer
       */
      buffer_insert(&console_buffer,&data, 1);
    }

    /* prints the buffer contents */
    printf("The buffer contents are \n\r");
    while(buffer_empty(&console_buffer) == 0) {

        /* extracts byte to byte from buffer, higher sizes streams are supported
         * but this mode shows better the capabilities of circ buffer
         */
        buffer_retrieve(&console_buffer, &data, 1);
        printf("%hu",&data );
    }

    /* wait for a key */
    scanf("%hu", &data);
    return(0);

 }
