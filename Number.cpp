#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<sstream>
#include"Number.h"
using namespace std;


Number::Number(int n)
{
	if(n%10 == n)
		this->n = n;
	else
		exit(1);
}
Number::Number()	{ this->n=0; }
Number::Number(Number &n)	{ this->n = n.n; }
/*Number& Number::operator=(Number &l)
{
	this->n = l.n;
	return *this;
}*/
int Number::getNumber()		{return n;}
bool Number::equals(Number &n)	
{
	if(this->n == n.n)
		return true;
	else
		return false;
}
bool Number::compare(Number &n)
{
	if(this->n>n.n)
		return true;
	else
		return false;
}
string Number::tostring()
{	
	stringstream ss;
	string s;
	ss<<this->n;
	ss>>s;
	return s;
}
Number::~Number(){/*cout<<"Number byebye~\n"*/;}
/***********Number class is over*************/
TwoDigitNumber::TwoDigitNumber()
{
	Number w1(0),w2(0);
	TwoDigitNumber(w1, w2);
}
TwoDigitNumber::TwoDigitNumber(Number &n1, Number &n2)
{
	this->n1 = n1;
	this->n2 = n2;
}

int TwoDigitNumber::getNumber2()	{return n1.getNumber()*10+n2.getNumber();}

bool TwoDigitNumber::equals(TwoDigitNumber &n)
{
	if(this->n1.equals(n.n1) && this->n2.equals(n.n2)) 
		return true;
	else
		return false;
}
bool TwoDigitNumber::compare(TwoDigitNumber &n)
{
	if(this->n1.compare(n.n1) && this->n2.compare(n.n2))
		return true;
	else
		return false;
}
string TwoDigitNumber::tostring()
{
	stringstream ss;
	string s;
	ss<<this->getNumber2();
	ss>>s;
	return s;
}
TwoDigitNumber::~TwoDigitNumber(){/*cout<<"TwoDigitNumber byebye~\n"*/;}
/***********TwoDigitNumber class is over*************/
ThreeDigitNumber::ThreeDigitNumber(Number &n1, TwoDigitNumber &n2)
{	
	this->n1 = n1;
	this->n2 = n2;
}
int ThreeDigitNumber::getNumber3(){return this->n1.getNumber()*100+this->n2.getNumber2();}
bool ThreeDigitNumber::equals(ThreeDigitNumber &n)
{
	if(this->n1.equals(n.n1) && this->n2.equals(n.n2))
		return true;
	else
		return false;
}
bool ThreeDigitNumber::compare(ThreeDigitNumber &n)
{
	if(this->n1.compare(n.n1) && this->n2.compare(n.n2))
		return true;
	else
		return false;
}
string ThreeDigitNumber::tostring()
{			
	stringstream ss;
	string s;
	ss<<this->n1.getNumber()*100+this->n2.getNumber2();
	ss>>s;
	return s;
}
ThreeDigitNumber::~ThreeDigitNumber(){/*cout<<"ThreeDigitNumber byebye~\n"*/;}

/***********ThreeDigitNumber class is over*************/
Number TestNumbers::getFirstDigit(int n)
{
	while(n%10!=n)
	{
		n/=10;
	}
	Number digit1(n);
	return digit1;
}
Number TestNumbers::getSecondDigit(int n)
{
	while(n%100!=n)
	{
		if(n%10==n)	break;	
		n/=10;
	}
	n= n%10;
	Number digit2(n);
	return digit2;
}
Number** TestNumbers::genNums()
{
	cout<<"start to yield random number........"<<endl;
	memset(avg, 0, sizeof(avg));
	static Number *sc[100];
	int num[100];
	srand(time(NULL));
	for(int i=0; i<100; i++)
	{
		num[i] = rand()%999+0;
		if(num[i]%10 == num[i])
		{
			Number *a1 = new Number(num[i]);
			sc[i] = a1;
		}
		else if(num[i]%100==num[i])
		{
			int ten, one;
			ten = num[i]/10;
			one = num[i]%10;
			Number qq1(ten),qq2(one);
			Number *a2 = new TwoDigitNumber(qq1, qq2);
			sc[i] = a2;
		}
		else if(num[i]%1000 ==num[i])
		{
			int hundred, ten, one;
			hundred = num[i]/100;
			ten = (num[i]/10)%10;
			one = num[i]%10;
			Number a1(hundred), qq1(ten), qq2(one);
			TwoDigitNumber a2(qq1, qq2);

			Number *q3 = new ThreeDigitNumber(a1, a2);
			ThreeDigitNumber p(a1,a2);
			sc[i] = q3;
			avg[i] = p.getNumber3();
		}
		else
		{
			perror("random is error");
		}
	}
	return sc;
}

string TestNumbers::printAvg(Number** num)
{
	int count=0, avge, sum=0;
	for(int i=0;i<100;i++)
	{
		if(avg[i]!=0)
		{
			++count;
			sum+=avg[i];
		}
	}
	avge = sum/count;
	stringstream ss;
	string s;
	ss<<avge;
	ss>>s;
	return s;
}
TestNumbers::~TestNumbers(){/*cout<<"TestNumber byebye~\n"*/;}

/***********TestNumbers class is over*************/
