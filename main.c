#include "servpipe.h"

int main()
{
  init_chat();
  if (!fork())
    {
      chat("jalcim", "test 1");
      chat("jalcim", "te 2");
      chat("jalcim", "tet 3");
      chat("jalcim", "test 4");
      chat("jalcim", "test 5");
      exit(0);
    }
  sleep(1);
  start_chat();
  recup_chat((t_conv *)-1);
}
