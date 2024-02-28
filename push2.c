#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute_command(const char* command)
{
    int result = system(command);

    if (result == -1)
    {
        printf("Error executing command.\n");
        exit(EXIT_FAILURE); // Exit the program if there's an error executing the command
    }
    else if (WIFEXITED(result) && WEXITSTATUS(result) != 0)
    {
        printf("Command exited with status %d. Exiting program.\n", WEXITSTATUS(result));
        exit(EXIT_FAILURE); // Exit the program if the command exited with a non-zero status
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

    // Automatically stash changes
    execute_command("git stash");
    printf("Local changes stashed successfully.\n");

    // Ask if user is ready to pull remote changes
    printf("Ready to pull remote changes? (y/n): ");
    fgets(response, sizeof(response), stdin);
    response[strcspn(response, "\n")] = 0; // Remove newline character
    clear_input_buffer(); // Clear the input buffer

    if (strcmp(response, "y") == 0)
    {
        execute_command("git pull");
        execute_command("git stash apply"); // Exit if a merge conflict occurs
        printf("Stash merged successfully.\n");

        // Perform git add *
        execute_command("git add *");

        // Ask what changes have been made
        printf("What changes have you made?");
        fgets(commitMessage, sizeof(commitMessage), stdin);
        commitMessage[strcspn(commitMessage, "\n")] = 0; // Remove newline character
        clear_input_buffer(); // Clear the input buffer

        // Perform git commit
        char command[400];
        snprintf(command, sizeof(command), "git commit -m \"%s\"", commitMessage);
        execute_command(command); // Exit if a merge conflict occurs

        // Ask if user is ready to push changes
        printf("Are you ready to push changes? (y/n): ");
        fgets(response, sizeof(response), stdin);
        response[strcspn(response, "\n")] = 0; // Remove newline character
        clear_input_buffer(); // Clear the input buffer

        if (strcmp(response, "y") == 0)
        {
            execute_command("git push");
        }

        // Ask if user is done with stashed changes and would like to clear the stash list
        printf("Done with stashed changes? Clear the stash list? (y/n): ");
        fgets(response, sizeof(response), stdin);
        response[strcspn(response, "\n")] = 0; // Remove newline character
        clear_input_buffer(); // Clear the input buffer

        if (strcmp(response, "y") == 0)
        {
            execute_command("git stash clear");
            printf("Stash list cleared.\n");
        }
    }

    return 0;
}

