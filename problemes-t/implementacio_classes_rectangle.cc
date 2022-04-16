//.h especificacions
//.cc implementacions

#include <iostream>
#include <utility>
using namespace std;

class Point {
public:
    Point(double x_coor, double y_coor)
    {
    }
    // Rotate the rectangle 90 degrees clockwise or
    // counterclockwise, depending on the value of the parameter. // The rotation should be done around the lower-left corner // of the rectangle.
    void rotate(bool clockwise)
    {
        //al rotar tmb hem de modificar el punt bt que teniem
        swap(width, height);
        if (clockwise) {
            bt = Point(bt.getX(), bt.getY() - w); //la x es mante, les y decrementen
        } else {
            bt = Point(bt.getX() - h, bt.getY()); //la y es mante, les x decrementen
        }
    }
    // Flip horizontally (around the left edge) or vertically (around
    // the bottom edge), depending on the value of the parameter.
    void flip(bool horizontally)
    {
        bt = (horizontally ? Point(bt.getX() - w, ll.getY()) : Point(bt.getX(), ll.getY() - h));
    }
    // Check whether point p is inside the rectangle
    bool isPointInside(const Point& p) const
    {
        return (ll.getX() <= p.getX()
            and p.getX() <= p.getX() + w
            and bt.getY <= p.getY()
            and bt.getY <= p.getY() + h)
    }

private:
    Point bt; //bottom left
    double height, width;
};

int main()
{
    Point bt;
    double height, width;
    cin >> bt >> height >> width;
}
