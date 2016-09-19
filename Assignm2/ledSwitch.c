#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc,char *argv[]){
  int ledFD = open("/sys/class/leds/devkit8000::led3/brightness", O_RDWR);
  char ledBuf[1] = "0";


  while(1){
    if(ledBuf[0] == '0'){
      ledBuf[0] = '1';
    } else {
      ledBuf[0] = '0';
    }
    write(ledFD, ledBuf, 1);
    sleep(1);
    
  }
  close(ledFD);
  return 0;
}
