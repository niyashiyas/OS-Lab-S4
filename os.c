#include <stdio.h>
#include <string.h>

void main(){
	char fname[15], pat[10], temp[200];
	FILE *fp;
	printf("Enter filename: ");
	scanf("%s",fname);
	printf("Enter pattern or letter to be searched: ");
	scanf("%s",pat);
	fp = fopen(fname, "r");
	while (!feof(fp)){
		fgets(temp,1000,fp);
		if (strstr(temp,pat)){
			printf("%s",temp);	
		}
	}
	fclose(fp);
}
