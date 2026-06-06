inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "west" : __DIR__"room01c",
]));
  set("new_exits",([
  "east" : __DIR__"room020",
]));

}
void reset()
{
  old_reset();
}
