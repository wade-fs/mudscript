inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "northwest" : __DIR__"room01a",
  "east" : __DIR__"room01c",  
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
