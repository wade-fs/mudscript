inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "north" : __DIR__"room014",
  "east" : __DIR__"room016",
  
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
