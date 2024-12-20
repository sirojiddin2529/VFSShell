#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    char name[128];
    int is_file;
    int created_at;
    int updated_at;
    struct Node *parent;
    struct Node *next;
    struct Node *child;
} Node;

Node *root = NULL;
Node *current = NULL;

// utils
void init();
void prompt();
Node *create_node(char *name, int is_file);
void insert_node(Node *node);

// commands
void mkdir(char *name);
void touch(char *name);
void ls();

int main() {

    init();

    char command[64];
    char arg[128];

    while (1) {
        prompt();
        scanf("%s", command);

        if (strcmp(command, "mkdir") == 0) {
            scanf("%s", arg);
            mkdir(arg);
        } else if (strcmp(command, "touch") == 0) {
            scanf("%s", arg);
            touch(arg);
        } else if (strcmp(command, "ls") == 0) {
            ls();
        } else {
            printf("vfsshell: command not found: %s\n", command);
        }
    }

    return 0;
}

void init() {
    root = malloc(sizeof(Node));

    strcpy(root->name, "root");
    root->is_file    = 0;
    root->created_at = time(NULL);
    root->updated_at = time(NULL);
    root->parent     = NULL;
    root->next       = NULL;
    root->child      = NULL;

    current = root;
}

void prompt() {
    printf("➜ %s ", current->name);
}

Node *create_node(char *name, int is_file) {
    Node *node = malloc(sizeof(Node));
    
    strcpy(node->name, name);
    node->is_file    = is_file;
    node->created_at = time(NULL);
    node->updated_at = time(NULL);
    node->parent     = current;
    node->next       = NULL;
    node->child      = NULL;

    return node;
}

void insert_node(Node *node) {
    if (current->child == NULL) {
        current->child = node;
    } else {
        Node *temp = current->child;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

void mkdir(char *name) {
    Node *node = create_node(name, 0);
    insert_node(node);
}

void touch(char *name) {
    Node *node = create_node(name, 1);
    insert_node(node);
}

void print_node(Node *node) {
    if (node->is_file) {
        printf("%s\n", node->name);
    } else {
        printf("%s/\n", node->name);
    }
}

void ls() {
    Node *temp = current->child;

    while (temp != NULL) {
        print_node(temp);
        temp = temp->next;
    }
}

