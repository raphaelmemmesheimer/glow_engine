/*
 * wxTimeline.cpp
 *
 *  Created on: Oct 18, 2011
 *      Author: raphael
 */

#include "wxTimeline.h"
#include <algorithm>

//TimelinePoint
IMPLEMENT_DYNAMIC_CLASS(wxTimelinePoint,wxControl);

int wxTimelinePoint::getZoomX() const
{
    return zoomX;
}

int wxTimelinePoint::getZoomY() const
{
    return zoomY;
}

void wxTimelinePoint::setZoomX(int zoomX)
{
    this->zoomX = zoomX;
}

void wxTimelinePoint::setZoomY(int zoomY)
{
    this->zoomY = zoomY;
}

TimelineValue wxTimelinePoint::getValue() const
{
    return value;
}

void wxTimelinePoint::setValue(TimelineValue value)
{
    this->value = value;
    this->SetPosition(this->parent->translateValueIntoPosition(value));
}

wxTimeline *wxTimelinePoint::getParent() const
{
    return parent;
}

void wxTimelinePoint::setParent(wxTimeline *parent)
{
    this->parent = parent;
}

/*wxTimelinePoint::wxTimelinePoint(wxTimeline *parent, wxWindowID id)
{
	zoomY = 100;
	zoomX = 100;SetCursor( &wxCursor(wxCROSS_CURSOR));
	this->parent = parent;
	printf("%d \n", parent->getZoomX());
	this->SetId(id);
}*/

BEGIN_EVENT_TABLE(wxTimelinePoint, wxControl)
	EVT_PAINT(wxTimelinePoint::OnPaint)
END_EVENT_TABLE()

/*void wxTimelinePoint::SetPosition(int posX, int posY)
{
  this->posX = posX;
  this->posY = posY;
  Move(posX,posY);
}*/


void wxTimelinePoint::OnPaint(wxPaintEvent& event)
{
  wxPaintDC dc (this);
  dc.SetPen(wxPen(wxColour(255, 0, 0), 2, wxSOLID));
  dc.DrawRectangle(this->GetClientRect());
}


//Timeline
IMPLEMENT_DYNAMIC_CLASS(wxTimeline,wxControl);


BEGIN_EVENT_TABLE(wxTimeline, wxControl)
	EVT_PAINT(wxTimeline::OnPaint)
	EVT_SIZE(wxTimeline::OnResize)
	EVT_LEFT_DOWN(wxTimeline::OnLeftClick)
	EVT_LEFT_DCLICK(wxTimeline::OnLeftDblClick)
	EVT_MOTION(wxTimeline::OnMouseMove)
	EVT_SCROLLWIN(wxTimeline::UpdateScrollbars)
END_EVENT_TABLE()

int wxTimeline::getSpacerX() const
{
    return spacerX;
}

int wxTimeline::getSpacerY() const
{
    return spacerY;
}

int wxTimeline::getZoomX() const
{
    return zoomX;
}

int wxTimeline::getZoomY() const
{
    return zoomY;
}

void wxTimeline::setSpacerX(int spacerX)
{
    this->spacerX = spacerX;
    Refresh();
}

void wxTimeline::setSpacerY(int spacerY)
{
    this->spacerY = spacerY;
    Refresh();
}

void wxTimeline::setZoomX(int zoomX)
{
    this->zoomX = zoomX;
    Refresh();
    for (unsigned int i = 0; i < points.size(); i++) {
        points[i]->setZoomX(zoomX);
    }
}

void wxTimeline::setZoomY(int zoomY)
{
    this->zoomY = zoomY;
    Refresh();
    for (unsigned int i = 0; i < points.size(); i++) {
        points[i]->setZoomY(zoomY);
    }
}

bool sortPoints (wxTimelinePoint* a, wxTimelinePoint* b) {
	return (a->getValue().getTime() > b->getValue().getTime());
}

