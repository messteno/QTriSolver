#ifndef Q3POINTCONNECTION_H
#define Q3POINTCONNECTION_H

#include "q3sceletonitem.h"
#include "q3point.h"

class Q3PointConnection : public Q3SceletonItem
{
private:
    Q3Point *a_;
    Q3Point *b_;

public:
    Q3PointConnection(Q3Point *a, Q3Point *b);
    virtual ~Q3PointConnection();

    virtual void draw(Q3Painter &painter);
    virtual qreal distanceTo(const QPointF &pos) const;
    virtual qreal distanceFromBoundaryTo(const QPointF &pos) const;
    virtual QRectF boundingRect() const;
    virtual void move(const QPointF diff);

    void setA(Q3Point *a);
    void setB(Q3Point *b);

    Q3Point* a();
    Q3Point* b();

};

#endif // Q3POINTCONNECTION_H
