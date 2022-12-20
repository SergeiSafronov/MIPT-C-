#include <math.h>
#include "geometry.h"

namespace myGeometry {

    // SQUARE ////////////////////////////////////////////////////////////////////////////

    Square::Square(struct point p1, struct point p2)//p1 - left up; p2 - right down
    {
        struct point P1, P2;
        if (p1.X <= p2.X)
        {
            P1.X = p1.X;
            P2.X = p2.X;
        }
        else
        {
            P1.X = p2.X;
            P2.X = p1.X;
        }
        if (p1.Y <= p2.Y)
        {
            P1.Y = p2.Y;
            P2.Y = p1.Y;
        }
        else
        {
            P1.Y = p1.Y;
            P2.Y = p2.Y;
        }
        if (p1.X == p2.X)
        {
            P2.X = P1.X + 1;
            P2.Y = P1.Y - 1;
        }

        Point0.X = P1.X;
        Point0.Y = P1.Y;
        Point2.X = P2.X;
        Point2.Y = P2.Y;

        Point1.X = P1.X;
        Point1.Y = P2.Y;
        Point3.X = P2.X;
        Point3.Y = P1.Y;
    }

    double Square::areaCount()
    {
        return ((Point3.X - Point0.X) * (Point0.Y - Point1.Y));
    }

    double Square::perimeterCount()
    {
        return 2 * ((Point3.X - Point0.X) + (Point0.Y - Point1.Y));
    }

    //Правильная ориентация задаётся ещё в конструкторе
    void Square::getPoints()
    {
        std::cout << "(" << Point3.X << ", " << Point3.Y << ") ";
        std::cout << "(" << Point2.X << ", " << Point2.Y << ") ";
        std::cout << "(" << Point1.X << ", " << Point1.Y << ") ";
        std::cout << "(" << Point0.X << ", " << Point0.Y << ") ";
    }

    int Square::checkPointInside(struct point PointInside)
    {
        if (PointInside.X > Point0.X)
            if (PointInside.X < Point2.X)
                if (PointInside.Y > Point1.Y)
                    if (PointInside.Y < Point0.Y)
                        return 1;
        return 0;
    }

    struct point* Square::returnPoints()
    {
        struct point points[4] = { Point0, Point1, Point2, Point3 };
        return points;
    }

    int Square::checkCrossing(int figureType, Shape* fig)
    {
        if (figureType == 1) //Square
        {
            struct point* points = (*fig).returnPoints();
            int result = checkPointInside(points[0]) * checkPointInside(points[1]) * checkPointInside(points[2]) * checkPointInside(points[3]);
            result *= (*fig).checkPointInside(Point0) * (*fig).checkPointInside(Point1) * (*fig).checkPointInside(Point2) * (*fig).checkPointInside(Point3);
            return result;
        }
        if (figureType == 2) //Triangle
        {
            struct point* points = (*fig).returnPoints();
            int result = checkPointInside(points[0]) * checkPointInside(points[1]) * checkPointInside(points[2]);
            result *= (*fig).checkPointInside(Point0) * (*fig).checkPointInside(Point1) * (*fig).checkPointInside(Point2) * (*fig).checkPointInside(Point3);
            return result;
        }
        if (figureType == 3) //Circle
        {
            //struct point* points = (*fig).returnPoints();
            int result = (*fig).checkPointInside(Point0) * (*fig).checkPointInside(Point1) * (*fig).checkPointInside(Point2) * (*fig).checkPointInside(Point3);
            return result;
        }
        return -1;
    }


    // TRIANGLE///////////////////////////////////////////////////////////////////////////

    Triangle::Triangle(struct point up, struct point lDown, struct point rDown)
    {
        struct point P1, P2, P3;
        /*
        if ((up.X == lDown.X && up.Y == lDown.Y) || (up.X == rDown.X && up.Y == rDown.Y) || (lDown.X == rDown.X && lDown.Y == rDown.Y))
        {
            Point0.X = up.X;
            Point0.Y = up.Y;
            Point1.X = Point0.X - 1;
            Point1.Y = Point0.Y - 1;
            Point2.X = Point2.X + 1;
            Point2.Y = Point2.Y - 1;
        }
        else
        {
            Point0.X = up.X;
            Point0.Y = up.Y;
            Point1.X = lDown.X;
            Point1.Y = lDown.Y;
            Point2.X = rDown.X;
            Point2.Y = rDown.Y - 1;
        }
        */
        Point0.X = up.X;
        Point0.Y = up.Y;
        Point1.X = lDown.X;
        Point1.Y = lDown.Y;
        Point2.X = rDown.X;
        Point2.Y = rDown.Y - 1;
    }

