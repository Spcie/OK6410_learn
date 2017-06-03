 #include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	FILE *fb0 = NULL;
	char Buf[4096];
	
	strcpy(Buf,"Mem is char dev!");
	printf("BUF:%s\n", Buf);

	fb0 = fopen("/dev/memdev", "r+");

	if(fb0 == NULL)
	{
		printf("Open mem Error!\n");
		return -1;
	}

	fwrite(Buf,sizeof(Buf),1,fb0);

	fseek(fb0,0,SEEK_SET);

	strcpy(Buf,"Buf is NULL!");
	printf("BUF: %s\n",Buf);

	fread(Buf,sizeof(Buf),1,fb0);

	printf("BUF:%s\n", Buf);

	return 0;
}