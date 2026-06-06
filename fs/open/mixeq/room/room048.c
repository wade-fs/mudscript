inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "north" : __DIR__"room047",
]));
  set("new_exits",([
  "west" : __DIR__"room049",
]));

}
void reset()
{
  old_reset();
}
