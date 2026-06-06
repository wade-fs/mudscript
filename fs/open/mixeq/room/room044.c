inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"room043",
]));
  set("new_exits",([
  "south" : __DIR__"room045",
]));

}
void reset()
{
  old_reset();
}
