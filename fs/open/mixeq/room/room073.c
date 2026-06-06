inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "south" : __DIR__"room072",
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
