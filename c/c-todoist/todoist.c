/*
 * C-todoist - A simple command-line todo list application written in C.
 *
 * This program allows users to manage tasks by adding, listing, and marking them as completed.
 * It provides a basic interface to organize and keep track of daily tasks.
 *
 * Features:
 * - Add tasks
 * - List tasks
 * - Mark tasks as completed
 * - Simple and easy-to-use command-line interface
 *
 * Author: Luca "Lucacux" Lombardo
 * Date: 03-02-2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_STR 1000

// STRUCT for Task is defined.
typedef struct {
  char taskString[MAX_STR];
} Task;

// Function prototypes.
void programLogic(Task *taskData);
void briefTutorial(Task *taskData);
void briefTutorialII(Task *taskData);
void briefTutorialIII(Task *taskData);
void menu(Task *taskData);
void addTasks(Task *taskData);
void listTasks(Task *taskData);
void markTasks(Task *taskData);

// Main function.
int main() {
  Task *taskData = (Task*) malloc(sizeof(Task));
  if (taskData != NULL) {
    programLogic(taskData);
    free(taskData);
  } else {
    printf("The program couldn't assign memory for execution in your OS\n");
  }
  return 0;
}

// Verifies if the txt file exists; otherwise, creates it and shows a tutorial.
void programLogic(Task *taskData) {
  FILE *file = fopen("tasks.txt", "r");
  if (file != NULL) {
    fclose(file);
    menu(taskData);
  } else {
    briefTutorial(taskData);
  }
}

void briefTutorial(Task *taskData) {
  printf("Welcome to: C-todoist - A simple command-line todo list application written in C.\n");
  printf("Looks like you're new here. Don't worry, it's easy :)\n");
  printf("Let's create your first task!\n");
  printf("Imagine something you would like to remember.\n");
  sleep(6);
  printf("Now, write it :) (0 words min. 1000 MAX)\n");

  FILE *file = fopen("tasks.txt", "a");
  if (file != NULL) {
    fgets(taskData->taskString, MAX_STR, stdin);
    fprintf(file, "Task (1): %s\n", taskData->taskString);
    fclose(file);
    briefTutorialII(taskData);
  } else {
    printf("Something went wrong, please try later\n");
  }
}

void briefTutorialII(Task *taskData) {
  printf("Let's see what you've written\n");

  FILE *file = fopen("tasks.txt", "r");
  if (file != NULL) {
    while (fgets(taskData->taskString, MAX_STR, file) != NULL) {
      printf("Your first task: %s", taskData->taskString);
    }
    fclose(file);
    briefTutorialIII(taskData);
  } else {
    printf("Something went wrong, please try later\n");
  }
}

void briefTutorialIII(Task *taskData) {
  printf("Now that you're all set, enjoy managing your tasks with C-Todoist! :)\n");
  menu(taskData);
}

void menu(Task *taskData) {
  int option;
  printf("Welcome back to C-Todoist! Your best CLI-based TODO app :)\n");
  printf("Please select an option\n");
  printf("1. Add tasks\n");
  printf("2. List tasks\n");
  printf("3. Mark tasks as completed\n");
  printf("4. Exit program\n");
  scanf("%d", &option);
  getchar(); // Clear input buffer
  switch (option) {
    case 1:
      addTasks(taskData);
      break;
    case 2:
      listTasks(taskData);
      break;
    case 3:
      markTasks(taskData);
      break;
    default:
      printf("Thank you for using C-Todoist! Have a great day and stay organized! ✨\n");
  }
}

void addTasks(Task *taskData) {
  FILE *file = fopen("tasks.txt", "a");
  if (file != NULL) {
    printf("Please write your task (0-1000 words):\n");
    getchar();
    fgets(taskData->taskString, MAX_STR, stdin);
    fprintf(file, "Task: %s", taskData->taskString);
    printf("Success! Your task was written.\n");
    fclose(file);
  } else {
    printf("The program couldn't open the .txt file that stores your tasks.\n");
  }
}

void listTasks(Task *taskData) {
  FILE *file = fopen("tasks.txt", "r");
  if (file != NULL) {
    printf("Total tasks\n---------------\n");
    while (fgets(taskData->taskString, MAX_STR, file) != NULL) {
      printf("%s", taskData->taskString);
    }
    printf("---------------\n");
    fclose(file);
  } else {
    printf("The program couldn't read the .txt file that stores your tasks.\n");
  }
}

void markTasks(Task *taskData) {
  int taskNumber, i = 1;
  printf("Please select the number of the task to mark as 'FINISHED':\n");
  scanf("%d", &taskNumber);
  getchar();

  FILE *file = fopen("tasks.txt", "r");
  FILE *tempFile = fopen("temp.txt", "w");

  if (file != NULL && tempFile != NULL) {
    while (fgets(taskData->taskString, MAX_STR, file) != NULL) {
      if (i == taskNumber) {
        strtok(taskData->taskString, "\n"); // Remove newline
        strcat(taskData->taskString, " FINISHED\n");
      }
      fprintf(tempFile, "%s", taskData->taskString);
      i++;
    }
    fclose(file);
    fclose(tempFile);
    remove("tasks.txt");
    rename("temp.txt", "tasks.txt");
    printf("Task marked as completed.\n");
  } else {
    printf("The program couldn't open the file for marking tasks.\n");
  }
}
