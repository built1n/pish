#include <led.h>
#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <cctype>
#include <unistd.h>
#include <cstring>
using namespace std;
void dot()
{
  cout << "." << flush;
  setLight(true);
  usleep(250000);
  setLight(false);
}
void dash()
{
  cout << "-" << flush;
  setLight(true);
  usleep(750000);
  setLight(false);
}
static map<string, string> table;
void transmit(const string& str)
{
  cout << "Transmitting message in Morse code via ACT LED..." << endl;
  for(unsigned long long i=0;i<str.length();++i)
    {
      char ch=str[i];
      string tmp;
      tmp=toupper(ch);
      string morse=table[tmp];
      if(morse!="")
	cout << ch << ": " << flush;
      for(unsigned int j=0;j<morse.length();++j)
	{
	  char morseCh=morse[j];
	  if(morseCh=='.')
	    dot();
	  else if(morseCh=='-')
	    dash(); 
	  usleep(200000);
	}
      if(morse!="")
	cout << " " << flush;
      usleep(250000); // between chars
      if(isspace(ch))
	{
	  cout << " " << flush;
	  usleep(500000); // extra for spaces
	}
    }
}

void init_morse()
{
  table["A"]=".-";
  table["B"]="-...";
  table["C"]="-.-.";
  table["D"]="-..";
  table["E"]=".";
  table["F"]="..-.";
  table["G"]="--.";
  table["H"]="....";
  table["I"]="..";
  table["J"]=".---";
  table["K"]="-.-";
  table["L"]=".-..";
  table["M"]="--";
  table["N"]="-.";
  table["O"]="---";
  table["P"]=".--.";
  table["Q"]="--.-";
  table["R"]=".-.";
  table["S"]="...";
  table["T"]="-";
  table["U"]="..-";
  table["V"]="...-";
  table["W"]=".--";
  table["X"]="-..-";
  table["Y"]="-.--";
  table["Z"]="--..";
  table["0"]="-----";
  table["1"]=".----";
  table["2"]="..---";
  table["3"]="...--";
  table["4"]="....-";
  table["5"]=".....";
  table["6"]="-....";
  table["7"]="--...";
  table["8"]="---..";
  table["9"]="----.";
  table["."]=".-.-.-";
  table[","]="--..--";
  table["("]="-.--.";
  table[")"]="-.--.-";
  table["/"]="-..-.";
  table["="]="-...-";
  table["+"]=".-.-.";
  table["-"]="-....-";
  table["\""]=".-..-.";
  table["@"]=".--.-.";
}
