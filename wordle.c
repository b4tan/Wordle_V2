#include "wordle.h"
#include <stdio.h>
#include <string.h>
/**
 * Play the wordle game.
 *
 * key          The answer word. Should be lowercase only.
 * nattempts    The total number of attempts allowed.
 * attempts     An array of string buffers to keep track of each attempt.
 * return       Number of guesses the player took to guess the right word,
 *              return 0 if player failed to guess the word.
 */
int wordle(const char *key, int nattempts, char **attempts)
{
    /* TODO: Implement this function
     * You should be able to copy-paste the body of your part 1 wordle 
     * function here without any modifications. Do NOT change the parameters
     * to this function when you do so. The type of `attempts` must be (char **) 
     * in part 2.
     */
    // initialize template for question
     int length = strlen(key);
     int attempt_num = 1;
     char template[15];
     for (int t = 0; t < length; t++) {
        template[t] = '_';
     }
     // for the 6 guesses...
     for(int i = 0; i < nattempts; i++) { 
        for (int m = 0; m < length; m++) {
            printf("%c", template[m]);
        }
        printf("\r");
         // get input
         get_input(attempts[i], length);
         // if the word is truly correct then
         if (strcmp(attempts[i], key) == 0) {
            return attempt_num;
         } else {
         // traverse through the columns
            for(int k = 0; k < length; k ++) {
                    // traverse through the keygen
                for (int count = 0; count < length; count++) {
                    // if element in input matches with element in keygen
                    if (attempts[i][k] == key[count]) {
                        template[count] = attempts[i][k];
                        //  attempts[i][count] = key[count];
                    }
                }
            }
            // printf("%s\r", template);
            // for (int m = 0; m < length; m++) {
            //     printf("%c", template[m]);
            // }
            // printf("\r");
         }
         attempt_num++;
     }
     return 0;
}
