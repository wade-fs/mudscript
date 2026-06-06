inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "north" : __DIR__"room003",
]));
  set("new_exits",([
  "south" : __DIR__"room007",
]));

}
void reset()
{
  old_reset();
}
