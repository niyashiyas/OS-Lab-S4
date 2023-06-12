#include<stdio.h>
#define max 25
void main(){
	int frag[max],b[max],f[max],c[max],i,j,nb,nf,temp,highest=-1;
	static int bf[max],ff[max];
	printf("\n\tMemory Management Scheme - Worst Fit");
	printf("\nEnter Number of blocks: ");
	scanf("%d",&nb);
	printf("\nEnter Number of Files: ");
	scanf("%d",&nf);
	printf("\nEnter size of blocks: \n");
	for(i=1;i<=nb;i++){
		printf("Block %d:",i);
		scanf("%d",&b[i]);
	}
	printf("Enter Size of files: \n");
	for(i=1;i<=nf;i++){
		printf("File %d:",i);
		scanf("%d",&f[i]);
	}
	for(i=1;i<=nf;i++){
		for(j=1;j<=nb;j++){
			if(b[j]>highest){
				highest=b[j];
				ff[i]=j;
			}
		}
		c[i]=highest;
		frag[i]=highest-f[i];
		b[ff[i]]=frag[i];
		highest=0;
	}
	printf("\nFile no: \tFile Size: \tBlock no: \tBlock Size: \tFragment");
	for(i=1;i<=nf;i++)
		printf("\n%d \t\t%d \t\t%d \t\t %d \t\t%d",i,f[i],ff[i],c[i],frag[i]);
		printf("\n");
}
/*
	Memory Management Scheme - Worst Fit
Enter Number of blocks: 3

Enter Number of Files: 4

Enter size of blocks: 
Block 1:100
Block 2:75
Block 3:200
Enter Size of files: 
File 1:50
File 2:50
File 3:100
File 4:75

File no: 	File Size: 	Block no: 	Block Size: 	Fragment
1 		50 		3 		 200 		150
2 		50 		3 		 150 		100
3 		100 		1 		 100 		0
4 		75 		3 		 100 		25
*/