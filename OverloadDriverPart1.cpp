//Demo code for operator overload in C++

#include <iostream>

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
};

Point::Point():x(0),y(0){}
Point::Point(int x, int y): x(x), y(y){}
void Point::showPoint(){cout << x << " " << y << endl;}


//simple line class containing two points
class Line
{
	private: 
		Point p1, p2;

	public:
		Line();
		Line(Point, Point);
		void showLine();
		Point getP1();
		
};

Line::Line(Point p1, Point p2):p1(p1),p2(p2){}
Line::Line(){}		// why don't I need to construct the points?
void Line::showLine(){p1.showPoint(); p2.showPoint();}


int main()
{
	//1. Review the above classes and answer any questions
	
	
	/*int y = 2;
	int x = 3; 
	cout << x+y;
	//x + y translates to a function  "operator+(x,y);"
	
	double y = 2.0;
	double x = 3.0; 
	cout << x + y;*/
	//x + y translates to a function  "operator+(x,y);" but for doubles
	
	//But what about more complex objects?
	
	
	//2. Create a void assignment overload for each class above
	
		//Think about how assignment works p1 = p2; 
		//Function wise this would look like p1.eq(p2);
		//On the left is the calling object and on the right is the object being sent
		
	//3. Test the void assignment operators
	//4. Attempt to "chain" (p1 = p2 = p3) and observe the results.
	//5. Why does this fail? How do we fix it?
	//6. What's the difference in the assignment operator and the construtor?
	
	
	//7. Now for something more complicated. I want to be able to say p1 = p2 + p3;
		//How does "replacement work?"
		//Why would an arithmetic expression need two arguments and why does the 
		//assignment only need one?
		
	//8. How many "objects" are involved in an arithmetic expression?
	//9. What is a "friend?"
	//10. Create a friend function for overloading addition on point and line. 
	//11. Test
		//How could we implement this without making the function a "friend?"
		//How could we implement it as a member function?
		
	//12. Implement the subtraction overload for homework
	//13. Would compound assignment operators be member functions?
	//14. Would relational operators be member functions?
	//15. Implement the equality and inequality operator for points and lines as homework
	//16. Implement the <> operators for lines based on line length
	//17. Implement any one of the compound assignment operators for homework
	//18. Next class we'll work on streams, conversion, increment/decrement, and subscript
}
