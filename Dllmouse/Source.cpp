#include <windows.h>
#include "pch.h"
#include <winuser.h>

// Function to be exported from the DLL
extern "C" __declspec(dllexport) const char* GetCurrentCursorType()
{
    // Get the current cursor information
    CURSORINFO ci;
    ci.cbSize = sizeof(CURSORINFO);
    if (!GetCursorInfo(&ci)) {
        // Return "Unknown" if GetCursorInfo fails
        return "Unknown";
    }

    // Check if the cursor is visible
    if (!ci.flags) {
        // Return "Unknown" if the cursor is not visible
        return "Unknown";
    }

    // Define the cursor types
    static const char* cursorTypes[] = {
        "Arrow", "I-beam", "Wait", "Cross", "Up Arrow", "Size", "Icon",
        "Size NWSE", "Size NESW", "Size WE", "Size NS", "Size All",
        "No", "Hand", "App Starting", "Help", "Unknown"
    };

    // Map the cursor handle to its type
    // This is a simplified example; you might need to adjust the logic based on your specific needs
    if (ci.hCursor == LoadCursor(NULL, MAKEINTRESOURCE(IDC_ARROW))) return cursorTypes[0];
    if (ci.hCursor == LoadCursor(NULL, MAKEINTRESOURCE(IDC_IBEAM))) return cursorTypes[1];
    if (ci.hCursor == LoadCursor(NULL, MAKEINTRESOURCE(IDC_WAIT))) return cursorTypes[2];
    if (ci.hCursor == LoadCursor(NULL, MAKEINTRESOURCE(IDC_CROSS))) return cursorTypes[3];
    if (ci.hCursor == LoadCursor(NULL, MAKEINTRESOURCE(IDC_UPARROW))) return cursorTypes[4];
    if (ci.hCursor == LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZE))) return cursorTypes[5];
    if (ci.hCursor == LoadCursor(NULL, MAKEINTRESOURCE(IDC_ICON))) return cursorTypes[6];
    if (ci.hCursor == LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZENWSE))) return cursorTypes[7];
    if (ci.hCursor == LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZENESW))) return cursorTypes[8];
    if (ci.hCursor == LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZEWE))) return cursorTypes[9];
    if (ci.hCursor == LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZENS))) return cursorTypes[10];
    if (ci.hCursor == LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZEALL))) return cursorTypes[11];
    if (ci.hCursor == LoadCursor(NULL, MAKEINTRESOURCE(IDC_NO))) return cursorTypes[12];
    if (ci.hCursor == LoadCursor(NULL, MAKEINTRESOURCE(IDC_HAND))) return cursorTypes[13];
    if (ci.hCursor == LoadCursor(NULL, MAKEINTRESOURCE(IDC_APPSTARTING))) return cursorTypes[14];
    if (ci.hCursor == LoadCursor(NULL, MAKEINTRESOURCE(IDC_HELP))) return cursorTypes[15];

    // Return "Unknown" if the cursor type is not recognized
    return cursorTypes[16];
}
