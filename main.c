#include "servpipe.h"

int main()
{
  init_chat();
  if (!fork())
    {
      chat("jalcim", "test 1");
      chat("jalcim", "test 2");
      chat("joe", "tesst 1");
      chat("jalcim", "test 3");
      chat("joe", "tesst 2");
      chat("jalcim", "test 4");
      chat("minot", "tesst 1");
      chat("minot", "tesst 2");
      chat("minot", "tesst 3");
      chat("minas", "tesst 1");
      chat("minot", "tesst 4");
      chat("minot", "tesst 5");
      chat("minot", "tesst 6");
      chat("minot", "tesst 7");
      chat("minas", "tesst 2");
      chat("minas", "tesst 3");
      chat("minas", "tesst 4");
      chat("minas", "tesst 5");
      chat("minas", "tesst 6");
      chat("minas", "tesst 7");
      chat("minas", "tesst 8");
      chat("minas", "tesst 9");
      chat("minas", "tesst 10");
      chat("minas", "tesst 11");
      chat("minas", "tesst 12");
      exit(0);
    }
  sleep(1);
  start_chat();
  printf("ok\n");
  //  recup_chat((t_conv *)-1);
  return (0);
}
