#include <stdio.h>

// Set to 2^n for faster modulo operation
#define QUEUE_SIZE 1024
#define QUEUE_MASK 1023
#define MAX_BALLOON_SIZE 1000

int queue[QUEUE_SIZE];
int head = 0;
int tail = 0;
int balloon_papers[MAX_BALLOON_SIZE];

int main(void)
{
    int num_balloons;
    scanf("%d", &num_balloons);

    // Initialize 
    for (int i = 0; i < num_balloons; i++)
    {
        queue[i] = i + 1;
    }
    tail = num_balloons;

    // Baloon papers have next movement info
    for (int i = 0; i < num_balloons; i++)
    {
        scanf("%d", &balloon_papers[i]);
    }

    while (1)
    {
        // Pop balloon
        printf("%d ", queue[head]);
        int movement = balloon_papers[queue[head] - 1];
        head = (head + 1) & QUEUE_MASK;
        num_balloons--;

        if (num_balloons == 0)
        {
            break;
        }

        // Positivie: Movement -1 since the head moved by popping 
        // Negative: Converted into positive movement
        movement = (movement > 0) 
                    ? (movement - 1) % num_balloons 
                    : num_balloons + (movement % num_balloons);

        // Rotate right by movement
        while (movement != 0)
        {
            queue[tail] = queue[head];
            head = (head + 1) & QUEUE_MASK;
            tail = (tail + 1) & QUEUE_MASK;
            movement--;
        }
    }
}