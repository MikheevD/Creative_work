#include "vertex.h"
#include "edge.h"
#include "graph.h"

#include <QVector>

Vertex::Vertex(Graph *graph, int index) : graph(graph){
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);
    vertexIndex = index;
    degree = 0;
    color = "white";
    name = "";
}

Vertex::~Vertex(){
    clearEdge();
    degree = 0;
}

QString Vertex::getVertexColor(){
    return this -> color;
}

void Vertex::setColor(QString color){
    this -> color = color;
    qApp->processEvents();
    update();
}

QString Vertex::getVertexName(){
    return name;
}

void Vertex::setVertexName(QString name){
    this -> name = name;
}

void Vertex::addEdge(Edge *edge){
    edgeList << edge;
    edge -> adjust();
    degree ++;
}

QVector<Edge *> Vertex::getEdges() const{
    return edgeList;
}

void Vertex::calculate(){
    if(!scene() || scene()->mouseGrabberItem() == this){
        newPos = pos();
        return;
    }

    qreal xvel = 0;
    qreal yvel = 0;
    const QList<QGraphicsItem *> items = scene()->items();
    for(QGraphicsItem *item : items){
        Vertex *temp = qgraphicsitem_cast<Vertex *>(item);
        if(!temp){
            continue;
        }
        QPointF vec = mapToItem(temp, 0, 0);
        qreal dx = vec.x();
        qreal dy = vec.y();
        double l = 4.0 * (dx * dx + dy * dy);
        if(l > 0 && l < 800){
            xvel += (dx * 200.0) / l;
            yvel += (dy * 200.0) / l;
        }
    }
    if(qAbs(xvel) < 0.5 && qAbs(yvel) < 0.5){
        xvel = yvel = 0;
    }

    QRectF sceneRect = scene()->sceneRect();
    newPos = pos() + QPointF(xvel, yvel);
    newPos.setX(qMin(qMax(newPos.x(), sceneRect.left() + 20), sceneRect.right() - 20));
    newPos.setY(qMin(qMax(newPos.y(), sceneRect.top() + 290), sceneRect.bottom() - 20));
}


bool Vertex::preliminaryPosition(){
    if(newPos == pos()){
        return false;
    }
    setPos(newPos);
    return true;
}

int Vertex::getVertexDegree(){
    return degree;
}

int Vertex::getVertexIndex(){
    return vertexIndex;
}

void Vertex::setVertexIndex(int index){
    vertexIndex = index;
    qApp->processEvents();
    update();
}

bool Vertex::pathExist(int dest){
    for(Edge *temp : edgeList){
        if(temp -> destVertex() -> getVertexIndex() == dest){
            return true;
        }
    }
    return false;
}

int Vertex::getEdge(int dest)
{
    for(Edge *temp : edgeList){
        if(temp -> destVertex() -> getVertexIndex() == dest){
            return temp->getWeightofEdge();
        }
    }
    return -1;
}

void Vertex::setVertexPosition(double xvel, double yvel){
    QRectF sceneRect = scene()->sceneRect();
    newPos = pos() + QPointF(xvel, yvel);
    newPos.setX(qMin(qMax(newPos.x(), sceneRect.left() + 15), sceneRect.right() - 15));
    newPos.setY(qMin(qMax(newPos.y(), sceneRect.top() + 160), sceneRect.bottom() - 15));
}

void Vertex::insertEdge(int dest, double weight){
    const QList<QGraphicsItem *> items = scene()->items();
    for(QGraphicsItem *item : items){
        Vertex *temp = qgraphicsitem_cast<Vertex *>(item);
        if(!temp){
            continue;
        }
        if(temp->getVertexIndex() == dest){
            Edge *edge = new Edge(this, temp, weight);
            edgeList.append(edge);
            return;
        }
    }
}

void Vertex::updateEdgeWeight(int dest, double weight){
    for(Edge *temp : edgeList){
        if(temp -> destVertex() -> getVertexIndex() == dest){
            temp -> setWeightofEdge(weight);
        }
    }
}

