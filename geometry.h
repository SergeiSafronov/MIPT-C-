#include <iostream>

namespace myGeometry {

    struct point
    {
        double X, Y;
    };

    class Shape
    {
    public:
        virtual double            areaCount() = 0;
        virtual double            perimeterCount() = 0;
        virtual void              getPoints() = 0;
        virtual int               checkPointInside(struct point Point) = 0;
        virtual struct point *    returnPoints() = 0;
        virtual int               checkCrossing(int figureType, Shape *fig) = 0;
    };

    class Square : public Shape
    {
    private:
        struct point Point0; //left  up
        struct point Point1; //left  down
        struct point Point2; //right down
        struct point Point3; //right up
    public:
        Square(struct point X, struct point Y);
        virtual double areaCount();
        virtual double perimeterCount();
        virtual void   getPoints();
        virtual int    checkPointInside(struct point Point); //0 - not inside. 1 - inside
        virtual struct point* returnPoints();
        virtual int    checkCrossing(int figureType, Shape* fig);
    };
    //                                         Square()                                       //
    //�� ���� ������ ����� �� ��������� ��������. �� ��� ����� ���������� ��� ����� ��������
    //���� ����� ����������� ����� ������� (�� �� ��������� ��� �� �������, � �������������), 
    //�� ������ ����� �������������� ������������� (���� ����� ����������, �� ��������� �����
    //����������, �������� 4 ����������, � ���� ����� ����� �������� ������ ���� ������� ����.
    //���� ���� �� ��������� � ����� �������, ����� ������ ��������� �������


    class Triangle : public Shape
    {
    private:
        struct point Point0; //up
        struct point Point1; //left  down
        struct point Point2; //right down
    public:
        Triangle(struct point up, struct point lDown, struct point rDown);
        virtual double areaCount();
        virtual double perimeterCount();
        virtual void   getPoints();
        virtual int    checkPointInside(struct point Point); //0 - not inside. 1 - inside
        virtual struct point* returnPoints();
        virtual int    checkCrossing(int figureType, Shape* fig);
    };
    //                                         Triangle()                                       //
    //�� ���� ������ �����: �������, ������ �����, ������ ������.
    //���� ����� ����������� ������, �� ����� �������������� �������������
    //���� ������� ��� ����� � ���������� ������� ��������� - ������ ���������
    //�� ��������������, ��� ������ ����� ������������ �� ����� ������. �� ��������.
    //� �����, �������� ��� ����� ������, �� ����� ��������� �������




    class Circle : public Shape
    {
    private:
        struct point Point0; //up
        double R;
    public:
        Circle(struct point center, double r);
        virtual double areaCount();
        virtual double perimeterCount();
        virtual void   getPoints();
        virtual int    checkPointInside(struct point Point); //0 - not inside. 1 - inside
        virtual struct point* returnPoints();
        virtual int    checkCrossing(int figureType, Shape* fig);
    };


}