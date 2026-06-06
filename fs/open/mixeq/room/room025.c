inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "west" : __DIR__"room024",
  "southeast" : __DIR__"room026",
  
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
