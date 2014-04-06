#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <led.h>
#include <morse.h>
#include <unistd.h>
void pish_parse(const string& str)
{
  stringstream ss(str);
  string cmd;
  ss>>cmd;
  vector<string> args;
  while(ss)
    {
      string arg;
      ss >> arg;
      args.push_back(arg);
    }
  string argstr;
  for(int i=0;i<args.size();++i)
    {
      argstr+=args[i]+' ';
    }
  if(cmd.length()==0)
    return; // exit early
  if(cmd=="exit" or cmd=="quit")
    {
      dash();
      exit(0);
    }
  else if(cmd=="morse")
    {
      if(argstr!="")
	{
	  dash();
	  usleep(250000);
	  transmit(argstr);
	  usleep(250000);
	  dash();
	}
      else
	{
	  cerr << "morse requires an argument" << endl;
	  dot();
	  usleep(250000);
	  dot();
	}
    }
  else if(cmd=="exec")
    {
      if(argstr=="")
	{
	  dot();
	  usleep(250000);
	  dot();
	}
      else
	{
	  dash();
	  usleep(250000);
	  int ret=system(argstr.c_str());
	  if(ret!=EXIT_SUCCESS)
	    {
	      cerr << "Command exited with return value " << ret << endl;
	      dot();
	      usleep(250000);
	      dot();
	    }
	  else
	    {
	      cerr << "Command exited normally." << endl;
	      dash();
	    }
	}
    }
  else if(cmd=="cd")
    {
      if(argstr!="")
	{
	  dash();
	  usleep(250000);
	  chdir(argstr.c_str());
	  dash();
	}
      else
	{
	  cerr << "Need an argument" << endl;
	  dot();
	  usleep(250000);
	  dot();
	}
    }
  else if(cmd=="pwd")
    {
      dash();
      usleep(250000);
      char* pwd=getcwd(0,0); // is this extension Linux only?
      cout << pwd << endl;
      transmit(string(pwd));
      free(pwd);
      usleep(25000);
      dash();
    }
  else
    {
      cerr << "Invalid command." << endl;
      dot();
      usleep(250000);
      dot();
    }
}
