sudo chown aashish /dev/input/event16 && gcc -lpthread $( pkg-config --cflags gtk4 ) -o main main.c $( pkg-config --libs gtk4 )
