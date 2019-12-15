#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 
typedef struct tschool {
	int grade;
	int class;
	int ID;
}tschool;
 
typedef struct tBlock {
	tschool rankSchool[10];
}tBlock;
 
typedef struct tcity {
	tBlock Block[2];
}tcity;
 
tschool *mySchool = NULL;
tcity *Beijing = NULL;
 
int main()
{
	
	int i = 0;
	int j = 0;
	int block_id = -999;//used for sorting an odd or even ID
	int BlockID = -999;//used for calling after grouping
	mySchool = (tschool *)calloc(10, sizeof(mySchool) * 3);
	Beijing = (tcity *)calloc(10, sizeof(Beijing) * 3);
	//initialize struct member value
	for (i = 1; i < 11; i++) {
		mySchool[i].grade = i * 10;
		mySchool[i].class = 10 - i;
		mySchool[i].ID = i;
	}
	printf("Before ranking!\n");
 
  //print the initial struct member value
	for (i = 1; i < 11; i++) {
		printf("grade of mySchool[%d] is: %d\n", i, mySchool[i].grade);
		printf("class of mySchool[%d] is: %d\n", i, mySchool[i].class);
		printf("ID of mySchool[%d] is: %d\n", i, mySchool[i].ID);
		printf("*************\n");
	}
	
	printf("After ranking!\n");
	
 
	//group 10 schools into 2 Block by sorting their ID (odd or even)
	for (j = 1; j < 11; j++) {
		block_id = mySchool[j].ID % 2;
		Beijing->Block[block_id].rankSchool[j] = mySchool[j];
	
	}
 
  //print the school infos after grouping
	BlockID = 0; 
	printf("printing Block - 0\n");	
	for(i = 2; i < 11; i+=2) {
		printf("grade of Block[0].rankSchool[%d] is: %d\n", i, Beijing->Block[0].rankSchool[i].grade);
		printf("class of Block[0].rankSchool[%d] is: %d\n", i, Beijing->Block[0].rankSchool[i].class);
		printf("ID of Block[0].rankSchool[%d] is: %d\n", i, Beijing->Block[0].rankSchool[i].ID);
		printf("*************\n");
	}
	
	BlockID = 1; 
	printf("printing Block - 1\n");
	for(i = 1; i < 11; i+=2) {
		printf("grade of Block[1].rankSchool[%d] is: %d\n", i, Beijing->Block[1].rankSchool[i].grade);
		printf("class of Block[1].rankSchool[%d] is: %d\n", i, Beijing->Block[1].rankSchool[i].class);
		printf("ID of Block[1].rankSchool[%d] is: %d\n", i, Beijing->Block[1].rankSchool[i].ID);
		printf("*************\n");
	}
 
	free(mySchool);
	free(Beijing);
 
	return 0;
}
