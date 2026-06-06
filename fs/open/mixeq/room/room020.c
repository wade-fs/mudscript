inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "west" : __DIR__"room01f",
]));
  set("new_exits",([
  "east" : __DIR__"room021",
]));

}
void reset()
{
  old_reset();
}
