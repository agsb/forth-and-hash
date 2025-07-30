#include <stdio.h>
#include <stdlib.h>

char word[33];

unsigned int hash;

void djb2 ( char * name) {

        hash = 5381;

        while ( c = *char++ ) {

                if (c < ' ') continue;

                hash = (( hash << 5) + hash) ^ c;

                }

        return (hash);
        
        }

int main ( int argc, char * argv[]) {

        while ( fgets (word, 32, stdin) ) {
                
                djb2 (word);

                printf ("%0X : %s",hash,word)

                }

        return (0)

        }

                
