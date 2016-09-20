/**************************************************************/
// gcc -pthread -o test_threads test_threads.c

// Simple thread create and exit test

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

/***************************************************************/
void *work(void *i)
{
  printf(" Hello World! from child thread %lu\n",
	 pthread_self());

  pthread_exit(NULL);
}

/****************************************************************/
int main(int argc, char *argv[])
{
  int arg,i,j,k,m;   	              /* Local variables. */
  pthread_t* id;
//  pthread_t id[NUM_THREADS];
  id = (pthread_t*)malloc(sizeof(pthread_t));

  for (i = 0; i < NUM_THREADS; ++i) {
    if (pthread_create(id, NULL, work, NULL)) {
    //  if (pthread_create(&id[i], NULL,work, NULL)){
	printf("ERROR creating the thread\n");
      exit(19);
    }
  }

  printf("\n main() after creating the thread.  My id is %lu\n",
	 pthread_self());

  sleep(3);
  return(0);

}/* end main */
