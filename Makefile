CFLAGS=-Wall -g -std=c99 -o
CC=gcc

acs_cat: acs_cat.c
	$(CC) $(CFLAGS) $@ $<
