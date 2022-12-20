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
    //На вход даются точки по диагонали квадрата. По ним можно определить все точки квадрата
    //Если точка некорректно задаёт квадрат (не по диагонали или не квадрат, а прямоугольник), 
    //то вторая точка корректируется автоматически (если точки перепутаны, то автоматом смена
    //фактически, вводятся 4 координаты, а сами точки имеют значение только если введены прав.
    //если одна из координат у точек совпадёт, будет создан единичный квадрат


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
    //На вход даются точки: верхняя, нижняя левая, нижняя правая.
    //Если точки некорректно поданы, то будут переопределены автоматически
    //Если наверху две точки с одинаковым уровнем вертикали - ничего страшного
    //Не предполагается, что нижние точки треугольника на одном уровне. Всё свободно.
    //В общем, работает при любых входах, но лучше нормально сделать




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