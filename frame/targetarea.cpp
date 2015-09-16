#include "targetarea.h"

targetArea::targetArea()
{
}


targetArea::~targetArea()
{
}


void targetArea::setPaletteSize(int width,int height)
{
    this->paletteSizeX = width;
    this->paletteSizeY = height;
}

int targetArea::getPaletteSizeX() const
{
    return this->paletteSizeX;
}

int targetArea::getPaletteSizeY() const
{
    return this->paletteSizeY;
}

QSize targetArea::getPaletteSize() const
{
    QSize palsize(this->paletteSizeX,this->paletteSizeY);
    return palsize;
}

void targetArea::setTargetHLine(int x1,int y1,int x2,int y2)
{
    this->targetHLineX1 = x1;
    this->targetHLineX2 = x2;
    this->targetHLineY1 = y1;
    this->targetHLineY2 = y2;
}

void targetArea::setTargetHLine(int x1,int x2)
{
    this->targetHLineY1 = this->offsetHLine;
    this->targetHLineY2 = this->offsetHLine;
    this->targetHLineX1 = x1;
    this->targetHLineX2 = x2;
}

void targetArea::setOffsetOfHLine(int offset)
{
    this->offsetHLine = offset;
}

QPoint  targetArea::getTargetHLinePoint1() const
{
    QPoint qp(this->targetHLineX1,this->targetHLineY1);
    return qp;
}

QPoint  targetArea::getTargetHLinePoint2() const
{
    QPoint qp(this->targetHLineX2,this->targetHLineY2);
    return qp;
}

void targetArea::setTargetVLine(int x1,int y1,int x2,int y2)
{
    this->targetVLineX1 = x1;
    this->targetVLineX2 = x2;
    this->targetVLineY1 = y1;
    this->targetVLineY2 = y2;
}

void targetArea::setTargetVLine(int y1,int y2)
{
    this->targetVLineY1 = y1;
    this->targetVLineY2 = y2;
    this->targetVLineX1 = this->offsetVLine;
    this->targetVLineX2 = this->offsetVLine;
}

void targetArea::setOffsetOfVLine(int offset)
{
    this->offsetVLine = offset;
}

QPoint  targetArea::getTargetVLinePoint1() const
{
    QPoint qp(this->targetVLineX1,this->targetVLineY1);
    return qp;
}

QPoint  targetArea::getTargetVLinePoint2() const
{
    QPoint qp(this->targetVLineX2,this->targetVLineY2);
    return qp;
}


void targetArea::setTargetRect(int x,int y ,int width,int height)
{
    this->targetRectX = x;
    this->targetRectY = y;
    this->targetRectWidth = width;
    this->targetRectHeight = height;
}

void targetArea::setTargetRect(int x,int y)
{
    this->targetRectX = x;
    this->targetRectY = y;
    this->targetRectWidth = 2 * qAbs(this->targetVLineX1 - this->targetRectX);
    this->targetRectHeight = 2 * qAbs(qAbs(this->targetHLineY1 - this->targetHLineY2) / 2  - this->targetRectY);
}

QPoint targetArea::getTargetRect() const
{
    QPoint qp(this->targetRectX,this->targetRectY);
    return qp;
}

QSize targetArea::getTargetRectSize() const
{
    QSize qs(this->targetRectWidth,this->targetRectHeight);
    return qs;
}










