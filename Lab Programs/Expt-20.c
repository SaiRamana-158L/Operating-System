#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_READERS 3
#define NUM_WRITERS 2

sem_t mutex, writeBlock;
int data = 0, readersCount = 0;

void *reader(void *arg) {
    int reader_id = *(int *)arg;
    for (int i = 0; i < 5; i++) { // Each reader reads 5 times
        sem_wait(&mutex);
        readersCount++;
        if (readersCount == 1) {
            sem_wait(&writeBlock); // First reader locks write
        }
        sem_post(&mutex);

        // Reading operation
        printf("Reader %d reads data: %d\n", reader_id, data);
        usleep(500000); // Simulate read delay

        sem_wait(&mutex);
        readersCount--;
        if (readersCount == 0) {
            sem_post(&writeBlock); // Last reader unlocks write
        }
        sem_post(&mutex);
    }
    return NULL;
}

void *writer(void *arg) {
    int writer_id = *(int *)arg;
    for (int i = 0; i < 5; i++) { // Each writer writes 5 times
        sem_wait(&writeBlock);

        // Writing operation
        data++;
        printf("Writer %d writes data: %d\n", writer_id, data);
        usleep(1000000); // Simulate write delay

        sem_post(&writeBlock);
    }
    return NULL;
}

int main() {
    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
    int reader_ids[NUM_READERS], writer_ids[NUM_WRITERS];

    sem_init(&mutex, 0, 1);
    sem_init(&writeBlock, 0, 1);

    // Creating Reader Threads
    for (int i = 0; i < NUM_READERS; i++) {
        reader_ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }

    // Creating Writer Threads
    for (int i = 0; i < NUM_WRITERS; i++) {
        writer_ids[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }

    // Waiting for all reader threads to finish
    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }

    // Waiting for all writer threads to finish
    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&writeBlock);

    return 0;
}
