#include <fstream>
#include <leds.h>
using namespace std;
bool isLightOn()
{
  ifstream ifs("/sys/class/leds/led0/brightness");
  int brightness;
  ifs >> brightness;
  if(brightness==0)
    return false;
  else
    return true;
}
void setLight(bool on)
{
  ofstream ofs("/sys/class/leds/led0/brightness");
  int val;
  if(on)
    val=255;
  else
    val=0;
  ofs << val << flush;
}
