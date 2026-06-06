inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"room083",
]));
  set("new_exits",([
  "west" : __DIR__"room085",
]));

}
void reset()
{
  old_reset();
}
