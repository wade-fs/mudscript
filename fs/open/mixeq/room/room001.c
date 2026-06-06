inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "south" : __DIR__"mixeq_room",
]));
  set("new_exits",([
  "west" : __DIR__"room002",
]));

}
void reset()
{
  old_reset();
}
