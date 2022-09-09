#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main(int argc, char* argv[])
{
    int ans, key;
    printf("Press 1 to Encrypt file.\nPress 2 to Decrypt file.\n");
    scanf("%d", &ans);
    printf("Enter Key -\n");
    scanf("%d", &key);
    if (ans == 1)
    {
        char c;
        int fd,fd1;
        fd = open(argv[1], O_RDWR) ;
        fd1 = open(argv[2], O_RDWR) ;
        while(read(fd, &c, 1) > 0)
        {
            c = c + key;
            write(fd1, &c, 1);
        }
       printf("File Encrypted.\n");
       close(fd);
       close(fd1);
    }
    else if (ans == 2)
    {
        char c;
        int fd, fd1;
        
        fd = open(argv[1], O_RDWR) ;
        fd1 = open(argv[2], O_RDWR) ;
        
        while(read(fd, &c, 1) > 0)
        {
            c = c - key;
            write(fd1, &c, 1);
        }
        
        printf("File Decrypted.\n");
        close(fd);
        close(fd1);

    }
    else
    {
        printf("Invalid Input");
    }

    return 0;
}
