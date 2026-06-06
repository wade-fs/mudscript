inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "northeast" : __DIR__"room033",
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
