inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "west" : __DIR__"room045",
]));
  set("new_exits",([
  "south" : __DIR__"room047",
]));

}
void reset()
{
  old_reset();
}
