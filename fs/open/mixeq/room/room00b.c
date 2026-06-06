inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "south" : __DIR__"seroom1",
  "north" : __DIR__"room00B",  
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
