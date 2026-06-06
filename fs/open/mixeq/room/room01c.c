inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "west"  : __DIR__"room01b",
  "south" : __DIR__"room027",
  "north" : __DIR__"room01d",
  
]));
  set("new_exits",([
  "east"  : __DIR__"room01f",
  
]));

}
void reset()
{
  old_reset();
}
