/*
 * =====================================================================================
 *       Filename:  wshell.h
 *    Description:  
 *        Version:  1.0
 *        Created:  2013年10月16日 20时15分26秒
 *         Author:  wuyue (wy), vvuyve@gmail.com
 *        Company:  UESTC
 * =====================================================================================
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> 
#include <errno.h>
#include <pwd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h> 
#define MAX_PROMPT 1024
#define MAXLINE 4096 //the length of all args is ARG_MAX
#define MAXARG 20

struct parse_info;
struct passwd *pwd;
char *buffer;

void type_prompt(char*);
int read_command(char **,char **,char*);
int builtin_command(char *,char **);
int parsing(char **,int,struct parse_info *);
void proc(void);



#ifndef STRUCT_PARSE_INFO
#define STRUCT_PARSE_INFO
#define BACKGROUND 		1
#define IN_REDIRECT 	2
#define OUT_REDIRECT 	4
#define IS_PIPED 		8
struct parse_info 
{
    int flag;
    char* in_file;
    char* out_file;
    char* command2;
	char** parameters2;
};
#endif
