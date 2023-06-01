#include <stdio.h>

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

void main() {
	int a;
	int b;
	//printf("Enter Rule:");
	//scanf("%d", &a);
	//printf("Enter Lines:");
	//scanf("%d", &b);
	//init();
	a = 151;
	b = 1000;
	display();
	rule(a);
	for(int i=0; i<b; i++) {
		next();
		display();
	}
}
