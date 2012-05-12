/*
 * wxTimeline.h
 *
 *  Created on: Oct 18, 2011
 *      Author: raphael
 */

#ifndef WXTIMELINE_H_
#define WXTIMELINE_H_
#include "wx/wx.h"
#include <vector>

class wxTimeline;

//class wxTimelineChild: public wxControl
class TimelineValue{

private:
  double value;
  double time;
public:
    TimelineValue() {}
    TimelineValue(double time, double value);
    double getTime() const;
    double getValue() const;
    void setTime(double time);
    void setValue(double value);
};

class wxTimelinePoint: public wxControl {
	TimelineValue value;
	int zoomY;
	int zoomX;
	wxTimeline* parent;
public:
	DECLARE_DYNAMIC_CLASS(wxTimelinePoint);
	wxTimelinePoint () {}
	wxTimelinePoint(wxControl* parent, wxWindowID id) : wxControl (parent, id) {zoomX = 100; zoomY = 100; this->parent = (wxTimeline*)parent;}
	void OnPaint(wxPaintEvent& event);
    int getZoomX() const;
    int getZoomY() const;
    void setZoomX(int zoomX);
    void setZoomY(int zoomY);
    TimelineValue getValue() const;
    void setValue(TimelineValue value);
    wxTimeline *getParent() const;
    void setParent(wxTimeline *parent);

	DECLARE_EVENT_TABLE();
};

class wxTimeline : public wxControl{
   int spacerX;
   int spacerY;
   int zoomX;
   int zoomY;

   float maxZoomX;

   std::vector<wxTimelinePoint*> points;

public:
	DECLARE_DYNAMIC_CLASS(wxTimeline);
	wxTimeline () {maxZoomX = 700.0;};
	wxTimeline (wxWindow* parent, wxWindowID id, const wxString& txt)
		: wxControl (parent, id) { spacerX = 20; zoomX = 100; spacerY = 20; zoomY = 100; points.clear();}
	void OnPaint(wxPaintEvent& event);
	void OnResize(wxSizeEvent& event);
	void OnLeftClick(wxMouseEvent& event);
	void OnLeftDblClick(wxMouseEvent& event);
	void OnMouseMove(wxMouseEvent& event);
	void UpdateScrollbars(wxScrollWinEvent& event);

	void drawMousePosLine(int posX, int posY);
    int getSpacerX() const;
    int getSpacerY() const;
    int getZoomX() const;
    int getZoomY() const;
    void setSpacerX(int spacerX);
    void setSpacerY(int spacerY);
    void setZoomX(int zoomX);
    void setZoomY(int zoomY);
//
    TimelineValue translatePosition(int posX, int posY);
    wxPoint translateValueIntoPosition(TimelineValue value);
	DECLARE_EVENT_TABLE();
};

#endif /* WXTIMELINE_H_ */
