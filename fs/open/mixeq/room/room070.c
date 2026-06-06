inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "south" : __DIR__"room06f",
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
