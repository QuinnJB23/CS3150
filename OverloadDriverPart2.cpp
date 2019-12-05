//Demo code for operator overload in C++

#include <iostream>
#include "OverloadDriverPart2.h"

using namespace std;


//simple Point class 
class Point
{
	private: 
		int x,y;

	public:
		Point();
		Point(int, int);
		void showPoint();

		Point operator++();
		Point operator++(int);
		int& operator[](int);

		friend ostream& operator<<(ostream&, const Point&);
		friend istream& operator>>(istream&, Point&);
		friend class Line;
		friend istream& operator>>(istream&, Line&);
		friend ostream& operator<<(ostream&, const Line&);
		friend void operator++(Line&);

};

Point::Point():x(0),y(0){}
Point::Point(int x, int y): x(x), y(y){}
void Point::showPoint(){cout << x << " " << y << endl;} 

int& Point::operator[] (int index)
{
	if(index == 0) return x; else return y;
}

Point Point::operator++()
{
	x++;
	y++;
	return *this;
}

Point Point::operator++(int)
{
	Point temp = *this;

	x++;
	y++;
	
	return temp;
}

ostream& operator<<(ostream& ost, const Point& p)
{
	return ost << p.x << ',' << p.y;
}

istream& operator>>(istream& ist, Point& p)
{
	cout << "x = ";
	ist >> p.x;

	cout << "y = ";
	ist >> p.y;

	return ist;
}

//simple line class containing two points
class Line
{
	private: 
		Point p1, p2;

	public:
		Line();
		Line(Point, Point);
		void showLine();

		friend istream& operator>>(istream&, Line&);
		friend ostream& operator<<(ostream&, const Line&);
		friend void operator++(Line&);

};

Line::Line(Point p1, Point p2):p1(p1),p2(p2){}
Line::Line(){}		// why don't I need to construct the points?
void Line::showLine(){p1.showPoint(); p2.showPoint();}

istream& operator>>(istream& ist, Line& l)
{
	cout << "Line 1" << endl;
	cout << "x = ";
	ist >> l.p1.x;
	cout << "y = ";
	ist >> l.p1.y;
	cout << "Line 2" << endl;
	cout << "x = ";
	ist >> l.p2.x;
	cout << "y = ";
	ist >> l.p2.y;
}

ostream& operator<<(ostream& ost, const Line& l)
{
	return ost << "(" << l.p1.x << "," << l.p1.y << ") (" << l.p2.x << "," << l.p2.y << ")";
}

void operator++(Line& l)
{
	++l.p2.x;
	++l.p2.y;
}

int main()
{

	//Point p1 (3,5);
	/*Point p2;

	cout << p1 << endl;
	cout << p1 << endl;
	cin >> p2;
	cout << p2 << endl;

	++p1;
	cout << p1 << endl;
	*/
	//p1++;
	//cout << p1[1];

	//PART 1
	//1. Review the above classes and answer any questions
	//2. Create a void assignment overload for each class above
	//3. Test the void assignment operators
	//4. Attempt to "chain" and observe the results
	//5. Why does this fail?
	//6. What's the difference in the assignment operator and the construtor?
	//7. Now for something more complicated. Why would an arithmetic expression need two
	//arguments and why does the assignment only need one?
	//8. How many "objects" are involved in an arithmetic expression?
	//9. What is a "friend?"
	//10. Create a friend function for overloading addition on point and line
	//11. Test
	//12. Implement the subtraction overload for homework
	//13. Would compound assignment operators be member functions?
	//14. Would relational operators be member functions?
	//15. Implement the equality and inequality operator for points and lines as homework
	//16. Implement the <> operators for lines based on line length
	//17. Implement any one of the compound assignment operators for homework
	//18. Next class we'll work on streams, conversion, increment/decrement, and subscript
	
	
	//PART 2
	//1. Member function or friend function?
	//2. Create a output operator overload for point. 
	//3. Implement a line output stream operator for homework. 
	
	cout << "Q3: " << endl;
	Point p1;
	cin >> p1;
	cout << p1 << endl;

	//4. Create an input stream operator for point. 
	//5. Why did we have to drop the const in this situation?
	//6. Implement a line input stream operator for homework. 
	cout << "Q6: " << endl;
	Line l1;
	cin >> l1;
	cout << l1 << endl;

	//7. Let's talk about conversion. Would that be a member of friend?
	//8. We aren't going to implement conversion for this class. I don't think it makes
	//sense in this example, but make sure you read through it. 
	//9. Increment and decrement friend or member?
	//10. Create a pre increment overload
	//11. Create a post increment overload
	//12. What is the functional difference?
	//13. Implement a pre increment overload for line that just increments p2 for homework
	
	++l1;
	cout << l1 << endl;

	//14. Subscript member or friend?
	//15. What would it return and what would you need to send it?
	//16. Create a subscript operator overload for point
	//17. Implement a subscript operator for line that returns a point for homework
	


	//18. How else could you setup a subscript operator with line?

	
}
