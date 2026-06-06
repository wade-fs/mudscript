inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "north" : __DIR__"room051",
]));
  set("new_exits",([
  "south" : __DIR__"room053",
]));

}
void reset()
{
  old_reset();
}
