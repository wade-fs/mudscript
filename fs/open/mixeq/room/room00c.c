inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "south" : __DIR__"room00b",
  "east"  : __DIR__"room00d",  
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
