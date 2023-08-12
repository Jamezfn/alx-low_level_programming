#!/bin/bash
gcc -Wall -pedantic -Werror -Wextra -c *.c
ar src liball.a *.o
