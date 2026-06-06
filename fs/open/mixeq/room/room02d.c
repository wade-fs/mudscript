inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "west" : __DIR__"room02c",
]));
  set("new_exits",([
  "east" : __DIR__"room02e",
]));

}
void reset()
{
  old_reset();
}
