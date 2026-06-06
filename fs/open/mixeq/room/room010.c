inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "west" : __DIR__"room00f",
  "north" : __DIR__"room011",
  "south" : __DIR__"room012",  
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
