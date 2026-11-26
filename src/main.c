#include "../include/file_ops.h"
#include <stdio.h>
#include <string.h>
#include "../include/logger.h"


int main(){
    char log_buf[256];
    char input[256];
    char *command;
    char *param;
    char *content;
    char *keyword;

    log_message(LOG_INFO, "Program started");

    while(1){
        printf("file-manager> ");  
        
        if(fgets(input, sizeof(input), stdin) == NULL){ // Receiving input from the user
            log_message(LOG_INFO, "Input terminated");
                break;
        }

        input[strcspn(input,"\n")] = 0;         // Removing \n using by strcspn

        command = strtok(input," ");            // Separating commands and parameters 
        param = strtok(NULL," ");               

        if(command == NULL){
            continue;
        }

        // Quits the program
        if(strcmp(command, "exit") == 0){
            log_message(LOG_INFO,"Program terminated");
            break;
        }

        // Creates a file
        if(strcmp(command, "create") ==0){
            if(param != NULL){
            error_codes_t result = create_file(param);
                if(result ==FS_SUCCESS){
                    printf("File created successfully\n");
                    snprintf(log_buf,sizeof(log_buf), "File created successfully: %s", param);
                    log_message(LOG_INFO,log_buf);
                }else{
                    printf("Failed to create file\n");
                    snprintf(log_buf, sizeof(log_buf), "Failed to create file: %s", param);
                    log_message(LOG_ERROR, log_buf);
                }
            }else {
                printf("error: NO filename specified!\n");
                log_message(LOG_ERROR, "No filename specified");
            }
        } 

        // Deletes a file
        if(strcmp(command, "delete") ==0){
            if(param != NULL){
                error_codes_t result =delete_file(param);
                   if(result ==FS_SUCCESS){
                    printf("File deleted successfully\n");
                    snprintf(log_buf,sizeof(log_buf),"File deleted successfully: %s", param);
                    log_message(LOG_INFO,log_buf);
                }else{
                    printf("Failed to delete file\n");
                    snprintf(log_buf,sizeof(log_buf),"Failed to delete file: %s", param);
                    log_message(LOG_ERROR, log_buf);
                }  
            } else {
                 printf("error: NO filename specified!\n");
                 log_message(LOG_ERROR, "No filename specified");
            }
        }

        // // Lists directory contents
        if(strcmp(command, "list") ==0){
            error_codes_t result = list_files(param != NULL ? param : ".");// list_files(".") lists the contents of the current directory

            if(result == FS_SUCCESS){
                printf("Directory listed successfully\n");
                snprintf(log_buf, sizeof(log_buf), "Directory listed successfully: %s", param != NULL ? param : ".");
                log_message(LOG_INFO,log_buf);
            } else {
                printf("Failed to list directory\n");
                snprintf(log_buf, sizeof(log_buf), "Failed to list directory: %s", param != NULL ? param : "."); 
                log_message(LOG_ERROR,log_buf);     
            }
        }
        
        // Writes text to a file
        if(strcmp(command,"write") == 0){
            content = strtok(NULL,"");              // separating content
            if(param != NULL && content != NULL){
                   error_codes_t result = write_file(param, content);
                   if(result == FS_SUCCESS){
                        printf("Content written successfully\n");
                        snprintf(log_buf,sizeof(log_buf),"Content written successfully: %s", param);
                        log_message(LOG_INFO,log_buf);
                   } else {
                    printf("Failed to write to file\n");
                    snprintf(log_buf,sizeof(log_buf),"Failed to write to file: %s", param);
                    log_message(LOG_ERROR,log_buf);
                   }
            } else {
                    if(param == NULL){
                        printf("error: No filename specified\n");
                        log_message(LOG_ERROR,"No filename specified");
                    } else {
                        printf("error: No content specified\n");
                        log_message(LOG_ERROR,"No content specified");
                    }                    
            }
        }

        // Reads file content
        if(strcmp(command,"read") == 0){
            if(param != NULL){
              error_codes_t result = read_file(param);
                if(result == FS_SUCCESS){
                    printf("File read successfully\n");
                    snprintf(log_buf,sizeof(log_buf),"File read successfully: %s", param);
                    log_message(LOG_INFO,log_buf);               
                } else{
                    printf("Failed to read file\n");
                    snprintf(log_buf,sizeof(log_buf),"Failed to read file: %s", param);
                    log_message(LOG_ERROR,log_buf);
                }        
            } else {
                printf("error: NO filename specified!\n");
                log_message(LOG_ERROR,"No filename specified");
            }
        }
        
        // Searches for a keyword in the specified file
        if(strcmp(command,"search") == 0){
            keyword = strtok(NULL," ");
            if(param != NULL && keyword != NULL){
                error_codes_t result = search_file(param,keyword);
                if(result == FS_SUCCESS){
                    printf("Search completed successfully\n");
                    snprintf(log_buf,sizeof(log_buf),"Search completed successfully: '%s' for keyword '%s'", param , keyword);
                    log_message(LOG_INFO,log_buf);
                } else {
                    printf("Failed to search file\n");
                    snprintf(log_buf,sizeof(log_buf),"Failed to search file: '%s' for keyword '%s'", param, keyword);
                    log_message(LOG_ERROR,log_buf);
                }
            } else {
                if(param == NULL){
                    printf("error: filename missing!\n");
                    log_message(LOG_ERROR,"No filename specified");
                } else {
                    printf("error: keyword missing!\n");
                    log_message(LOG_ERROR,"No keyword specified");
                }
            }
        }
    }
    return 0;
}

