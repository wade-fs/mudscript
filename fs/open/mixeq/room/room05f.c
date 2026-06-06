inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"room05e",
  "west" : __DIR__"room060",
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
