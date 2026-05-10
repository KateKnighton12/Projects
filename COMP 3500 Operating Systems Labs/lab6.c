
/*****************************************************************************\
* Laboratory Exercises Introduction to Operating Systems                      *
* Author: Saad Biaz                                                           *
* Date  : October 22, 2021                                                        *
\*****************************************************************************/

/*****************************************************************************\
*                             Global system headers                           *
\*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/time.h>
#include <math.h>
#include <limits.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>

#include <unistd.h>   /* for getpid, read, write, fork                       */



/*****************************************************************************\
*                             Global data types                               *
\*****************************************************************************/
typedef int             Identifier;
typedef int             Flag;
typedef int             Status;
typedef double          Timestamp;
typedef double          TimePeriod;
typedef unsigned int    Quantity;
typedef double          Average;

/*****************************************************************************\
*                             Global definitions                              *
\*****************************************************************************/
#define  MAXDIMENSION       131072  /* Maxtrix Dimension 2^20                */
#define  FALSE                    0 /* False condition                       */
#define  TRUE                     1 /* True condition                        */

/*****************************************************************************\
*                            Global data structures                           *
\*****************************************************************************/




/*****************************************************************************\
*                                  Global data                                *
\*****************************************************************************/
Timestamp  StartTime;         /* Start time of emulation                     */
char       Matrix[MAXDIMENSION][MAXDIMENSION]; /* Matrix                     */
Quantity   MaxDimension;      /* Max Dimension of Matrix To Initialize       */
Quantity   Step;              /* Step data points                            */
Flag       Version;           /* Version                                     */
FILE       *fileData;  /* File Pointer To Store Data                         */


/*****************************************************************************\
*                               Function prototypes                           *
\*****************************************************************************/
Timestamp Now(void);     
Flag      Initialization(int argc, char **argv);
void      LaunchExperiment(Flag Version);
void      InitializeMatrix0(Quantity Dimension);
void      InitializeMatrix1(Quantity Dimension);
static void StopExperiment(int signo);
  
/*****************************************************************************\
* function: main()                                                            *
* usage:    Initializes an nxn  matrix Matrix[i][j] = '0'                     *
*******************************************************************************
* Inputs: ANSI flat C command line parameters:                                *
*             - largest matrix dimension                                      *
*             - Version (0 or 1)                                              *
* Output: file with execution time for different matrix dimension.            *
\*****************************************************************************/

int main (int argc, char **argv) {
   if (Initialization(argc,argv)){
     LaunchExperiment(Version);
   }
} /* end of main function */

/*****************************************************************************\
* function: LaunchExperiment()                                                *                                 
* usage:    Launches the experiment                                           *                             
*******************************************************************************                              
* Input    : None                                                             *                             
* Output   : None                                                             *                        
* Function : Initializes a matrices with different dimensions and             *                                
*            and collects execution time for each dimension                   *                       
\*****************************************************************************/
void LaunchExperiment(Flag Version){
  int dimension;
  Timestamp Start;
  TimePeriod ExecutionTime;
  //SB_
  // Timestamp NowRecord;


  for (dimension = Step; dimension <= MaxDimension; dimension += Step){
    Start = Now();
    if (!Version){ // (Version == 0)
      InitializeMatrix0(dimension);
    } else {
      InitializeMatrix1(dimension);
    }
    ExecutionTime   = Now() - Start;
    printf("%d    %f\n",dimension, ExecutionTime);
    fprintf(fileData,"%d,    %f\n",dimension, ExecutionTime);
    /* write in file dimension and execution time                            */
  }
  fclose(fileData);
  exit(0);
}

/***********************************************************************\                               
 * Input    : Standard command line parameters                           *                               
 * Output   : Returns a flag TRUE if everything went ok                  *                               
 * Function : Initialize global variables, structures.                   *                               
\***********************************************************************/

Flag Initialization(int argc, char **argv){
  char filename[100];
  if (argc != 4) {
    printf("usage: command MatrixDimension  Step Version(0/1)\n");
    return(FALSE);
  }

  MaxDimension    = (Quantity) atoi(argv[1]);
  if (MaxDimension > MAXDIMENSION){
    printf("Max Matrix Dimension Not To Exceed  %d\n",MAXDIMENSION);
    return(FALSE);
  }

  Step            = (Quantity) atoi(argv[2]);
  if ((Step < 1) || (Step > 65536)){
    printf(" Step must be between 1 to 65536 (included)\n");
    return(FALSE);
  }

  Version = (Flag) atoi(argv[3]);
  if ((Version != TRUE) && (Version != FALSE)){
    printf("Version must be either 0 or 1\n");
    return(FALSE);
  }

  StartTime           = Now();

  signal(SIGINT,StopExperiment);

  
  sprintf(filename,"file-%d-Step%d-Version%d.csv",MaxDimension, Step,Version);

  printf("File name will be %s \n",filename);
  
  fileData = fopen(filename,"w");
  if (fileData == NULL){
    printf("Cannot Open File\n");
    exit(1);
  }

  return(TRUE);

 }

/***********************************************************************\                                  
* Input : Dimension                                                     *
* Output: None                                                          *                                  
* Function: Initialize Matrix Version 0                                 *                                 
\***********************************************************************/
void InitializeMatrix0(Quantity Dimension){
  int i,j;
  for (i = 0; i < Dimension; i++){
    for (j = 0; j < Dimension; j++){
      Matrix[i][j] = '0';
    }
  }
}

/***********************************************************************\
* Input : Dimension                                                     * 
* Output: None                                                          * 
* Function: Initialize Matrix Version 1                                 *  
\***********************************************************************/
void InitializeMatrix1(Quantity Dimension){
  int i,j;
  for (j = 0; j < Dimension; j++){
    for (i = 0; i < Dimension; i++){
      Matrix[i][j] = '0';
    }
  }
}


/***********************************************************************\                                 
* Input : signal number signo (we do not use signo)                     *                                
* Output: None                                                          *                                 
* Function: Turns on Greenlight to allow Process to start its task      *                                 
\***********************************************************************/
static void StopExperiment(int signo){
  signal(SIGINT, StopExperiment);
  fclose(fileData);
  printf("Closed File\n",getpid(), Now());
  exit(1);
}


/***********************************************************************\                                  
 * Input    : None                                                       *                                 
 * Output   : Returns the current system time                            *                                 
\***********************************************************************/
Timestamp Now(){
  struct timeval tv_CurrentTime;
  gettimeofday(&tv_CurrentTime,NULL);
  return( (Timestamp) tv_CurrentTime.tv_sec + (Timestamp) tv_CurrentTime.tv_usec / 1000000.0 - StartTime);
}
