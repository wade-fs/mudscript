inherit ROOM;

#include "room.msg"
string query_long();
void create ()
{
set ("short", "殭屍洞");
set ("long",(: query_long :));
set("no_clean_up",1);

  set("no_transmit", 1);
  set("no_scale",1);

setup();
}