    double Triangle::areaCount()
    {
        double area = 0.5 * ((Point1.X - Point0.X) * (Point2.Y - Point0.Y) - (Point2.X - Point0.X) * (Point1.Y - Point0.Y));

        if (area > 0)
            return area;
        return -1 * area;
    }


    double Triangle::perimeterCount()
    {
        double l1 = sqrt((Point0.X - Point1.X) * (Point0.X - Point1.X) + (Point0.Y - Point1.Y) * (Point0.Y - Point1.Y));
        double l2 = sqrt((Point1.X - Point2.X) * (Point1.X - Point2.X) + (Point1.Y - Point2.Y) * (Point1.Y - Point2.Y));
        double l3 = sqrt((Point0.X - Point2.X) * (Point0.X - Point2.X) + (Point0.Y - Point2.Y) * (Point0.Y - Point2.Y));

        return l1 + l2 + l3;
    }


    void Triangle::getPoints()
    {

        std::cout << "(" << Point0.X << ", " << Point0.Y << ") " << "\n";
        std::cout << "(" << Point1.X << ", " << Point1.Y << ") " << "\n";
        std::cout << "(" << Point2.X << ", " << Point2.Y << ") " << "\n";

        /*
        double Y;
        struct point P1, P2;
        //Выводим самую правую нижнюю точку. Плюс - сохраняем координаут Y у неё.
        if (Point0.X <= Point1.X)
        {
            if (Point1.X <= Point2.X)
            {
                if (Point1.X == Point2.X)
                {
                    if (Point1.Y > Point2.Y)
                    {
                        std::cout << "(" << Point2.X << ", " << Point2.Y << ") ";
                        P1.X = Point0.X; P1.Y = Point0.Y;
                        P2.X = Point1.X; P2.Y = Point1.Y;
                        Y = Point2.Y;
                    }
                    else
                    {
                        std::cout << "(" << Point1.X << ", " << Point1.Y << ") ";
                        P1.X = Point0.X; P1.Y = Point0.Y;
                        P2.X = Point2.X; P2.Y = Point2.Y;
                        Y = Point1.Y;
                    }
                }
                else
                {
                    std::cout << "(" << Point2.X << ", " << Point2.Y << ") ";
                    P1.X = Point0.X; P1.Y = Point0.Y;
                    P2.X = Point1.X; P2.Y = Point1.Y;
                    Y = Point2.Y;
                }
            }
            else
            {

                std::cout << "(" << Point1.X << ", " << Point1.Y << ") ";
                P1.X = Point0.X; P1.Y = Point0.Y;
                P2.X = Point2.X; P2.Y = Point2.Y;
                Y = Point1.Y;
            }
        }
        else
        {
            if (Point0.X <= Point2.X)
            {
                if (Point0.X == Point2.X)
                {
                    if (Point0.Y > Point2.Y)
                    {
                        std::cout << "(" << Point2.X << ", " << Point2.Y << ") ";
                        P1.X = Point0.X; P1.Y = Point0.Y;
                        P2.X = Point1.X; P2.Y = Point1.Y;
                        Y = Point2.Y;
                    }
                    else
                    {
                        std::cout << "(" << Point0.X << ", " << Point0.Y << ") ";
                        P1.X = Point1.X; P1.Y = Point1.Y;
                        P2.X = Point2.X; P2.Y = Point2.Y;
                        Y = Point0.Y;
                    }
                }
                else
                {
                    std::cout << "(" << Point2.X << ", " << Point2.Y << ") ";
                    P1.X = Point0.X; P1.Y = Point0.Y;
                    P2.X = Point1.X; P2.Y = Point1.Y;
                    Y = Point2.Y;
                }
            }
            else
            {

                std::cout << "(" << Point0.X << ", " << Point0.Y << ") ";
                P1.X = Point1.X; P1.Y = Point1.Y;
                P2.X = Point2.X; P2.Y = Point2.Y;
                Y = Point0.Y;
            }
        }

        std::cout << "\n";

        if (P1.Y != Y && P2.Y != Y)
        {
            if (P1.Y > P2.Y)
                std::cout << "(" << P2.X << ", " << P2.Y << ") " << "\n";
            else
                std::cout << "(" << P1.X << ", " << P1.Y << ") " << "\n";
        }
        else
        {
            if (P1.Y == Y)
            {
                std::cout << "(" << P2.X << ", " << P2.Y << ") " << "\n";
                std::cout << "(" << P1.X << ", " << P1.Y << ") " << "\n";
            }
            else
            {
                std::cout << "(" << P1.X << ", " << P1.Y << ") " << "\n";
                std::cout << "(" << P2.X << ", " << P2.Y << ") " << "\n";
            }
        }
        */
    }

