/* 
 * Operating Systems  (2INCO)  Practical Assignment
 * Threaded Application
 *
 * STUDENT_NAME_1 (STUDENT_NR_1)
 * STUDENT_NAME_2 (STUDENT_NR_2)
 *
 * Grading:
 * Students who hand in clean code that fully satisfies the minimum requirements will get an 8. 
 * Extra steps can lead to higher marks because we want students to take the initiative. 
 * 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>     // for perror()
#include <pthread.h>

#include "uint128.h"
#include "flip.h"

// create a bitmask where bit at position n is set
#define BITMASK(n)          (((uint128_t) 1) << (n))

// check if bit n in v is set
#define BIT_IS_SET(v,n)     (((v) & BITMASK(n)) == BITMASK(n))

// set bit n in v
#define BIT_SET(v,n)        ((v) =  (v) |  BITMASK(n))

// clear bit n in v
#define BIT_CLEAR(v,n)      ((v) =  (v) & ~BITMASK(n))



int main (void)
{
    // TODO: start threads to flip the pieces and output the results
    // (see thread_test() and thread_mutex_test() how to use threads and mutexes,
    //  see bit_test() how to manipulate bits in a large integer)

    int buffer_elements = (NROF_PIECES/128) + 1;

 //   uint128_t temp;

    for (int i = 0; i < buffer_elements; i++)    {
        buffer[i] = 0x2;                    //  Make the last two bits 10
        for(int j = 0; j < 64; j++){
            buffer[i] = buffer[i] << 2;         //  Shift every bit by two: 00010 -> 01000
            buffer[i] = buffer[i] | 0x2;        //  Make 2nd last bit 1:    01000 -> 01010
//            temp = buffer[0];
        }
    }

    

    return (0);
}

