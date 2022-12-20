#include "geometry.h"

/*
(75Б) Создайте проект, содержащий 3 класса, описывающих геометрические фигуры 
в двумерном пространстве: квадрат, круг и треугольник. Реализуйте объявление 
и определение в .h и .cpp файлах. Реализуйте методы расчета площади и периметра 
для этих фигур. Реализуйте методы, возвращающие вектор вершин фигуры в порядке, 
соответствующем правой ориентации (точки следует объявить, как структуру или 
класс) для квадрата и треугольника. Реализуйте методы проверяющие, лежит ли 
предложенная точка внутри фигуры. Классы расположите в собственном пространстве 
имен.
*/

//Правая ориентация - это по часовой стрелке?..


using namespace myGeometry;

void testSquare()
{
    //Square
    struct point PointUp, PointDown;

    PointUp.X = 0.4; PointUp.Y = 5.31;
    PointDown.X = 11; PointDown.Y = 0.1;

    struct point pIn, pOut;

    pIn.X = 0.5; pIn.Y = 5.3;
    pOut.X = 13; pOut.Y = 0.2;

    Square sq(PointUp, PointDown);

    std::cout << sq.areaCount() << "\n" << sq.perimeterCount() << "\n";
    std::cout << sq.checkPointInside(pIn) << "\n";
    std::cout << sq.checkPointInside(pOut) << "\n";

    sq.getPoints();
}

void testTriangle()
{
    //Triangle
    struct point PointUp, PointDown, PointDown1;

    PointUp.X = 0; PointUp.Y = 5.31;
    PointDown.X = 11; PointDown.Y = 0.1;
    PointDown1.X = 8; PointDown1.Y = 16;

    struct point pIn, pOut;

    pIn.X = 1; pIn.Y = 5.5;
    pOut.X = 22; pOut.Y = 100.19;

    Triangle tr(PointUp, PointDown, PointDown1);

    std::cout << tr.areaCount() << "\n" << tr.perimeterCount() << "\n";
    std::cout << tr.checkPointInside(pIn) << "\n";
    std::cout << tr.checkPointInside(pOut) << "\n";

    tr.getPoints();
}

void testCircle()
{
    //Circle
    struct point PointCenter;

    PointCenter.X = -8; PointCenter.Y = 5.31;
    double r = 9.78;

    struct point pIn, pOut;

    pIn.X = -7; pIn.Y = 5.5;
    pOut.X = 22; pOut.Y = 100.19;

    Circle cr(PointCenter, r);

    std::cout << cr.areaCount() << "\n" << cr.perimeterCount() << "\n";
    std::cout << cr.checkPointInside(pIn) << "\n";
    std::cout << cr.checkPointInside(pOut) << "\n";

    cr.getPoints();
}

void CheckCrossingFigs()
{
    struct point PointCenter;
    PointCenter.X = -8; PointCenter.Y = 5.31;
    double r = 9.78;
    Circle cr(PointCenter, r);

    struct point PointCenterNew;
    PointCenterNew.X = 0; PointCenterNew.Y = 0;
    r = 500;
    Circle cr1(PointCenterNew, r);

    struct point PointUp, PointDown, PointDown1;
    PointUp.X = 0; PointUp.Y = 5.31;
    PointDown.X = 11; PointDown.Y = 0.1;
    PointDown1.X = 8; PointDown1.Y = 16;
    Triangle tr(PointUp, PointDown, PointDown1);

    struct point PointUpS, PointDownS;
    PointUpS.X = 0.4; PointUpS.Y = 5.31;
    PointDownS.X = 11; PointDownS.Y = 0.1;
    Square sq(PointUpS, PointDownS);


    std::cout << cr.checkCrossing(1, &sq) << "\n";
    std::cout << cr.checkCrossing(2, &tr) << "\n";
    std::cout << cr.checkCrossing(3, &cr1) << "\n";
    std::cout << tr.checkCrossing(1, &sq) << "\n";
    std::cout << tr.checkCrossing(3, &cr) << "\n";
    std::cout << tr.checkCrossing(3, &cr1) << "\n";
    std::cout << sq.checkCrossing(1, &sq) << "\n";
    std::cout << sq.checkCrossing(3, &cr) << "\n";
    std::cout << sq.checkCrossing(3, &cr1) << "\n";
}

int main()
{
    testSquare();
    std::cout << "\n\n\n";
    testTriangle();
    std::cout << "\n\n\n";
    testCircle();
    std::cout << "\n\n\n";
    CheckCrossingFigs();
}