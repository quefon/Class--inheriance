#include<iostream>
#include"Number.h"
using namespace std;

int main()
{
	int i=0;
	Number q1(5), q2(4);
	//Number t4;
	//t4 = q1;
	cout<<"q1's number = "<<q1.getNumber()<<endl;
	cout<<"q2's number = "<<q2.getNumber()<<endl;
	if(q1.equals(q2))
		cout<<"q1 and q2 equals~"<<endl;
	else
		cout<<"q1 and q2 not equals~"<<endl;
	if(q1.compare(q2))
		cout<<"q1 is bigger than q2~"<<endl;
	else
		cout<<"q2 is bigger than q1~"<<endl;
	Number q3(q2);
	cout<<"q3's number = "<<q3.getNumber()<<endl;
	string sc1;
	sc1 = q1.tostring();//trcpy(sc, q1.tostring());
	cout<<"sc1 = "<<sc1<<endl<<endl;

	cout<<"Number test is over"<<endl<<endl;

/********Number test is over********/

	TwoDigitNumber b1, b2(q1, q2);
	cout<<"b1's number = "<<b1.getNumber2()<<endl;
	cout<<"b2's number = "<<b2.getNumber2()<<endl;
	if(b1.equals(b2))
		cout<<"b1 and b2 equals~"<<endl;
	else
		cout<<"b1 and b2 not equals~"<<endl;
	if(b1.compare(b2))
		cout<<"b1 is bigger than b2~"<<endl;
	else
		cout<<"b2 is bigger than b1~"<<endl;
	string sc2;
	sc2 = b2.tostring();
	cout<<"sc2 = "<<sc2<<endl<<endl;

	cout<<"--------TwoDigitNumber test is over--------"<<endl<<endl;

/********TwoDigitNumber test is over********/
	
	ThreeDigitNumber c1(q1, b2), c2(q2,b1);
	if(c1.equals(c2))
		cout<<"c1 and c2 equals~"<<endl;
	else
		cout<<"c1 and c2 not equals~"<<endl;
	if(c1.compare(c2))
		cout<<"c1 is bigger than c2~"<<endl;
	else
		cout<<"c2 is bigger than c1~"<<endl;
	string sc3;
	sc3 = c1.tostring();
	cout<<"sc3 = "<<sc3<<endl<<endl;

	cout<<"--------ThreeDigitNumber test is over--------"<<endl<<endl;

/********ThreeDigitNumber test is over********/
	
	Number temp1,temp2;
	TestNumbers d1,d2;
	cout<<"<d1 = 456> , <d2 = 199>"<<endl;
	temp1 = d1.getFirstDigit(456);
	temp2 = d2.getSecondDigit(199);
	cout<<"d1's number = "<<temp1.getNumber()<<endl;
	cout<<"d2's number = "<<temp2.getNumber()<<endl;
	string sc4 = d1.printAvg(d1.genNums());
	cout<<"Avg = "<<sc4<<endl<<endl;

	cout<<"--------TestNumbers test is over--------"<<endl<<endl;
/********TestNumbers test is over********/
	cout<<"End program"<<endl;
	return 0;
}
