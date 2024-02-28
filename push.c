#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute_command(const char* command)
{
    int result = system(command);

    if (result == -1)
    {
        printf("Error executing command.\n");
    }
}

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    char response[2];
    char commitMessage[301]; // Extra space for null terminator

    // Ask to perform a git pull
    printf("Perform git pull first? (y/n): ");
    fgets(response, sizeof(response), stdin);
    response[strcspn(response, "\n")] =   0; // Remove newline character
    clear_input_buffer(); // Clear the input buffer

    if (strcmp(response, "y") ==   0)
    {
        execute_command("git pull");
    }

    // Perform git add *
    execute_command("git add *");

    // Ask what changes have been made
    printf("What changes have you made?");
    fgets(commitMessage, sizeof(commitMessage), stdin);
    commitMessage[strcspn(commitMessage, "\n")] =   0; // Remove newline character
    clear_input_buffer(); // Clear the input buffer

    // Perform git commit
    char command[400];
    snprintf(command, sizeof(command), "git commit -m \"%s\"", commitMessage);
    execute_command(command);

    // Ask if user is ready to push
    printf("Are you ready to push? (y/n): ");
    fgets(response, sizeof(response), stdin);
    response[strcspn(response, "\n")] =   0; // Remove newline character
    clear_input_buffer(); // Clear the input buffer

    if (strcmp(response, "y") ==   0)
    {
        execute_command("git push");
    }

    return   0;
}

