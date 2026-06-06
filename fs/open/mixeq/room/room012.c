inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "north" : __DIR__"room010",
  "south" : __DIR__"room01a",  
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
