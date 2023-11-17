/* Filename: shm_read.c */
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

#define BUF_SIZE 1024
#define SHM_KEY 0x1234

/*

ftok()      key_t ftok()
            It is used to generate a unique key.

shmget()	int shmget(key_t key,size_t size, int shmflg);
            Upon successful completion, shmget() returns an identifier for the shared memory segment.

shmat()	    void *shmat(int shmid ,void *shmaddr ,int shmflg); 
            Before you can use a shared memory segment, you have to attach yourself to it using shmat(). Here, shmid is a shared memory ID and shmaddr specifies the specific address to use but we should set it to zero and OS will automatically choose the address.

shmdt()	    int shmdt(void *shmaddr);
            When you’re done with the shared memory segment, your program should detach itself from it using shmdt().

shmctl()	shmctl(int shmid,IPC_RMID,NULL);
            When you detach from shared memory, it is not destroyed. So, to destroy shmctl() is used.

*/


struct shmseg {
   int cnt;
   int complete;
   char buf[BUF_SIZE];
};

int main(int argc, char *argv[]) {
    // ftok to generate unique key
    key_t key = ftok("shmfile", 65);


   int shmid;
   struct shmseg *shmp;

   // signa ture: int shmget(key_t key,size_t size, int shmflg);
   shmid = shmget(SHM_KEY, sizeof(struct shmseg), 0644|IPC_CREAT);
   if (shmid == -1) {
      perror("Shared memory");
      return 1;
   }
   
   // Attach to the segment to get a pointer to it.
   shmp = shmat(shmid, NULL, 0);
   if (shmp == (void *) -1) {
      perror("Shared memory attach");
      return 1;
   }
   
   /* Transfer blocks of data from shared memory to stdout*/
   while (shmp->complete != 1) {
      printf("segment contains : \n\"%s\"\n", shmp->buf);
      if (shmp->cnt == -1) {
         perror("read");
         return 1;
      }
      printf("Reading Process: Shared Memory: Read %d bytes\n", shmp->cnt);
      sleep(3);
   }
   printf("Reading Process: Reading Done, Detaching Shared Memory\n");
   if (shmdt(shmp) == -1) {
      perror("shmdt");
      return 1;
   }
   printf("Reading Process: Complete\n");
   return 0;
}