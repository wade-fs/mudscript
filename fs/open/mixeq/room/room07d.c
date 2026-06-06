inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"room07b",
]));
  set("new_exits",([
  "west" : __DIR__"room07e",
]));

}
void reset()
{
  old_reset();
}
