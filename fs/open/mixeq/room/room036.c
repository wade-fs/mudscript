inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "northwest" : __DIR__"room035",
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
