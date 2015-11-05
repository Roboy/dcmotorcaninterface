#include <canlib.h>
#include <stdio.h>
#include <iostream>
#include <signal.h>
#include <QSettings>
#include <QObject>
#include <QTime>

#include "muscleDriverCANInterface.h"
#include "UserInterface.h"

#include <QCoreApplication>
using namespace std;

//can appliation
KvaserCanInterface myCan;

void delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

UserInterface::UserInterface()
{
    cout<<"User Interface started:"<<endl;
}
void UserInterface::run()
{
    int input=0;
    while (input!=9)
    {
	cout<<"User Interface: 0 to stop motor, 1 to start motor, 2 disable logging, 3 enable logging,  5 to set reference,  9 to end application (return)"<<endl;
	cin>>input;
	cout<<"Input was "<<input<<endl<<endl;
	if (input==0)
	{
	    cout<<"set motor drive signal to 0"<<endl;
	    emit stopMotors();
	}
	else if (input==1)
	{
	    cout<<"enable motor drive signal"<<endl;
	    emit startMotors();
	}
	
	else if (input==2)
	{
	    cout<<"disable logging"<<endl;
	    emit setLoggingEnable(false);
	}
	
	else if (input==3)
	{
	    cout<<"enable logging"<<endl;
	    emit setLoggingEnable(true);
	}
	
	else if (input==5)
	{
	    float reference;
	    cout<<"       Set Reference value (float) (return):"; cin>>reference;
	    cout<<endl<<"setting reference to :"<<reference<<endl;
	    emit setReference(reference);
	    //emit startMotors();
	}
	else if (input==9)
	{
	    cout<<"ending CAN application"<<endl;
	    emit stopMotors();
	    delay(200);
	    emit detachFromCAN();
	    
	}
	
	
    }
    
    cout<<"Ending application, please restart."<<endl;
    
};




int main (int argc, char *argv[])

{
    CAN_MESSAGE myCanMessage;
    STATUS_CODE myCanStatus;
    canHandle handle;
    canStatus status;
    int ret = -1;
    long id;
    unsigned char msg[8];
    unsigned int dlc;
    unsigned int flag;
    unsigned long time;
    int channelCount;
    int channel = 0;
    int bitrate = BAUD_1M;
    int j;
    unsigned int canData[4];
    
    QCoreApplication a(argc, argv);
    
    //start a CAN interface with a 1ms cycle time
    MuscleDriverCANInterface* canInterface  = new MuscleDriverCANInterface (1);
    
    QThread *canThread = new QThread;
    
    canInterface->moveToThread(canThread);
    canThread->start();
    
    QThread *thread = new QThread;
    UserInterface *myUserInterface = new UserInterface;
    //obj is a pointer to a QObject that will trigger the work to start. It could just be this
    //  connect(obj, SIGNAL(startWork()), worker, SLOT(doWork()));
    myUserInterface->moveToThread(thread);
    
    //connect user interface to CAN application
    
    //starts the userInterface run function when can thread has started
    QObject::connect(thread, SIGNAL(started()), myUserInterface, SLOT(run()),Qt::DirectConnection );
    
    
    //connect user interface to CAN application
    QObject::connect(myUserInterface, SIGNAL(setLoggingEnable(bool )), canInterface, SLOT(enableLogging(bool )), Qt::DirectConnection);
    QObject::connect(myUserInterface, SIGNAL(setReference(float )), canInterface, SLOT(getReference(float )), Qt::DirectConnection);
    QObject::connect(myUserInterface, SIGNAL(startMotors()), canInterface, SLOT(start()), Qt::DirectConnection);
    QObject::connect(myUserInterface, SIGNAL(stopMotors()), canInterface, SLOT(stop()), Qt::DirectConnection);
    QObject::connect(myUserInterface, SIGNAL(detachFromCAN()), canInterface, SLOT(detachCAN()), Qt::DirectConnection);
    thread->start();
    
    //cin>>startMotor;
    //if (st)
    //start CAN data processing
    //canInterface->start();
    
    cout<<" event loop"<<endl;
    //basic event-loop
    a.exec();
    
    cout<<"do we return?"<<endl;
    
    cout<<"waiting for 0 and return!"<<endl;
    cin>>j;
    
    cout<<endl<<"Quitting"<<endl;
}