void Vertex::eraseEdge(int dest){
    if(!pathExist(dest)){
        return;
    }
    for(int i{0}; i < edgeList.size(); i++){
        if(edgeList[i] -> destVertex() -> getVertexIndex() == dest){
            edgeList.erase(edgeList.begin() + i);
        }
    }
    degree --;
}


void Vertex::clearEdge(){
    edgeList.clear();
    degree = 0;
}

void Vertex::changeEdgeColor(int dest){
    for(Edge *edge : edgeList){
        if(edge->destVertex()->getVertexIndex() == dest){
            edge->setColor("black");
        }
    }
}

QPointF Vertex::getPos(){
    return newPos;
}

QRectF Vertex::boundingRect() const{
    qreal adjust = 4;
    return QRectF(-15 - adjust, -15 - adjust, 56 + adjust, 56 + adjust);
}

QPainterPath Vertex::shape() const{
    QPainterPath path;
    path.addEllipse(-15, -15, 50, 50);
    return path;
}

void Vertex::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *){

    painter->setPen(Qt::NoPen);
    painter->drawEllipse(0, 0, 50, 50);

    QRadialGradient gradient(-9, -9, 20);
    if (option->state & QStyle::State_Sunken) {
        gradient.setCenter(50, 50);
        gradient.setFocalPoint(50, 50);

        if (this -> color == "white"){
            gradient.setColorAt(1, QColor(Qt::blue).lighter(140));
            gradient.setColorAt(0, QColor(Qt::blue).lighter(140));
        }
        else if (this -> color == "gray"){
            gradient.setColorAt(1, QColor(Qt::yellow).lighter(140));
            gradient.setColorAt(0, QColor(Qt::darkYellow).lighter(140));
        }
        else if (this -> color == "black"){
            gradient.setColorAt(1, QColor("orange").lighter(140));
            gradient.setColorAt(0, QColor("darkorange").lighter(140));
        }
        else if (this -> color == "green"){
            gradient.setColorAt(1, QColor(Qt::green).lighter(140));
            gradient.setColorAt(0, QColor(Qt::green).lighter(140));
        }

    } else {
        if (this -> color == "white"){
            gradient.setColorAt(0, QColor(Qt::blue).lighter(140));
            gradient.setColorAt(1, QColor(Qt::blue).lighter(140));
        }
        else if (this -> color == "gray"){
            gradient.setColorAt(0, QColor(Qt::yellow).lighter(140));
            gradient.setColorAt(1, QColor(Qt::darkYellow).lighter(140));
        }
        else if (this -> color == "black"){
            gradient.setColorAt(0, QColor("orange").lighter(140));
            gradient.setColorAt(1, QColor("darkorange").lighter(140));
        }
        else if (this -> color == "green"){
            gradient.setColorAt(1, QColor(Qt::green).lighter(140));
            gradient.setColorAt(0, QColor(Qt::green).lighter(140));
        }
    }
    painter->setBrush(gradient);
    painter->setPen(QPen(Qt::black, 0));
    painter->drawEllipse(-20, -20, 50, 50);
    QString index = QString::number(vertexIndex);
    painter->drawText(QRect(-20, -20, 50, 50), Qt::AlignCenter, index);
}


QVariant Vertex::itemChange(GraphicsItemChange change, const QVariant &value){
    switch(change){
        case ItemPositionHasChanged:
            for(Edge *edge : qAsConst(edgeList)){
                graph->itemMoved();
                edge->adjust();
                for(Edge *reverseEdge : edge->destVertex()->getEdges()){
                    reverseEdge->adjust();
                }
            }
            graph->itemMoved();
            break;
        default:
            break;
    };
    return QGraphicsItem::itemChange(change, value);
}


void Vertex::mousePressEvent(QGraphicsSceneMouseEvent *event){
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Vertex::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
