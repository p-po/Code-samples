#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main() {
int fd = open("/home/ponnuvel/share_library/outfile", O_WRONLY);
puts("Kane");
/*while(1) {
    write(fd, "Hello, world!\n", 14); 
    sleep(2);
}*/

}
