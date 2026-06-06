inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "southeast" : __DIR__"room02f",
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
