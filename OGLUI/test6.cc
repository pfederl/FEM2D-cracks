#include <cstdlib>
#include <cstdio>
#include <memory>
#include <UIWidget.h>
#include <WindowWidget.h>
#include <BevelWidget.h>
#include <SmartLayoutManager.h>
#include <PushButtonWidget.h>

OGLUI_USE_NAMESPACE

static int real_main (int & argc, char ** & argv)
{
	// initialize the user interface library
	UI * ui = new UI (argc, argv);
	// create a new window
	WindowWidget * win = new WindowWidget (ui);
	win -> setPrefSize (Size (500, 500));
	win -> setBgColor (Color::DarkGreen);
	win -> setDisplayMode (GLUT_RGB | GLUT_DOUBLE);
	// create a layout manager
	SmartLayoutManager::Pointer lm = 
		win -> setLayoutManager (new SmartLayoutManager ());
	// create a status bar
	LabelWidget * pb = new LabelWidget (win);
	pb -> setLabel ("Status");
	pb -> setBevelSize (5);
	pb -> setPrefSize (Size (100, 30));
	pb -> setBgColor (Color::Red);
	// specify attachments
	lm -> attach (SLM::TopEdge (pb), SLM::Relative (100, 0));
	lm -> attach (SLM::BottomEdge (pb), SLM::None ());
	lm -> attach (SLM::LeftEdge (pb), SLM::Relative (0,0));
	lm -> attach (SLM::RightEdge (pb), SLM::Relative (100, 0));
	
	// run the application
	ui-> run ();

	return 0;
}

int main (int argc, char ** argv)
{
	try
	{
		real_main (argc, argv);
	}
	catch (...)
	{
	}
}
