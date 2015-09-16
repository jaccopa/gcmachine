#ifndef TARGETAREA_H
#define TARGETAREA_H


#include "log.h"
#include <QSize>
#include <QPoint>
#include <QRect>

class targetArea:public Singleton<targetArea>
{
public:
    //void drawTargetHLine();
    void setTargetHLine(int,int,int,int);
    void setTargetHLine(int,int);
    void setOffsetOfHLine(int);
    QPoint  getTargetHLinePoint1() const;
    QPoint  getTargetHLinePoint2() const;

    //int  getTargetHLinePoint() const;

    //void drawTargetVLine();
    void setTargetVLine(int,int,int,int);
    void setTargetVLine(int,int);
    void setOffsetOfVLine(int);
    QPoint  getTargetVLinePoint1() const;
    QPoint  getTargetVLinePoint2() const;

    //void drawTargetRect();
    void setTargetRect(int,int,int,int);
    void setTargetRect(int,int);
    QRect getTargetRect() const;
    QSize getTargetRectSize() const;

    void setPaletteSize(int,int);
    int  getPaletteSizeX() const;
    int  getPaletteSizeY() const;
    QSize getPaletteSize() const;

    //void drawElipse();
    //void drawSRect();

private:
    targetArea();
    ~targetArea();
    friend class Singleton<targetArea>;

    int targetHLineX1;
    int targetHLineY1;
    int targetHLineX2;
    int targetHLineY2;

    int targetVLineX1;
    int targetVLineY1;
    int targetVLineX2;
    int targetVLineY2;

    int targetRectX;
    int targetRectY;
    int targetRectWidth;
    int targetRectHeight;

    int paletteSizeX;
    int paletteSizeY;

    int offsetVLine;
    int offsetHLine;

};

#endif // TARGETAREA_H
