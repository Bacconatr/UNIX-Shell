#include <stdio.h>
#include "tokens.h"
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

//Takes STDIN and turns it into tokesn
char* read_line();

//Takes tokens and executes the commands 
void execute(char** tokens);
#include<stdio.h>
#include "tokens.h"
#include <assert.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc, char **argv) {

  // TODO: Implement your shell's main
  int exec;
  int stop_when;
 
  printf("Welcome to mini-shell.\n");

  while(1) {
   printf("shell $ ");
   char* commandLine = read_line(); 
   char* splitString = strtok(commandLine,";");
   while(splitString !=NULL) {
     
      char **tokens = get_tokens(splitString);
     execute(tokens); 
     splitString = strtok(NULL,";");
   }


  

  }   
  return 0;

 

typedef enum {T,F} boolean;


boolean b = T;

printf("Welcome to my mini shell.\n");
while(b == T) {
printf("shell $ ");
char input[256];

  fgets(input, 256, stdin);


  char **tokens = get_tokens(input);

  assert(tokens != NULL);

  char **current = tokens;
//  while (*current != NULL) {
  //  printf("%s\n", *current);
   // ++current;
 // }


int curr;
curr = 0;
char* myargv[16];
int fork1;
while (*current != NULL) {
 
  myargv[curr] = *current;
    ++current;
    ++curr;
  }



fork1 = fork();
if(fork1 == 0) {
execve(myargv[0],myargv,NULL);
exit(1);
}
else {
wait(NULL);

}
  free_tokens(tokens);

}


return 0;
}


//--------------------------Split the commands into lines ---------------------------//
char* read_line() {

char buf[256];
char *b = buf;
size_t size = 256;
  getline(&b,&size,stdin);
  return b;



}


//-----------------------Executing the commands---------------------------
void execute(char** tokens) {


int program;
char *envp[] = { (char*) "PATH=/bin/","HOME=/",0};

program= fork();


if(program == 0) {
execvpe(tokens[0],tokens,envp);
exit(1);
}
else {
wait(NULL);
}




}
