// Copyright(c) 2024 Aashish Adhikari
// This software is distributed under MIT license

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>

#define MOUSEFILE "/dev/input/event9"
//#define TOUCHPAD "/dev/input/event0"

void createSpot(){
    system("gsettings set org.gnome.desktop.interface cursor-theme Spotlight");
}

void offSpot(){
    system("gsettings set org.gnome.desktop.interface cursor-theme Adwaita");
}

int main()
{
	int fd;
	struct input_event ie;

	if((fd = open(MOUSEFILE, O_RDONLY)) == -1) {
		perror("opening device");
		exit(EXIT_FAILURE);
	}

	while(read(fd, &ie, sizeof(struct input_event))) {
    if(ie.value==120){
      createSpot();
    }
    if(ie.value==-120){
      offSpot();
    }
		printf("time %ld.%06ld\ttype %d\tcode %d\tvalue %d\n",
		       ie.time.tv_sec, ie.time.tv_usec, ie.type, ie.code, ie.value);
	}

	return 0;
}
