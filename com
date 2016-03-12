 gcc -fPIC -g -c -Wall -Wextra -std=gnu99 init.c
 gcc -shared -Wl,-soname,libinit.1.0 -o libinit init.o
 gcc test.c -o monitor
 LD_PRELOAD=./libinit /bin/ls #echo "From com" #> com_file_out
