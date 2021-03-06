/*����ģʽ
 */

#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <iostream>

class Receiver
{
public:
	Receiver(){}
	~Receiver(){}

public:
	void Action(){ std::cout << "Receiver action ..." << std::endl; }
};


class Command
{
public:
	virtual ~Command(){}
	virtual void Excute() = 0;

protected:
	Command(){}
};


class ConcreteCommand : public Command
{
public:
	ConcreteCommand(Receiver* rev) : rev_(rev) {}
	~ConcreteCommand(){}
	void Excute()
	{
		rev_->Action();
	}

private:
	Receiver* rev_;
};


class Invoker
{
public:
	Invoker(Command* cmd) : cmd_(cmd) {}
	void Invoke()
	{
		cmd_->Excute();
	}
private:
	Command* cmd_;
};

#endif