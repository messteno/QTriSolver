#include <QFile>
#include <QTextStream>
#include <QVector2D>
#include <QVector3D>
#include <float.h>
#include "naturalneigbourinterpolation.h"

NaturalNeigbourInterpolation::NaturalNeigbourInterpolation(
        QVector<QVector3D> &values) :
    Interpolation(values),
    delaunay_(NULL),
    interpolator_(NULL)
{
    points_.clear();

    for (int i = 0; i < values_.size(); ++i)
    {
        point a;
        a.x = values_[i].x();
        a.y = values_[i].y();
        a.z = values_[i].z();
        points_.append(a);
    }

    delaunay_ = delaunay_build(points_.size(), points_.data(), 0, NULL, 0, NULL);
    interpolator_ = nnpi_create(delaunay_);
    nnpi_setwmin(interpolator_, -DBL_MAX);
}

NaturalNeigbourInterpolation::~NaturalNeigbourInterpolation()
{
    nnpi_destroy(interpolator_);
    delaunay_destroy(delaunay_);
}

qreal NaturalNeigbourInterpolation::interpolateToPoint(const QPointF &pt)
{
    point pout;
    pout.x = pt.x();
    pout.y = pt.y();
    nnpi_interpolate_point(interpolator_, &pout);
    return pout.z;
}
