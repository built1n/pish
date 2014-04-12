#include <cstdlib>
#include <unistd.h>
#include <led.h>
#include <morse.h>
#include <iostream> // let the user use this with a screen, too
#include <parse.h>
#include <csignal>
using namespace std;
void parse_args(int argc, char* argv[])
{
  // nothing for now
}
void prepare_to_exit(int signum)
{
  cerr << "Received signal " << signum << ", exiting." << endl;
  dash();
  usleep(250000);
  dash();
  exit(signum);
}
int main(int argc, char* argv[])
{
  if(geteuid()!=0) // must be root to control LEDS!
    {
      int ret=seteuid(0);
      if(!ret)
	{
	  cerr << "Cannot become root."<< endl;
	  cerr << "LEDs will not be used." << endl;
	}
    }
  for(int i=0;i<_NSIG;++i) // handle any and all signals by exiting
    {
      signal(i, &prepare_to_exit);
    }
  parse_args(argc, argv);
  init_morse();
  dash();
  usleep(250000);
  dash();
  usleep(250000);
  cout << "PiSH initializied." << endl;
  string cmd;
  while(cmd!="exit")
    {
      dot();
      cout << "PiSH> ";
      getline(cin, cmd);
      pish_parse(cmd);
      cin.clear();
      sleep(1);
    }
}

