bool isLightOn();
void setLight(bool);
#define lightOn() setLight(true)
#define lightOff() setLight(false)
