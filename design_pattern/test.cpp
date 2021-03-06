/*设计模式原则:
 1、单一职责原则（Single Responsibility Principle）
 2、里氏替换原则（Liskov Substitution Principle）
 3、依赖倒置原则（Dependence Inversion Principle）
 4、接口隔离原则（Interface Segregation Principle）
 5、迪米特法则（Law Of Demeter）
 6、开闭原则（Open Close Principle）
*/

#include <iostream>

//创建型模式
#include "patterns/Creational_Patterns/factory.h"
#include "patterns/Creational_Patterns/abstractFactory.h"
#include "patterns/Creational_Patterns/singleton.h"
#include "patterns/Creational_Patterns/builder.h"
#include "patterns/Creational_Patterns/prototype.h"

//结构型模式
#include "patterns/Structural_Patterns/bridge.h"
#ifndef _CLASS_ADAPTER__
//#define _CLASS_ADAPTER__  //测试类模式Adapter还是对象模式Adapter的标识
#include "patterns/Structural_Patterns/adapter.h"
#endif
#include "patterns/Structural_Patterns/decorator.h"
#include "patterns/Structural_Patterns/composite.h"
#include "patterns/Structural_Patterns/flyweight.h"
#include "patterns/Structural_Patterns/facade.h"
#include "patterns/Structural_Patterns/proxy.h"

//行为模式
#include "patterns/Behavioral_Patterns/template.h"
#include "patterns/Behavioral_Patterns/strategy.h"
#include "patterns/Behavioral_Patterns/state.h"
#include "patterns/Behavioral_Patterns/Observer/observer.h"
#include "patterns/Behavioral_Patterns/memento.h"
#include "patterns/Behavioral_Patterns/command.h"
#include "patterns/Behavioral_Patterns/Mediator/mediator.h"
#include "patterns/Behavioral_Patterns/Visitor/visitor.h"
#include "patterns/Behavioral_Patterns/ChianOfResponsibility/ChianOfResponsibility.h"
#include "patterns/Behavioral_Patterns/Iterator/aggregate.h"
#include "patterns/Behavioral_Patterns/Iterator/iterator.h"
#include "patterns/Behavioral_Patterns/Interpreter/Interpreter.h"


void test_observe()
{
	SubjectObserver* sub = new ConcreteSubjectObserverA;
	Observer* ob1 = new ConcreteObserverA(sub);
	Observer* ob2 = new ConcreteObserverB(sub);

	sub->SetState("old");
	sub->Notify();
	sub->SetState("new");
	sub->Notify();

	delete sub;
	delete ob1;
	delete ob2;
}

void test_decorator()
{
	Component* com = new ConcreteComponent();
	Decorator* dec = new ConcreteDecorator(com);
	dec->Operation();

	delete com;
	delete dec;	
}

void test_factory()
{
	Factory* fac = new ConcreteFactory();
	Product* pro = fac->CreateProduct();

	delete fac;
	delete pro;
}

void test_abstract_factory()
{
	AbstractFactory* cf1 = new ConcreteFactory1();
	cf1->CreateProductA();
	cf1->CreateProductB();

	AbstractFactory* cf2 = new ConcreteFactory2();
	cf2->CreateProductA();
	cf2->CreateProductB();

	delete cf1;
	delete cf2;
}

void test_singlnton()
{
	Singlnton* sgn1 = Singlnton::Instance();
	Singlnton* sgn2 = Singlnton::Instance();
	if (sgn1 == sgn2)
	{
		std::cout << "singln ..." << std::endl;
	}
	else
	{
		std::cout << "not singln ..." << std::endl;
	}
}

void test_command()
{
	Receiver* rev = new Receiver();
	ConcreteCommand* concmd = new ConcreteCommand(rev);
	Invoker* inv = new Invoker(concmd);
	inv->Invoke();

	delete rev;
	delete concmd;
	delete inv;
}

#ifdef _CLASS_ADAPTER__
void test_adapter()
{
	Target* tag = new Adapter;
	tag->Request();

	delete tag;
}
#else
void test_adapter()
{
	Adaptee* ade = new Adaptee;
	Target* tag = new Adapter(ade);
	tag->Request();

	delete ade;
	delete tag;
}
#endif

void test_template()
{
	AbstractClass* p1 = new ConcreteClass1;
	AbstractClass* p2 = new ConcreteClass2;
	p1->TemplateMethod();
	p2->TemplateMethod();

	delete p1;
	delete p2;
}

