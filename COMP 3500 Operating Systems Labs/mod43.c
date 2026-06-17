#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int nloop = 240;

/**********************************************************\
 * Function: increment a counter by some amount one by one *
 * argument: ptr (address of the counter), increment       *
 * output  : nothing                                       *
 **********************************************************/
void add_n(int *ptr, int increment){
  int i,j;
  for (i=0; i < increment; i++){
    *ptr = *ptr + 1;
    for (j=0; j < 7000000;j++);
  }
}

int main(){
  int pid;        /* Process ID                     */

  int *countptr;  /* pointer to the counter         */
  int *turnptr, *Interested0ptr, *Interested1ptr; // Peterson's Solution variables

  int fd;     /* file descriptor to the file "containing" my counter */
  int fd_turn, fd_Interested0, fd_Interested1;

  int zero = 0; /* a dummy variable containing 0 */

  system("rm -f counter");
  system("rm -f turn");
  system("rm -f Interested0");
  system("rm -f Interested1");

  /* create files which will "contain" my shared variables */
  fd = open("counter",O_RDWR | O_CREAT);
  write(fd,&zero,sizeof(int));

  fd_turn = open("turn",O_RDWR | O_CREAT);
  write(fd_turn,&zero,sizeof(int));

  fd_Interested0 = open("Interested0",O_RDWR | O_CREAT);
  write(fd_Interested0,&zero,sizeof(int));

  fd_Interested1 = open("Interested1",O_RDWR | O_CREAT);
  write(fd_Interested1,&zero,sizeof(int));


  /* map my files to memory */
  countptr       = (int *) mmap(NULL, sizeof(int),PROT_READ | PROT_WRITE, MAP_SHARED, fd,0);
  turnptr        = (int *) mmap(NULL, sizeof(int),PROT_READ | PROT_WRITE, MAP_SHARED, fd_turn,0);
  Interested0ptr = (int *) mmap(NULL, sizeof(int),PROT_READ | PROT_WRITE, MAP_SHARED, fd_Interested0,0);
  Interested1ptr = (int *) mmap(NULL, sizeof(int),PROT_READ | PROT_WRITE, MAP_SHARED, fd_Interested1,0);

  if ((!countptr) || (!turnptr) || (!Interested0ptr) || (!Interested1ptr)) {
    printf("Mapping failed\n");
    exit(1);
  }

  *countptr       = 0;
  *turnptr        = 0;
  *Interested0ptr = 0;
  *Interested1ptr = 0;

  close(fd);
  close(fd_turn);
  close(fd_Interested0);
  close(fd_Interested1);


  setbuf(stdout,NULL);

  pid = fork();
  if (pid < 0){
    printf("Unable to fork a process\n");
    exit(1);
  }

  if (pid == 0) {
    /* The child increments the counter by two's */
    while (*countptr < nloop){
      // Entry to Critical Region
      *Interested0ptr = 1; *turnptr = 1;
      while ((*Interested1ptr == 1) && (*turnptr == 1));

      // Critical Region
      add_n(countptr,2);

      // Exit code out of Critical Region
      *Interested0ptr =0;

      printf("Child process -->> counter= %d\n",*countptr);
    }
    close(fd);
    close(fd_turn);                                                                                      
    close(fd_Interested0);                                                                                 
    close(fd_Interested1);  
  }
  else {
    /* The parent increments the counter by twenty's */
    while (*countptr < nloop){
      // Entry to Critical Region                                                                          
      *Interested1ptr = 1; *turnptr = 0;
      while ((*Interested0ptr == 1) && (*turnptr == 0));

      // Critical Region                                                                                   
      add_n(countptr,20);

      // Exit code out of Critical Region                                                                  
      *Interested1ptr =0;
      
      printf("Parent process -->> counter = %d\n",*countptr);
    }
    close(fd);
    close(fd_turn);
    close(fd_Interested0);
    close(fd_Interested1);
  }
}









