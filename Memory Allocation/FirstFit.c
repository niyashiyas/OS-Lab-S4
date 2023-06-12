#include<stdio.h>
#define max 25
void main(){
	int frag[max],b[max],f[max],c[max],i,j,nb,nf,temp;
	static int ff[max];
	printf("\n\tMemory Management Scheme - First Fit");
	printf("\nEnter the number of blocks:");
	scanf("%d",&nb);
	printf("Enter the number of files:");
	scanf("%d",&nf);
	printf("\nEnter the size of the blocks:-\n");
	for(i=1;i<=nb;i++){
		printf("Block %d:",i);
		scanf("%d",&b[i]);
	}
	printf("Enter the size of the files :-\n");
	for(i=1;i<=nf;i++){
		printf("File %d:",i);
		scanf("%d",&f[i]);
	}
	for(i=1;i<=nf;i++){
		for(j=1;j<=nb;j++){
				temp=b[j]-f[i];
				if(temp>=0){
					ff[i]=j;
					break; 
				}
		}
		c[i]=b[ff[i]];
		frag[i]=temp;
		b[ff[i]]=frag[i];
	}
	printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
	for(i=1;i<=nf;i++)
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],c[i],frag[i]);
	printf("\n");
}
/*

	Memory Management Scheme - First Fit
Enter the number of blocks:3
Enter the number of files:4

Enter the size of the blocks:-
Block 1:100
Block 2:75
Block 3:200
Enter the size of the files :-
File 1:50
File 2:50
File 3:100
File 4:75

File_no:	File_size :	Block_no:	Block_size:	Fragement
1		50		1		100		50
2		50		1		50		0
3		100		3		200		100
4		75		2		75		0
*/