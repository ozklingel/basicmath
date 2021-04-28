#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <time.h>
#include <sys/socket.h> 
#include <netinet/in.h>
#include <netinet/tcp.h> 
#define SIZE 1031

void send_file(FILE *fp, int sockfd){
  int n;
  char data[SIZE] = {0};

  while(fgets(data, SIZE, fp) != NULL) {
    if (send(sockfd, data, sizeof(data), 0) == -1) {
      perror("[-]Error in sending file.");
      exit(1);
    }
    bzero(data, SIZE);
  }
}

int main(){
  char *ip = "127.0.0.1";
  int port = 8080;
  int e;

  int sockfd;
  struct sockaddr_in server_addr;
  FILE *fp;
  char *filename = "1gb2.txt";

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
    perror("[-]Error in socket");
    exit(1);
  }
  printf("[+]Server socket created successfully.\n");

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = port;
  server_addr.sin_addr.s_addr = inet_addr(ip);

  e = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
  if(e == -1) {
    perror("[-]Error in socket");
    exit(1);
  }
 printf("[+]Connected to Server.\n");
 char buf[256];
 socklen_t len;
 len = sizeof(buf); 
if (getsockopt(sockfd, IPPROTO_TCP, TCP_CONGESTION, buf, &len) != 0) { 
perror("getsockopt");
return -1;
} 

printf("Current: %s\n", buf); 

for(int i=0;i<5;i++){
  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("[-]Error in reading file.");
    exit(1);
  }

  send_file(fp, sockfd);
  printf("[+]File data sent successfully.\n");
  sleep(2);
}
      strcpy(buf, "reno"); 
len = strlen(buf);
if (setsockopt(sockfd, IPPROTO_TCP, TCP_CONGESTION, buf, len) != 0) {
perror("setsockopt"); 
return 1;
}
 
printf("New: %s\n", buf);
for(int i=0;i<5;i++){
  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("[-]Error in reading file.");
    exit(1);
  }

  send_file(fp, sockfd);
  printf("[+]File data sent successfully.\n");
  sleep(2);
}
  printf("[+]Closing the connection.\n");
  close(sockfd);

  return 0;
}
