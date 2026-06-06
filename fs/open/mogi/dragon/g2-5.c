
// Room: /u/p/poloer/dragon/g2-5
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "魔王殿二樓");
  set ("long", @LONG

四周一片暗暗的，只能從岩璧上的漏洞，投射一點陽光來看清
東西，不時傳來屍體腐爛的惡臭，聞起來非常的不舒服，前方似乎
有一道門，門前隱約可以看到一個人影在晃動。  　　　　

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/ghostwom.c" : 1,
]));
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"g2-4",
  "enter" : __DIR__"endroom",
]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
}

int valid_leave(object me, string dir)

{
        if(dir=="enter"&&present("ghost",environment(me)))
  {

message_vision(HIW"鬼姥姥說:想進去先過我這關，納命來吧。\n"NOR,me);

return 0;
}
return 1;
}

