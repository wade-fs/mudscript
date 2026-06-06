inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "west" : __DIR__"room022",
  "northeast" : __DIR__"room024",
  
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
