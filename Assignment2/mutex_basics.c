#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int balance = 0;
int read_balance();
void write_balance(int new_balance);

void *deposit(void *amount);

pthread_mutex_t mutex;

int main()
{
    int before = read_balance();
    printf("Before: %d\n", before);

    pthread_t thread1;
    pthread_t thread2;

    pthread_mutex_init(&mutex, NULL);

    int deposit1 = 300;
    int deposit2 = 200;

    pthread_create(&thread1, NULL, deposit, (void *) &deposit1);
    pthread_create(&thread2, NULL, deposit, (void *) &deposit2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex);

    int after = read_balance();
    printf("After: %d\n", after);

    return 0;
}



void *deposit(void *amount)
{
    //  Create Lock
    pthread_mutex_lock(&mutex);

    int account_balance = read_balance();

    account_balance += *((int *) amount);

    write_balance(account_balance);

    //  Release Lock
    pthread_mutex_unlock(&mutex);

    return NULL;
}
int read_balance()
{
  usleep(250000);
  return balance;
}
void write_balance(int new_balance)
{
  usleep(250000);
  balance = new_balance;
}