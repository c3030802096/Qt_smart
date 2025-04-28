#include "my_custom/global.h"


Global::Global()
{

}

int Global::curr_socket = 0;
QMap<int,int> g_socket_map;

int livingroom_status = ERROR;
