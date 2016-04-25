#ifndef _JULIA_SERVER_H_
#define _JULIA_SERVER_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_CONCURRENT_NUM  (65536)
#define MAX_EVENT_NUM   (256)
#define RECV_BUF_SIZE   (4 * 1024)
#define SEND_BUF_SIZE   (4 * 1024)
#define EVENTS_IN   (EPOLLIN | EPOLLET)
#define EVENTS_OUT  (EPOLLOUT | EPOLLET)

#define EXIT_ON(cond, msg)  if ((cond)) { perror((msg)); exit(EXIT_FAILURE); };

enum {
    JU_ERR_UNEXPECTED_EOF,
    
};

#endif
