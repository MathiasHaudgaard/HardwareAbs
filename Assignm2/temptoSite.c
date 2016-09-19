#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc,char *argv[]){
  int ledFD = open("/sys/class/leds/devkit8000::led3/brightness", O_RDWR);
  int tempFD = open("/dev/i2c-2", O_RDONLY);
  int htmlFD = open("/www/pages/index.html", O_RDWR);
  char ledBuf[1] = "0";
  char tempBuf[2];
  char tempToSite[600] = "0";
  int dec;
  ioctl(tempFD, 0x0703, 0x48);
  write(ledFD, ledBuf, 1);


  while(1){
    read(tempFD, tempBuf, 2);
    
    if(tempBuf[1] == 128){
      dec = 5;
    } else {
      dec = 0;
    }
    if(tempBuf[0] > 29){
      ledBuf[0] = '1';
      printf("Reactor is melting!\n");
    } else {
      ledBuf[0] = '0';
    }
    sprintf(tempToSite, "<html><body><script>window.setInterval(function(){location.reload();}, 1000);</script><h1>Temperatur: %d,%d grader</h1></body></html>",tempBuf[0], dec);
    lseek(htmlFD,0,0);
    write(htmlFD, tempToSite, 600);
    printf("%d,%d\n", tempBuf[0], dec);
    write(ledFD, ledBuf, 1);
    fflush(stdout);
    sleep(1);
    
  }
  return 0;
}
