#include<stdio.h>
#define max 25
void main(){
	int frag[max],b[max],f[max],c[max],i,j,nb,nf,temp,lowest=10000;
	static int ff[max];
	printf("\n\tMemory Management Scheme - Best Fit");
	printf("\nEnter the number of blocks:");
	scanf("%d",&nb);
	printf("\nEnter the number of files:");
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
			if(temp<lowest && temp>=0){
				lowest=temp;
				ff[i]=j;
			}
		}
		c[i]=b[ff[i]];
		frag[i]=lowest;
		b[ff[i]]=frag[i];
		lowest=10000;
	}
	printf("\nFile No\tFile Size \tBlock No\tBlock Size\tFragment");
	for(i=1;i<=nf;i++){
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],c[i],frag[i]);
	}
	printf("\n");
}
/*
Memory Management Scheme - Best Fit
Enter the number of blocks:3

Enter the number of files:3

Enter the size of the blocks:-
Block 1:100
Block 2:75
Block 3:200
Enter the size of the files :-
File 1:90
File 2:70
File 3:40

File No	File Size 	Block No	Block Size	Fragment
1		90		1		100		10
2		70		2		75		5
3		40		3		200		160
*/