    int Triangle::checkPointInside(struct point PointInside)
    {
        double r0 = (Point0.X - PointInside.X) * (Point1.Y - Point0.Y) - (Point1.X - Point0.X) * (Point0.Y - PointInside.Y);
        double r1 = (Point1.X - PointInside.X) * (Point2.Y - Point1.Y) - (Point2.X - Point1.X) * (Point1.Y - PointInside.Y);
        double r2 = (Point2.X - PointInside.X) * (Point0.Y - Point2.Y) - (Point0.X - Point2.X) * (Point2.Y - PointInside.Y);

        if (r0 > 0)
            if (r1 > 0)
                if (r2 > 0)
                    return 1;
        if (r0 < 0)
            if (r1 < 0)
                if (r2 < 0)
                    return 1;
        return 0;
    }

    struct point* Triangle::returnPoints()
    {
        struct point points[3] = { Point0, Point1, Point2 };
        return points;
    }

    int Triangle::checkCrossing(int figureType, Shape* fig)
    {
        if (figureType == 1) //Square
        {
            struct point* points = (*fig).returnPoints();
            int result = checkPointInside(points[0]) * checkPointInside(points[1]) * checkPointInside(points[2]) * checkPointInside(points[3]);
            result *= (*fig).checkPointInside(Point0) * (*fig).checkPointInside(Point1) * (*fig).checkPointInside(Point2);
            return result;
        }
        if (figureType == 2) //Triangle
        {
            struct point* points = (*fig).returnPoints();
            int result = checkPointInside(points[0]) * checkPointInside(points[1]) * checkPointInside(points[2]);
            result *= (*fig).checkPointInside(Point0) * (*fig).checkPointInside(Point1) * (*fig).checkPointInside(Point2);
            return result;
        }
        if (figureType == 3) //Circle
        {
            return (*fig).checkPointInside(Point0) * (*fig).checkPointInside(Point1) * (*fig).checkPointInside(Point2);
        }
        return -1;
    }


    // CIRCLE ////////////////////////////////////////////////////////////////////


    Circle::Circle(struct point center, double r)
    {
        Point0.X = center.X;
        Point0.Y = center.Y;
        R = r;
    }

    double Circle::areaCount()
    {
        return 3.14 * R * R;
    }


    double Circle::perimeterCount()
    {
        return 2 * 3.14 * R;
    }


    void Circle::getPoints()
    {
        std::cout << "(" << Point0.X << ", " << Point0.Y << ")   R = " << R << "\n";
    }

    int Circle::checkPointInside(struct point PointInside)
    {
        if (sqrt((PointInside.X - Point0.X) * (PointInside.X - Point0.X) + (PointInside.Y - Point0.Y) * (PointInside.Y - Point0.Y)) <= R)
            return 1;
        return 0;
    }

    struct point* Circle::returnPoints()
    {
        struct point radius;
        radius.X = R;
        radius.Y = R;
        struct point points[3] = { Point0, radius};
        return points;
    }
    int Circle::checkCrossing(int figureType, Shape* fig)
    {
        if (figureType == 1) //Square
        {
            struct point* points = (*fig).returnPoints();
            return checkPointInside(points[0]) * checkPointInside(points[1]) * checkPointInside(points[2]) * checkPointInside(points[3]);
        }
        if (figureType == 2) //Triangle
        {
            struct point* points = (*fig).returnPoints();
            return checkPointInside(points[0]) * checkPointInside(points[1]) * checkPointInside(points[2]);
        }
        if (figureType == 3) //Circle
        {
            struct point* points = (*fig).returnPoints();
            double length = points[1].X + R;
            if (length < 0)
                length *= -1;
            double centerLength = sqrt((Point0.X - points[0].X) * (Point0.X - points[0].X) + (Point0.Y - points[0].Y) * (Point0.Y - points[0].Y));

            if (centerLength < length)
                return 1;
            return 0;
        }
        return -1;
    }

}