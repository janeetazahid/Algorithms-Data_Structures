#include <stdlib.h>
#include "towers.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int n = 3;
    int from = 1;
    int dest = 2;
    if (argc ==1) {
        
	towers(n, from, dest);
	}
    else if (argc ==2){
	n= atoi (argv[1]);
	from =1;
	dest=2;
	towers(n, from, dest);
	}
    else if (argc==4){
	if(atoi(argv[2])!=atoi(argv[3])&&atoi(argv[2])<=3&&atoi(argv[3])<=3){
	n=atoi(argv[1]);
	from=atoi(argv[2]);
	dest=atoi(argv[3]);
	towers(n, from, dest);
	exit(0);}
	else if(atoi(argv[2])==atoi(argv[3])) {
	printf("The destination and starting point cannot be the same\n");
	exit(1);
	}
	else if (atoi(argv[3])>3||atoi(argv[2])>3){
		printf("The destination or current spot cannot be more than 3\n");
	exit(1);
	}
}
	else if (argc>4||argc==3){
	printf("you do not have the apporpirate number of command line argumnets\n");
	return(1);
	}

	
    exit(0);
}

