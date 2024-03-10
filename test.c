#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>

#define MOUSEFILE "/dev/input/mice"

int main()
{
	int fd;
	struct input_event ie;

	if((fd = open(MOUSEFILE, O_RDONLY)) == -1) {
		perror("opening device");
		exit(EXIT_FAILURE);
	}

	while(read(fd, &ie, sizeof(struct input_event))) {
   // if(ie.time.tv_sec>16771976){
    //  printf("Time for spotlight\n");
    //}
    if(ie.type=EV_REL && ie.code==REL_X){
      printf("relative  moved  and wheel moved:%d\n",ie.value);
    }
    if(ie.type=EV_ABS){
      printf("absolute movement\n");
    }
    if(ie.type=EV_KEY && ie.code==BTN_TOOL_DOUBLETAP){
      printf("Button clicked\n");
    }
		printf("time %ld.%06ld\ttype %d\tcode %d\tvalue %d\n",
		       ie.time.tv_sec, ie.time.tv_usec, ie.type, ie.code, ie.value);
	}

	return 0;
}
