#include <stdio.h>
#include <stdlib.h>

int line[100];
int update[100];
int length = 99;
int b[50];

void init();
void display();
void rule(int a);
void next();

void init() {
	for (int i=0; i<length; i++) line[i] = 0;
	line[0] = 1;
}

void display() {
	for(int i=0; i<length; i++) {
		if (line[i] == 1) printf("#");
		else printf(" ");
	}
	printf("\n");
}

void rule(int a) {
	for(int i=0; i<8; i++) {
		if(a != 0) {
			b[i] = a%2;
			a/=2;
		} else {
			b[i] = 0;
		}
	}
}

void next() {
	for(int i=0; i<length; i++) {
		if(i==0) {
			if(line[i]==0 && line[i+1]==0) update[i] = b[0];
			else if(line[i]==0 && line[i+1]==1) update[i] = b[1];
			else if(line[i]==1 && line[i+1]==0) update[i] = b[2];
			else if(line[i]==1 && line[i+1]==1) update[i] = b[3];
		} else if(i==length-1) {
			if(line[i-1]==0 && line[i]==0) update[i] = b[0];
			else if(line[i-1]==0 && line[i]==1) update[i] = b[1];
			else if(line[i-1]==1 && line[i]==0) update[i] = b[2];
			else if(line[i-1]==1 && line[i]==1) update[i] = b[3];
		} else if(i>0 && i<length-1) {
			if(line[i-1]==0 && line[i]==0 && line[i+1]==0) update[i] = b[0];
			else if(line[i-1]==0 && line[i]==0 && line[i+1]==1) update[i] = b[1];
			else if(line[i-1]==0 && line[i]==1 && line[i+1]==0) update[i] = b[2];
			else if(line[i-1]==0 && line[i]==1 && line[i+1]==1) update[i] = b[3];
			else if(line[i-1]==1 && line[i]==0 && line[i+1]==0) update[i] = b[4];
			else if(line[i-1]==1 && line[i]==0 && line[i+1]==1) update[i] = b[5];
			else if(line[i-1]==1 && line[i]==1 && line[i+1]==0) update[i] = b[6];
			else if(line[i-1]==1 && line[i]==1 && line[i+1]==1) update[i] = b[7];
		}
	}
	for (int i=0; i<length; i++) line[i] = update[i];
}

void output(int seed, int lines, int width) {
	length = width;
	char fileName[10];
	FILE *fp;
	sprintf(fileName, "%d.txt", seed);
	fp = fopen(fileName, "w");
	if (fp == NULL) {
		printf("Could not create file %d\n", seed);
	}
	rule(seed);
	for(int i=0; i<lines; i++) {
		next();
		for(int i=0; i<length; i++) {
			if (line[i] == 1) fprintf(fp, "1");
			else fprintf(fp, "0");
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
}


int main() {
	for (int i = 0; i < 256; ++i)
	{
		output(i, 2400, 120);
	}
    
    return 0;
}
