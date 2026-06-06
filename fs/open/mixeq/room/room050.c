inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"room04f",
]));
  set("new_exits",([
  "west" : __DIR__"room054",
  "south" : __DIR__"room051",
]));

}
void reset()
{
  old_reset();
}
