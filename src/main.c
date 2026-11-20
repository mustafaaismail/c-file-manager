#include "../include/file_ops.h"
#include <stdio.h>
#include <string.h>

int main(){
    char input[256];
    char *command;
    char *param;
    char *content;
    char *keyword;
    while(1){
        printf("file-manager> ");
        fgets(input,sizeof(input),stdin);        // Receiving input from the user

        input[strcspn(input,"\n")] = 0;         // Removing \n using by strcspn

        command = strtok(input," ");            // Separating commands and parameters 
        param = strtok(NULL," ");               

        if(command == NULL){
            continue;
        }

        // Quits the program
        if(strcmp(command, "exit") == 0){
            break;
        }

        // Creates a file
        if(strcmp(command, "create") ==0){
            if(param != NULL){
                create_file(param);
            } else {
                printf("error: NO filename specified!\n");
            }
        } 

        // Deletes a file
        if(strcmp(command, "delete") ==0){
            if(param != NULL){
                delete_file(param);
            } else {
                 printf("error: NO filename specified!\n");
            }
        }

        // Lists the contents of the folder
        if(strcmp(command, "list") ==0){
           if(param != NULL){ 
            list_files(param);
            } else {
                list_files(".");   // refers to the existing folder
            }
        }
        
        // Writes text to a file
        if(strcmp(command,"write") == 0){
            content = strtok(NULL,"");              // separating content
            if(param != NULL && content != NULL){
                    write_file(param, content);
            } else {
                    printf("error: filename or content missing!\n");
            }

        }

        // Reads file content
        if(strcmp(command,"read") == 0){
            if(param != NULL){
               read_file(param); 
            } else {
                printf("error: NO filename specified!\n");
            }
        }
        
        // Search keyword in the given file
        if(strcmp(command,"search") == 0){
            keyword = strtok(NULL," ");
            if(param != NULL && keyword != NULL){
                search_file(param,keyword);
            } else {
                printf("error: filename or keyword missing!\n");
            }
        }
    }

}

