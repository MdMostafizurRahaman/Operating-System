// #include <stdio.h>
// #include <pthread.h>
// #include <semaphore.h>
// #include <stdlib.h>

// #define Max_Items  10

// #define Buffer_Size  10

// #define Max_Producer 10
// #define Max_Consumer 10

// sem_t empty, full;
// pthread_mutex_t mutex;

// int input_index = 0; // index where producer will produce
// int output_index = 0; // index from where consumer will consume
// int buffer[Buffer_Size];

// void *producer_pro(void *pno){
//     int item;

//     for(int i = 0; i < Max_Items; i++) {
//         item = rand(); // Produce an random item
//         sem_wait(&empty);
//         pthread_mutex_lock(&mutex);
//         buffer[input_index] = item;
//         printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[input_index],input_index);
//         input_index = (input_index+1)%Buffer_Size;
//         pthread_mutex_unlock(&mutex);
//         sem_post(&full);
//     }
// }

// void *consumer_con(void *cno)
// {
//     int item;

//     for(int i = 0; i < Max_Items; i++) {
//         sem_wait(&full);
//         pthread_mutex_lock(&mutex);
//         item = buffer[output_index];
//         printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),item, output_index);
//         output_index = (output_index+1)%Buffer_Size;
//         pthread_mutex_unlock(&mutex);
//         sem_post(&empty);
//     }
// }

// int main(void){
//     pthread_t producer[Max_Producer], consumer[Max_Consumer];

//     pthread_mutex_init(&mutex, NULL);
//     sem_init(&empty, 0, Buffer_Size);
//     sem_init(&full, 0, 0);

//     // used for numbering the producer and consumer
//     int num[Max_Producer];
//     for(int i=1; i<=Max_Producer; i++) num[i] = i+1;

//     // producer and consumer thread creation
//     for(int i=0; i<Max_Producer; i++)
//         pthread_create(&producer[i], NULL, (void *)producer_pro, (void *)(&num[i]));

//     for(int i=0; i<Max_Consumer; i++)
//         pthread_create(&consumer[i], NULL, (void *)consumer_con, (void *)(&num[i]));

//     // join the threads
//     for(int i = 0; i < Max_Producer; i++) {
//         pthread_join(producer[i], NULL);
//     }
//     for(int i = 0; i < Max_Consumer; i++) {
//         pthread_join(consumer[i], NULL);
//     }

//     pthread_mutex_destroy(&mutex);
//     sem_destroy(&empty);
//     sem_destroy(&full);

//     return 0;

// }

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <stdbool.h>
#include <unistd.h>

sem_t barberReady, accessWRSeats, custReady;
int numOfFreeWRSeats = 5;

void *Barber(void *arg)
{
    while (true)
    {
        printf("Barber checking if any customer available.\n");
        sem_wait(&custReady);
        printf("Customer is available\n");

        printf("Barber is trying to free waiting a room seat.\n");
        sem_wait(&accessWRSeats);
        numOfFreeWRSeats++;
        printf("Barber freed a waiting room seat.\n");
        printf("Barber is cutting hair.\n");
        sleep(1);
        sem_post(&barberReady);
        printf("Barber released the waiting room lock\n");
        sem_post(&accessWRSeats);
    }
}

void *Customer(void *arg)
{
    while (true)
    {
        printf("Customer is trying to access the waiting room chair.\n");
        sem_wait(&accessWRSeats);
        printf("Customer accessed the waiting room chair.\n");
        printf("Customer checking if any free seat available in the waiting room.\n");
        if (numOfFreeWRSeats > 0)
        {
            printf("Customer found free a seat.\n");
            numOfFreeWRSeats--;
            printf("A customer is ready to cut.\n");
            sem_post(&custReady);
            printf("Customer released the waiting room lock\n");
            sleep(1);
            sem_post(&accessWRSeats);
            printf("Customer checking if the barber is free.\n");
            sem_wait(&barberReady);
            printf("Customer found a barber available.\n");
        }
        else
        {
            printf("Customer leaves without a haircut.\n");
            sem_post(&accessWRSeats);
        }
    }
}

int main()
{
    pthread_t thread1, thread2;

    sem_init(&barberReady, 0, 0);
    sem_init(&accessWRSeats, 0, 1);
    sem_init(&custReady, 0, 0);

    pthread_create(&thread1, NULL, Barber, NULL);
    pthread_create(&thread2, NULL, Customer, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}