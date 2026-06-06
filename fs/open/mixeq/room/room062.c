inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "south" : __DIR__"room061",
]));
  set("new_exits",([
  "west" : __DIR__"room063",
]));

}
void reset()
{
  old_reset();
}
