#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#define SIZE 500
#include <time.h>
#include <sys/socket.h> 
#include <netinet/in.h>
#include <netinet/tcp.h> 
int sockfd, new_sock;
char buf[256];
socklen_t len;
int counter=1;
int print_mean=0;

void write_file(int sockfd){
double t [5] ={0,0,0,0,0};
int i=0;
  int n;
  FILE *fp;
  char *filename = "recv.txt";
  char buffer[SIZE];
 
clock_t start, end;
     double cpu_time_used;
     start = clock();
  fp = fopen(filename, "w");
  while (1) {
    n = recv(sockfd, buffer, SIZE, 0);
         printf("got: %d bit\n",n);
    if (n == 31){
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
 printf("cpu_time_used for this file: %f\n",cpu_time_used);
 t[i]=cpu_time_used;
 i++;
 start = clock();
      printf("file number : %d\n",i);
    }
    if (i==5){
      if(print_mean<=1){
      printf("cpu_time_used mean: %f\n",(t[1]+t[2]+t[3]+t[4]+t[0])/5);
      print_mean++;
      }
      if (counter==1){
      
////now  change cc algorithm
      strcpy(buf, "reno"); 
len = strlen(buf);
if (setsockopt(sockfd, IPPROTO_TCP, TCP_CONGESTION, buf, len) != 0) {
perror("setsockopt"); 
return ;
}
 
printf("New: %s\n", buf);
counter++; 
      write_file(sockfd);
      }
      if(n==0){
      break;
      return;}
      }
    //fprintf(fp, "%s", buffer);
    bzero(buffer, SIZE);
  }
  return;
}

int main(){
  char *ip = "127.0.0.1";
  int port = 8080;
  int e;

  
  struct sockaddr_in server_addr, new_addr;
  socklen_t addr_size;
  char buffer[SIZE];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
    perror("[-]Error in socket");
    exit(1);
  }
  printf("[+]Server socket created successfully.\n");
///////////////////

len = sizeof(buf); 
if (getsockopt(sockfd, IPPROTO_TCP, TCP_CONGESTION, buf, &len) != 0) { 
perror("getsockopt");
return -1;
} 

printf("Current: %s\n", buf); 

//////////////////
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = port;
  server_addr.sin_addr.s_addr = inet_addr(ip);

  e = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
  if(e < 0) {
    perror("[-]Error in bind");
    exit(1);
  }
  printf("[+]Binding successfull.\n");

  if(listen(sockfd, 10) == 0){
 printf("[+]Listening....\n");
 }else{
 perror("[-]Error in listening");
    exit(1);
 }

  addr_size = sizeof(new_addr);
  new_sock = accept(sockfd, (struct sockaddr*)&new_addr, &addr_size);
  
  write_file(new_sock);
  printf("[+]Data written in the file successfully.\n");

  return 0;
}
