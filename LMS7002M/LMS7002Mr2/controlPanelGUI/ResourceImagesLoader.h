// -----------------------------------------------------------------------------
// FILE: 		ResourceImagesLoader.h
// DESCRIPTION:
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#ifndef RESOURCE_IMAGES_LOADER_H
#define RESOURCE_IMAGES_LOADER_H

#include <wx/splash.h>
#include <wx/mstream.h>
#include <wx/icon.h>

#ifndef LINUX
#include <windows.h>
wxBitmap* GetBitmapFromMemory(const char* t_data, const unsigned long t_size);
bool LoadDataFromResource(char*& t_data, unsigned long& t_dataSize, const wxString& t_name);
wxBitmap* CreateBitmapFromPngResource(const wxString& t_name);
#endif

#endif // RESOURCE_IMAGES_LOADER_H

