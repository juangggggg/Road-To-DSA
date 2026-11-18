
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Global variable to remember the user's name
char user_name[50] = "";

// Convert text to lowercase
void toLowerCase(char text[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = tolower((unsigned char)text[i]);
    }
}

// Check if a word exists as a separate word
int containsWord(const char text[], const char word[]) {
    const char *p = text;
    size_t len = strlen(word);

    while ((p = strstr(p, word)) != NULL) {

        int left = (p == text ||
                    !isalnum((unsigned char)p[-1]));

        int right = (p[len] == '\0' ||
                     !isalnum((unsigned char)p[len]));

        if (left && right) {
            return 1;
        }

        p++;
    }

    return 0;
}

// Display a random response
void randomResponse(const char *responses[], int size) {
    int choice = rand() % size;
    printf("AI: %s\n", responses[choice]);
}

// Main chatbot
int main() {

    char input[256];
    char original[256];

    srand((unsigned int)time(NULL));

    const char *greetings[] = {
        "Hello! How are you?",
        "Hey there! What's up?",
        "Hi! Nice to talk to you.",
        "Hello! What are you doing today?"
    };

    const char *happy[] = {
        "That's great to hear!",
        "I'm glad you're doing well!",
        "Awesome! Keep that positive energy!",
        "That's wonderful!"
    };

    const char *sad[] = {
        "I'm sorry to hear that.",
        "I hope things get better for you.",
        "Do you want to talk about it?"
    };

    const char *unknown[] = {
        "Interesting! Tell me more.",
        "I see. What else?",
        "That's something worth discussing!",
        "Can you explain that a little more?",
        "Hmm, I haven't thought about that before."
    };

    printf("       C SIMPLE AI CHATBOT       \n");

    printf("AI: Hello! I'm your chatbot.\n");
    printf("AI: What's your name?\n\n");

    while (1) {

        printf("YOU: ");

        // Read user input
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        // Remove newline
        input[strcspn(input, "\r\n")] = '\0';

        // Ignore empty input
        if (strlen(input) == 0) {
            continue;
        }

        // Preserve original input
        strcpy(original, input);

        // Convert a copy to lowercase
        toLowerCase(input);

        printf("\n");

        // Exit condition
        if (containsWord(input, "exit") ||
            containsWord(input, "quit")) {

            printf("AI: Goodbye! It was nice talking to you.\n");
            break;
        }

        // Remember user's name
        char *namePosition = strstr(input, "my name is ");

        if (namePosition != NULL) {

            size_t offset = (size_t)(namePosition - input)
                            + strlen("my name is ");

            snprintf(user_name, sizeof(user_name),
                     "%s", original + offset);

            // Remove trailing spaces and punctuation
            size_t len = strlen(user_name);

            while (len > 0 &&
                   (isspace((unsigned char)user_name[len - 1]) ||
                    ispunct((unsigned char)user_name[len - 1]))) {
                user_name[--len] = '\0';
            }

            printf("AI: Nice to meet you, %s!\n", user_name);
        }

        // Ask for user's name
        else if (strstr(input, "what is my name") ||
                 strstr(input, "who am i")) {

            if (strlen(user_name) > 0) {
                printf("AI: Your name is %s!\n", user_name);
            } else {
                printf("AI: I don't know your name yet!\n");
            }
        }

        // Greetings
        else if (containsWord(input, "hello") ||
                 containsWord(input, "hi") ||
                 containsWord(input, "hey")) {

            randomResponse(greetings, 4);
        }

        // Ask chatbot's name
        else if (strstr(input, "your name") ||
                 strstr(input, "who are you")) {

            printf("AI: I'm a simple chatbot written in C!\n");
        }

        // Ask how chatbot is doing
        else if (strstr(input, "how are you")) {

            printf("AI: I'm doing great! Thanks for asking.\n");
        }

        // User is happy
        else if (strstr(input, "happy") ||
                 strstr(input, "good") ||
                 strstr(input, "great")) {

            randomResponse(happy, 4);
        }

        // User is sad
        else if (strstr(input, "sad") ||
                 strstr(input, "bad") ||
                 strstr(input, "tired")) {

            randomResponse(sad, 3);
        }

        // Ask what the chatbot can do
        else if (strstr(input, "help") ||
                 strstr(input, "what can you do")) {

            printf("AI: I can chat, recognize keywords, ");
            printf("and remember your name during this session.\n");
        }

        // Thank you
        else if (containsWord(input, "thanks") ||
                 containsWord(input, "thank")) {

            printf("AI: You're welcome!\n");
        }

        // Default response
        else {

            randomResponse(unknown, 5);
        }

        printf("\n");
    }

    return 0;
}
