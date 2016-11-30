/*
 * author: Elisa Maiettini
 * date: 26/11/2016
 */
#include <iostream>
#include <iomanip>
#include <yarp/os/Network.h>
#include <yarp/os/RFModule.h>
#include <yarp/os/RpcServer.h>
#include <yarp/os/Semaphore.h>

//#include <FIFOController.hpp>
#include <vocabs.hpp>

#include <stdio.h>
#include <string>
#include <ctime>
#include <list>

using namespace std;
using namespace yarp::os;
class ServerModule : public RFModule
{
private:

	RpcServer        server_port;
	Bottle           in, out;
	int              CNT;

	std::list<int>   FIFO;
	Semaphore        fifo_mutex;

public:

  double getPeriod(){
    return 1.0;
  }

  virtual bool respond(const Bottle &command, Bottle &reply){
    return true;
  }

  bool interruptModule(){
    server_port.interrupt();
    return true;
  }

  bool close(){
    server_port.close();
    return true;
  }

    virtual bool updateModule();

    bool configure(yarp::os::ResourceFinder &rf);

		std::list<int>::iterator getFIFO();
};