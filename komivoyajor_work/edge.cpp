#include "vertex.h"
#include "edge.h"
#include "graph.h"

#include <QtMath>


#define PI 3.1415926



Edge::Edge(Vertex *source, Vertex *dest, double weight){
    this->source = source;
    this->dest = dest;
    setAcceptedMouseButtons(Qt::NoButton);
    source->addEdge(this);
    this->weight = weight;
    color = "white";
    adjust();
}

Edge::~Edge(){

}

Vertex *Edge::sourceVertex() const{
    return source;
}

Vertex *Edge::destVertex() const{
    return dest;
}

void Edge::adjust(){
    if(!source || !dest){
        return;
    }
    QLineF line(mapFromItem(source, 0, 0), mapFromItem(dest, 0, 0));
    qreal length = line.length();
    prepareGeometryChange();

    if(length > qreal(20.)){
        QPointF edgeOffset((line.dx() * 21) / length, (line.dy() * 21) / length);
        sourcePoint = line.p1() + edgeOffset;
        destPoint = line.p2() - edgeOffset;
    } else {
        sourcePoint = destPoint = line.p1();
    }
}

QRectF Edge::boundingRect() const{
    if(!source || !dest){
        return QRectF();
    }
    qreal penWidth = 1;
    qreal extra = (penWidth + arrowSize) / 2.5;
    return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(), destPoint.y() - sourcePoint.y())).normalized().adjusted(-extra, -extra, extra, extra);
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    if(!source || !dest){
        return;
    }
    QLineF line(sourcePoint, destPoint);
    if(qFuzzyCompare(line.length(), qreal(0.4))){
        return;
    }

    double angle = std::atan2(-line.dy(), line.dx());
    QPointF destArrowP1 = destPoint + QPointF(sin(angle - PI / 4) * arrowSize, cos(angle - PI / 4) * arrowSize);
    QPointF destArrowP2 = destPoint + QPointF(sin(angle - PI + PI / 4) * arrowSize, cos(angle - PI + PI / 4) * arrowSize);


    if(color == "white"){
        painter->setBrush(Qt::black);
        painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    }
    else if(color == "black"){
        painter->setBrush(Qt::green);
        painter->setPen(QPen(Qt::green, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    }
    if(color=="Green")
    {
        painter->setBrush(Qt::green);
        painter->setPen(QPen(Qt::green, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    }
    painter->drawLine(line);
    painter->drawPolygon(QPolygonF() << line.p2() << destArrowP1 << destArrowP2);

    painter->drawText(QRectF(QPointF(sourcePoint.x() - 5, sourcePoint.y() - 5), QPointF(destPoint.x() + 50, destPoint.y() + 50)), Qt::AlignCenter, QString::number(weight));
}

double Edge::getWeightofEdge(){
    return weight;
}

void Edge::setWeightofEdge(double w){
    weight = w;
}

QString Edge::getEdgeColor(){
    return color;
}

void Edge::setColor(QString color){
    this -> color = color;
    qApp->processEvents();
    update();
}
