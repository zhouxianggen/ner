
#include <sys/time.h>
#include "utils.h"
#include "number.h"
using namespace ucltp;

int main(int argc, char** argv)
{
  struct timeval sTime, eTime;
  gettimeofday(&sTime, NULL);

  Number num;
  int r = num.load_dict("data/number/dict");
  if (r != 0) {
    printf("load dict failed with %d.\n", r);
    return -1;
  }
  r = num.load_regexp("data/number/regexp");
  if (r != 0) {
    printf("load regexp failed with %d.\n", r);
    return -1;
  }

  vector<char_t> chars;
  read_utf8_text(argv[1], chars);
  show(chars);
  num.seg(chars);
  show(chars);

  gettimeofday(&eTime, NULL);
  long exeTime = (eTime.tv_sec-sTime.tv_sec)*1000000+(eTime.tv_usec-sTime.tv_usec);
  printf("exeTime = %d us\n", exeTime);
  
  return 0;
}
