#ifndef Q3BOUNDARYFIXEDVELOCITY_H
#define Q3BOUNDARYFIXEDVELOCITY_H

#include "q3boundarytype.h"

namespace Ui {
class Q3BoundaryFixedVelocity;
}

class Q3BoundaryFixedVelocity : public Q3BoundaryType
{
    Q_OBJECT

public:
    explicit Q3BoundaryFixedVelocity(QWidget *parent = 0);
    ~Q3BoundaryFixedVelocity();

    QVector2D velocity(Q3SceletonItem *item,
                       const QPointF &a, const QPointF &b, qreal time);
    void setVelocityText(const QString &vText);

private:
    Ui::Q3BoundaryFixedVelocity *ui;
};

#endif // Q3BOUNDARYFIXEDVELOCITY_H
