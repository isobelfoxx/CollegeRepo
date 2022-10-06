#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

#define KEY 10

struct message {
       char text[100];
       int  timestamp;
       char username[100];
};

void main()
{
     pid_t childpid; int idm, idw; struct message *shmaddress;
     idm = shmget(KEY, sizeof(struct message), IPC_CREAT|0666); //rw_rw_rw

     if (idm < 0) 
     {
          perror("shmget status:"); //print why call failed, e.g. no memory
          exit(1);
     } //end of shmget()

     shmaddress= (struct message *)shmat(idm,0,0);
     if (shmaddress<= (struct message *)NULL) 
     {
          perror("shmat status:");
          exit(2);
     }

     /* inter-process communicate via ptr(shmaddress)
     can now take place between child and parent */
     childpid = fork();
     if (childpid == 0)
     { //must be child process
          while(1)
          {
               printf("Please enter a message \n\n");
               fgets(shmaddress->text,100,stdin);
               shmaddress->timestamp = time(NULL);
               printf("\n(written at t=%i from user=%s)\n\n",shmaddress->timestamp,shmaddress->username);

          }
     }
     

     else 
     { //must be parent process
          int  oldtimestamp;
          oldtimestamp = 0;
          while(1)
         {
         
               if(shmaddress->timestamp != oldtimestamp)
               {
                    printf("The Parent reads the message from shared mem as %s", shmaddress->text);
                    printf("written at t=%i\n\n", shmaddress->timestamp);
               }
               
          oldtimestamp = shmaddress->timestamp; 
          strcpy(shmaddress->username, getenv("USER"));
          sleep(1); 
          }
     }
} //main











#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

#define KEY 10

struct message {
       char text[100];
       int  timestamp;
       char username[100];
};

int ans;

void main()
{
     pid_t childpid; int idm, idw; struct message *shmaddress;
     idm = shmget(KEY, sizeof(struct message), IPC_CREAT|0666); //rw_rw_rw

     if (idm < 0) 
     {
          perror("shmget status:"); //print why call failed, e.g. no memory
          exit(1);
     } //end of shmget()

     shmaddress= (struct message *)shmat(idm,0,0);
     if (shmaddress<= (struct message *)NULL) 
     {
          perror("shmat status:");
          exit(2);
     }

     /* inter-process communicate via ptr(shmaddress)
     can now take place between child and parent */
     childpid = fork();
     if (childpid == 0)
     { //must be child process
          while(1)
          {
               printf("Please enter a message \n\n");
               fgets(shmaddress->text,100,stdin);
               shmaddress->timestamp = time(NULL);
               printf("\n(written at t=%i from user=%s)\n\n",shmaddress->timestamp,shmaddress->username);
               printf ("\nDo you wish to continue?(1 for yes, 0 for no)\n");
               scanf ("%d", &ans);
          }
     }

     else 
     { //must be parent process
          int  oldtimestamp;
          oldtimestamp = 0;
          while(1)
         {
         
               if(shmaddress->timestamp != oldtimestamp)
               {
                    printf("The Parent reads the message from shared mem as %s", shmaddress->text);
                    printf("written at t=%i\n\n", shmaddress->timestamp);
               }
       
          oldtimestamp = shmaddress->timestamp; 
          strcpy(shmaddress->username, getenv("USER"));
          sleep(1); 
          }
     }
     exit(0); 
} //main
