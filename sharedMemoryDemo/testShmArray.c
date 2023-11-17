#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/shm.h>


typedef struct
   {
   char a[24];
   int i;
   int j;
   } somestruct;


void fillshm(int shmid) {
   somestruct *p;

   if ( (p = shmat (shmid, NULL, 0)) < 0 )
      {
      perror("shmat");
      exit(1);
      }

   printf("writing to shared memory\n");
   strcpy(p->a, "my shared memory");
   p->i = 123;
   p->j = 456;
}


void printshm(int shmid)
{
   somestruct *p;
   if ( (p = shmat (shmid, NULL, 0)) < 0 )
      {
      perror("shmat");
      exit(1);
      }

   printf( "%s, %d, %d\n", p->a, p->i, p->j );
}

int main( int argc, char *argv[] ) {

   int shmid;

   // see if the memory exists and print it if so
   if ( (shmid = shmget (1234, 0, 0)) >= 0 )
      printshm( shmid );
   else
      {
      // didn't exist, so create it
      if ( (shmid = shmget (1234, sizeof( somestruct ), IPC_CREAT | 0600)) < 0 )
         {
         perror("shmget");
         exit(1);
         }

      printf( "shmid = %d\n", shmid );

      fillshm(shmid);
      printf( "Run another instance of this app to read the memory... (press a key): " );
      getchar();
      int pid = fork();
      if(pid ==0){
        printshm(shmid); 
      }
      else{
        wait(&pid);
      }
      

      // delete it
      if ( shmctl (shmid, IPC_RMID, NULL) < 0 )
         {
         perror("semctl");
         exit(1);
         }
      }

   return 0;
}