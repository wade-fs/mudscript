inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "west" : __DIR__"room017",
]));
  set("new_exits",([
  "east" : __DIR__"room019",
]));

}
void reset()
{
  old_reset();
}
