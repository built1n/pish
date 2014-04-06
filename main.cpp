#include <unistd.h>
#include <led.h>
#include <morse.h>
#include <iostream> // let the user use this with a screen, too
#include <parse.h>
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
      cerr << "PiSH will work fine, but the LEDs can not be used." << endl;
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

