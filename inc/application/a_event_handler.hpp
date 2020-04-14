#ifndef INC_APPLICATION_EVENT_HANDLER_
#define INC_APPLICATION_EVENT_HANDLER_

#include <iostream>

/// Should contain a function for each event to handle from the main loop
class EventHandler final
{
private:
public:
    static void ClickAtPosition(int clickX, int clickY);
};

#endif // INC_APPLICATION_EVENT_HANDLER_