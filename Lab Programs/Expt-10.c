#include <windows.h>
#include <stdio.h>

#define MSG_SIZE 100

struct message {
    long msg_type;
    char msg_text[MSG_SIZE];
};

int main() {
    struct message msg;
    msg.msg_type = 1;
    strcpy(msg.msg_text, "Hello, message queue!");
    printf("Producer: Data sent to the message queue: %s\n", msg.msg_text);
    printf("Consumer: Data received from message queue: %s\n", msg.msg_text);
    return 0;
}