void test_strategy()
{
	Strategy* stg = new ConcreteStrategyA;
	Context* ctt = new Context(stg);
	ctt->DoAction();

	delete stg;
	delete ctt;
}

void test_bridge()
{
	AbstractionImp* impA = new ConcreteAbstractionImpA;
	Abstraction* act = new RefinedAbstraction(impA);

	act->Operation();

	delete impA;
	delete act;
}

void test_proxy()
{
	Subject* sbj = new ConcreteSubject;
	Proxy* pro = new Proxy(sbj);
	pro->Request();

	delete sbj;
	delete pro;
}

void test_prototype()
{
	Prototype* p = new ConcretePrototype;
	Prototype* p1 = p->Clone();

	delete p;
	delete p1;
}

void test_builder()
{
	Builder* bld = new ConcreteBuilder;
	Director* dct = new Director(bld);
	dct->Construct();

	ProductBuild* pdt = bld->GetProduct();
	pdt->Show();

	delete bld;
	delete dct;
}

void test_composite()
{
	Leaf* l = new Leaf;
	l->Operation();

	ComponentComposite* com = new Composite;
	com->Add(l);
	com->Operation();

	ComponentComposite* l1 = com->GetChild(0);
	l1->Operation();
}

void test_flyweight()
{
	FlyweightFactory* fc = new FlyweightFactory;

	Flyweight* fw1 = fc->GetFlyweight("hello");
	Flyweight* fw2 = fc->GetFlyweight("world");
	Flyweight* fw3 = fc->GetFlyweight("hello");

	fw1->Operation("Lucy");
	fw2->Operation("Lily");
	fw3->Operation("Samao");

	delete fc;
}

void test_facade()
{
	Facade* f = new Facade;
	f->OperationWrapper();

	delete f;
}

void test_state()
{
	State* st = new ConcreteStateA;
	ContextState* con = new ContextState(st);
	con->OperationChangeState();
	con->OperationChangeState();
	con->OperationChangeState();
	con->OperationChangeState();
	con->OperationChangeState();

	delete st;
	delete con;
}

void test_memento()
{
	Originator* o = new Originator;
	o->SetState("old");
	o->PrintState();

	Memento* m = o->CreateMemento();  //备忘当前状态

	o->SetState("new");
	o->PrintState();

	o->RestoreToMemento(m);  //恢复状态
	o->PrintState();

	delete o;
}

void test_mediator()
{
	ConcreteMediator* pConMdt = new ConcreteMediator();
	ConcreteColleageA* pConClgA = new ConcreteColleageA(pConMdt);
	ConcreteColleageB* pConClgB = new ConcreteColleageB(pConMdt);

	pConMdt->IntroColleage(pConClgA, pConClgB);

	pConClgA->SetState("old");
	pConClgB->SetState("old");
	pConClgA->Action();
	pConClgB->Action();

	pConClgA->SetState("new");
	pConClgA->Action();
	pConClgB->Action();

	pConClgB->SetState("old");
	pConClgB->Action();
	pConClgA->Action();
}

void test_visitor()
{
	Visitor* pVis = new ConcreteVisitorA();
	Element* pElm = new ConcreteElementA();
	pElm->Accept(pVis);
}

void test_ChinaOfResponsibility()
{
	Handler* ph1 = new ConcreteHandlerA();
	Handler* ph2 = new ConcreteHandlerB();

	ph1->SetSuccessor(ph2);
	ph1->HandleRequest();
}

void test_iterator()
{
	Aggregate* pAg = new ConcreteAggregate();
	Iterator* pItor = new ConcreteIterator(pAg);
	for (; !pItor->IsDone(); pItor->Next())
	{
		std::cout << pItor->CurrentItem() << std::endl;
	}
}

void test_interpreter()
{
	ContextInterpreter* pContext = new ContextInterpreter();
	AbstractExpression* pTe = new TerminalExpression("hello world");
	AbstractExpression* pNte = new NonterminalExpression(pTe, 3);

	pNte->Interpreter(*pContext);
}

int main(int argc , char *argv [])
{
	//test_observe();

	//test_decorator();

	//test_factory();

	//test_abstract_factory();

	//test_singlnton();

	//test_command();

	//test_adapter();

	//test_template();

	//test_strategy();

	//test_bridge();

	//test_proxy();

	//test_prototype();

	//test_builder();

	//test_composite();

	//test_flyweight();

	//test_facade();

	//test_state();

	//test_memento();

	//test_mediator();

	//test_visitor();

	//test_ChinaOfResponsibility();

	//test_iterator();

	test_interpreter();

	return 0;
}