void wxTimeline::OnPaint(wxPaintEvent& WXUNUSED(event))
{
	wxPaintDC dc (this);
	wxCoord	width = 0, height = 0;
	GetClientSize( &width, &height );

	dc.SetTextForeground (GetForegroundColour ());
	dc.SetTextBackground (GetBackgroundColour ());

	int lineLength = 0;
	//dc.SetBackground(*wxTheBrushList->FindOrCreateBrush(wxColour(255, 255, 255), wxSOLID));
	dc.Clear();
	dc.GradientFillLinear(GetClientRect(),wxColour( 240, 240, 240),wxColour(255, 255, 255), wxDOWN);
	printf("zoom %d \n", zoomX);
    float spacerZoomX = spacerX * (zoomX / 100.0);
    float spacerZoomY = spacerY * (zoomY / 100.0);
	//dc.DrawRectangle( 0, 0, GetSize().x, GetSize().y);

    // draw vertical stuff
 	lineLength = 5;
 	for (unsigned int i = 0; i <= float( GetSize().y / spacerZoomY); i++) {
    	dc.SetPen(wxPen( wxColour( 220, 220, 220), 1, wxSOLID));
    	dc.DrawLine(0, (GetSize().y / 2) - i * spacerZoomY, GetSize().x, (GetSize().y / 2) - i * spacerZoomY);
    	dc.DrawLine(0, (GetSize().y / 2) + i * spacerZoomY, GetSize().x, (GetSize().y / 2) + i * spacerZoomY);
 		dc.SetPen(wxPen( wxColour( 0, 0, 0), 1, wxSOLID));
 		dc.DrawLine(0, (GetSize().y / 2) - i * spacerZoomY, lineLength, (GetSize().y / 2) - i * spacerZoomY);
    	dc.DrawLine(0, (GetSize().y / 2) + i * spacerZoomY, lineLength, (GetSize().y / 2) + i * spacerZoomY);
    }
 	dc.SetPen(wxPen( wxColour( 0, 0, 0), 5, wxSOLID));
 	lineLength = 10;
 	dc.DrawLine(0, GetSize().y / 2, lineLength, GetSize().y / 2);
 	dc.SetPen(wxPen( wxColour( 0, 0, 0), 2, wxSOLID));
 	dc.DrawLine(0, GetSize().y / 2, GetSize().x, GetSize().y / 2);

    // draw horizontal stuff
    if (spacerZoomX <= 0) {
    	printf("wxTimeline spacerZoom <= 0 \n");
    }
    else {
		for(unsigned int i = 1; i <=  float( GetSize().x / spacerZoomX); i++){
			dc.SetPen(wxPen( wxColour( 220, 220, 220), 1, wxSOLID));
			dc.DrawLine(i * spacerZoomX ,0 ,i *spacerZoomX, height);


			if (i % 5 == 0) {
				lineLength = 10;
				dc.SetPen(wxPen( wxColour( 0, 0, 0 ), 3, wxSOLID));
			}
			else {
				lineLength = 5;
				dc.SetPen(wxPen( wxColour( 0, 0, 0 ), 1, wxSOLID));
			}

			dc.DrawLine(i * spacerZoomX ,0 ,i *spacerZoomX, lineLength);
			dc.DrawLine(i * spacerZoomX ,height - lineLength ,i *spacerZoomX, height);
		}
    }


    dc.SetPen(wxPen(wxColour(255, 0, 0), 1, wxSOLID));
    sort(points.begin(), points.end(), sortPoints);
    float zoomX = (spacerZoomX/255.0);
    for (unsigned int k = 1; k < points.size(); k++) {
    	dc.DrawLine((int)points[k-1]->GetPosition().x * zoomX, points[k-1]->GetPosition().y, (int)points[k]->GetPosition().x * zoomX, points[k]->GetPosition().y);
	}
    printf("spacerZoom %d \n", spacerZoomX);
}

void wxTimeline::OnResize(wxSizeEvent& event)
{
    Refresh();
	event.Skip();
}



void wxTimeline::OnLeftClick(wxMouseEvent & event)
{
  this->drawMousePosLine(event.GetX(),event.GetY());
  printf("click %d %d \n",event.GetX(),event.GetY());

}

void wxTimeline::drawMousePosLine(int posX, int posY)
{
	Refresh();
	Update();

	wxPaintDC dc (this);
	dc.SetPen(wxPen( wxColour( 0, 0, 255 ), 2, wxSOLID));
	dc.DrawLine(posX,0,posX,GetSize().y);
	dc.DrawLine(0,posY,GetSize().x,posY);
}

void wxTimeline::OnMouseMove(wxMouseEvent& event)
{
	if (event.LeftIsDown())
		this->drawMousePosLine(event.GetX(),event.GetY());
}

void wxTimeline::UpdateScrollbars(wxScrollWinEvent& event)
{
	if(event.GetOrientation() == wxHORIZONTAL){
	  this->SetScrollbar(wxHORIZONTAL, event.GetPosition(), GetSize().x, 100, true);
	}
	if(event.GetOrientation() == wxVERTICAL){
	  this->SetScrollbar(wxVERTICAL, event.GetPosition(), GetSize().y, 100,true);
	}
}

void wxTimeline::OnLeftDblClick(wxMouseEvent& event)
{
	printf("dblclick %d %d \n",event.GetX(),event.GetY());
	points.push_back(new wxTimelinePoint(this, wxID_ANY));
	//p->SetSize(5,5);
	points[points.size()-1]->SetSize(5, 5);
	points[points.size()-1]->setValue(translatePosition(event.GetX(),event.GetY()));

	Refresh();
}

TimelineValue wxTimeline::translatePosition(int posX, int posY)
{

	double value = ((GetClientSize().GetHeight())/2)- posY;
	//printf("%d %f %d\n",GetClientSize().GetHeight(),value ,posY);
	return TimelineValue(posX, value);
}

wxPoint wxTimeline::translateValueIntoPosition(TimelineValue value)
{
	int posY = (GetClientSize().GetHeight()/2)-value.getValue()*zoomY/100;
	printf("%f %d \n",value.getValue(),posY);
  	return wxPoint(value.getTime(), posY);
}

//TimelineValue

double TimelineValue::getTime() const
{
    return time;
}

double TimelineValue::getValue() const
{
    return value;
}

void TimelineValue::setTime(double time)
{
    this->time = time;
}

void TimelineValue::setValue(double value)
{
    this->value = value;
}

TimelineValue::TimelineValue(double time, double value)
{
	this->time = time;
	this->value = value;
}


