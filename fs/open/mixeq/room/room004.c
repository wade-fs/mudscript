inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "south" : __DIR__"room003",
]));
  set("new_exits",([
  "north" : __DIR__"room005",
]));

}
void reset()
{
  old_reset();
}
