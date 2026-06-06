inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "south" : __DIR__"room011",
  "east" : __DIR__"room014",  
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
