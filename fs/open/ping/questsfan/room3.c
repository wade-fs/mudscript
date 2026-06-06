// Room: /u/d/dhk/questsfan/room3
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", ""CYN"密道"NOR"");
  set ("long", @LONG
走著走著四周忽然閃過些許光芒，原本是一些掉落的
珠寶，但是你已無心貪此物了。你越走越納悶，已經走了
許久但還是不見出口。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room4",
  "east" : __DIR__"room2",
]));
set("no_transmit", 1);
  setup();
}
int valid_leave(object who,string dir)
{
  if(dir=="north")
    who->add_temp("go_north",1);
  if(dir=="north" && query("exits/north")==__DIR__"room5.c")
  {
    set("exits/north",__DIR__"room4");
    who->delete_temp("go_north");
  }
  return :: valid_leave(who,dir);
}
void init()
{
  object me=this_player();

  if(me->query_temp("go_north")>=9)
  {
    set("exits/north",__DIR__"room5.c");
  }
}
