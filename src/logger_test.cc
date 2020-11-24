#include "recv_event_logger.h"
#include <stdlib.h>
#include <unistd.h>

int main() {
    auto logger = RecvEventLogger("Test Logger", "./test.log");
    for (int i=0; i<100; i++) {
        logger.LogEvent(true, false, true, 123456789098766, 12, 24);
    }
    sleep(4);
    return 0;
}
