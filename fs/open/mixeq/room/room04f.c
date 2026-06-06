inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "south" : __DIR__"room04e",
]));
  set("new_exits",([
  "west" : __DIR__"room050",
]));

}
void reset()
{
  old_reset();
}
