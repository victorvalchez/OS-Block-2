<<<<<<< HEAD
<<<<<<< HEAD
=======


>>>>>>> 4bf36ed (new)
=======
>>>>>>> 978a8f7 (final)
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
<<<<<<< HEAD
<<<<<<< HEAD
  int fd, size;
  char *buf1="abc";
=======
  int fd;
  char buf1[]="abc";
>>>>>>> 4bf36ed (new)
=======
  int fd, size;
  char *buf1="abc";
>>>>>>> 978a8f7 (final)
  char buf2[]="ABC";
  
  /* creat() creates a file and is equivalent to open() with flags equal to O_CREAT|O_WRONLY|O_TRUNC 
     i.e. If a file does not exist, it creates it and opens it write only. 
          If the file exists, it truncates it (deletes the whole content) and opens it write only.
     NOTE: If you do not want to make sure that a file exist and you do not want to truncate it, 
     use  open(fd, O_CREAT|O_RDWR, 0666). This creates a file if it does not exist and opens 
     a file if it does exist without truncating it.

     Question: After using  open(fd, O_CREAT|O_RDWR, 0666), how can you find out if the file is empty or  not?      

  */ 

<<<<<<< HEAD
<<<<<<< HEAD
  if ( (fd=creat("file_hole.txt",0666))<0)
=======
  if ( (fd=creat("file_hole",0666))<0)
>>>>>>> 4bf36ed (new)
=======
  if ( (fd=creat("file_hole.txt",0666))<0)
>>>>>>> 978a8f7 (final)
  {
    perror("error creating the file");
    exit(1);
  }


  if ( write(fd,buf1,3)< 0) {
    perror("write error");
    exit(1);		
  }

<<<<<<< HEAD
<<<<<<< HEAD
  if((size = lseek(fd,100,SEEK_CUR)) < 0) { // a la current position le sumamos 100
     perror("seek error");
     exit(1);
  }
  printf("Size is: %d\n", size);
=======
  if( lseek(fd,100,SEEK_CUR) < 0) {
     perror("seek error");
     exit(1);
  }
>>>>>>> 4bf36ed (new)
=======
  if((size = lseek(fd,100,SEEK_CUR)) < 0) { // a la current position le sumamos 100
     perror("seek error");
     exit(1);
  }
  printf("Size is: %d\n", size);
>>>>>>> 978a8f7 (final)

  if ( write(fd,buf2,3) <0) {    
    perror("write error");
    exit(1);
  }
  

  if (close(fd)<0){    
    perror("close error");
    exit(1);
  }
 
  return 0;
}
