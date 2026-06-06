inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"room072",
  "west" : __DIR__"room078",
]));
  set("new_exits",([
  "north" : __DIR__"room076",
  "south" : __DIR__"room077",
]));

}
void reset()
{
  old_reset();
}
