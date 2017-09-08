#ifndef NUMBER_H_INCLUDE
#define NUMBER_H_INCLUDE
#include<string.h>


class Number{
	protected:
		int n;
	public:	
		Number(int n);
		Number();
		Number(Number &n);
		int getNumber();
		bool equals(Number &n);
		bool compare(Number &n);
		std::string tostring();
		//Number& operator=(Number &l);
		virtual ~Number();
};
class TwoDigitNumber:public Number{
	protected:
		Number n1, n2;
	public:
		TwoDigitNumber();
		TwoDigitNumber(Number &n1, Number &n2);
		int getNumber2();
		bool equals(TwoDigitNumber &n);
		bool compare(TwoDigitNumber &n);
		std::string tostring();
		virtual ~TwoDigitNumber();
};
class ThreeDigitNumber:public TwoDigitNumber{
	protected:
		Number n1;
		TwoDigitNumber n2;
	public:
		ThreeDigitNumber(Number &n1, TwoDigitNumber &n2);
		int getNumber3();
		bool equals(ThreeDigitNumber &n);
		bool compare(ThreeDigitNumber &n);
		std::string tostring();
		virtual ~ThreeDigitNumber();
};
class TestNumbers{
	public:
		Number getFirstDigit(const int n);
		Number getSecondDigit(const int n);
		static Number** genNums();
		static std::string printAvg(Number** num);
		virtual ~TestNumbers();
	
};
static int avg[100];
#endif
