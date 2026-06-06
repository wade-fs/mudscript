// Room: /u/d/dhk/questsfan/rm24
#include <ansi.h>
#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "樹林右翼");
  set ("long", @LONG
這裡是約是嵩山山腰處，往東南走好像會通往〝百草谷〞
，不過那只是傳聞，也不知道是不是真有那地方。此地依舊雲
霧迷濛，氣氛神秘，奇聲隨侍左右。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/man" : 2,
]));
  set("outdoors", "/u/d");
  set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"rm28",
  "northwest" : __DIR__"rm8",
]));

  setup();
}
int valid_leave(object who,string dir)
{
    who=this_player();
        if(dir=="eastdown"&&who->query_temp("stupid")==1)
  {
// tell_object(who,""HIM"谷中仙說道:閣下仙緣已盡，快走吧！"NOR"\n");
        return notify_fail("谷中仙說道:閣下仙緣已盡，快走吧！\n");
        return :: valid_leave(who,dir);
  }
  return :: valid_leave(who,dir);
}

