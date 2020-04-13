#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
  
sem_t mutex; 
sem_t coronaPatient;
sem_t potentialCPatient;
sem_t fluPatient;

void Rtests()   //recovery tests for patients
{

   printf("The patient has recovered after two tests\n"); 

}
void Ctests()
{

   printf("The patient has been tested positive for virus\n"); 

}

void ftests()
{


   printf("The patient is suffering from flu\n"); 

}

void* thread(void* arg) 
{ 
    //wait 
    sem_wait(&mutex); 
    printf("\nEntering time n"); 
    if (Ctests()==true)
    {
        sem_init(&coronaPatient, 1);
        sem_init(&potentialCPatient, 1);
    }
    if (Ctests()==true)
    {
        sem_init(&fluPatient, 1);
        sem_init(&potentialCPatient, 1);
    }
    if (Rtests()==true)
    {
        sem_init(&coronaPatient, 0);
        sem_init(&potentialCPatient, 0);
    }
    sleep(4); 
      
    //signal 
    printf("\nExiting time\n"); 
    sem_post(&mutex); 
} 
  
  
int main() 
{ 
    sem_init(&mutex, 0, 1); 
    sem_init(&coronaPatient, 0, 1);
    sem_init(&potentialCPatient, 0, 1);
    sem_init(&fluPatient, 0, 1);
    
    pthread_t t1,t2; 
    pthread_create(&t1,NULL,thread,NULL); 
    sleep(2); 
    pthread_create(&t2,NULL,thread,NULL); 
    pthread_join(t1,NULL); 
    pthread_join(t2,NULL); 
    sem_destroy(&mutex); 
    return 0; 
} 