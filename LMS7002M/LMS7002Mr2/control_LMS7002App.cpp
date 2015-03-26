/***************************************************************
 * Name:      control_LMS7002App.cpp
 * Purpose:   Code for Application Class
 * Author:    Lime Microsystems
 * Created:   2013-08-12
 * Copyright: Lime Microsystems
 * License:
 **************************************************************/

#include "control_LMS7002App.h"
#include "ResourceImagesLoader.h"
//(*AppHeaders
#include "controlPanelGUI/controlPanel_LMS7002.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(control_LMS7002App);

bool control_LMS7002App::OnInit()
{
    #ifndef LINUX
    wxInitAllImageHandlers();
    wxDisableAsserts();
    wxBitmap *splashImage = CreateBitmapFromPngResource("splashImage");
    wxSplashScreen* splash = new wxSplashScreen( *splashImage,
          wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
          6000, NULL, -1, wxDefaultPosition, wxDefaultSize,
          wxSIMPLE_BORDER|wxSTAY_ON_TOP);

    //wxYield();
    #endif
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	controlPanel_LMS7002* Frame = new controlPanel_LMS7002(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    #ifndef LINUX
    delete splash;
    #endif
    return wxsOK;

}
