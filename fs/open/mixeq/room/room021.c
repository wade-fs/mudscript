inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "west" : __DIR__"room020",
]));
  set("new_exits",([
//  "west" : __DIR__"room009",
]));

}
void reset()
{
  old_reset();
}
