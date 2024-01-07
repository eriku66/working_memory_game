#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10  // Maximum memory capacity

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Argument is missing. \n Usage: memory_game <number of previous numbers> <n number of iterations> \n");
        return 1;
    }

    int memory_steps = atoi(argv[1]);
    int repeat_times = atoi(argv[2]);
    int numbers[MAX] = {0};  // Array to store numbers
    int current_number, user_input;
    srand(time(0));  // Initialize random number

    if (memory_steps >= MAX || memory_steps <= 0) {
        printf("Invalid number, must be in the range of 1 to %d.\n", MAX - 1);
        return 1;
    }

    printf("Enter the number before %d \n", memory_steps);
    system("sleep 1");
    system("clear");

    for (int i = 0; i < repeat_times + memory_steps; i++) {
        if (i < repeat_times) {
            current_number = rand() % 10;  // Generate a random number in the range of 0 to 9
            printf("%d\n", current_number);
            system("sleep 0.5");
            system("clear");
        }

        if (i >= memory_steps) {
            scanf("%d", &user_input);

            if (user_input != numbers[(i - memory_steps) % MAX]) {
                printf("Game over\n");
                break;
            }

            system("clear");
        }

        numbers[i % MAX] = current_number;
    }

    return 0;
}
