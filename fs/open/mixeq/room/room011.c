inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "south" : __DIR__"room010",
  "north" : __DIR__"room013",  
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
