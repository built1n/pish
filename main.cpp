#include <unistd.h>
#include <led.h>
#include <morse.h>
#include <iostream> // let the user use this with a screen, too
using namespace std;
void parse_args(int argc, char* argv[])
{
  // nothing for now
}
int main(int argc, char* argv[])
{
  if(geteuid()!=0) // must be root to control LEDS!
    {
      cerr << "Need to be root to control LEDs!"<< endl;
      cerr << "Current user ID: " << geteuid() << endl;
      return 1;
    }
  parse_args(argc, argv);
  cout << "PiSH initializied." << endl;
  dash();
  usleep(250000);
  dash();
  usleep(250000);
  string cmd;
  while(cmd!="exit")
    {
      dot();
      cout << "PiSH> ";
      getline(cin, cmd);
      dash();
      usleep(250000);
    }
}

