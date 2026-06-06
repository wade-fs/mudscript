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
  __DIR__"npc/gold-dra" : 1,
]));
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"g2-5",
  "enter" : __DIR__"endroom",
]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
  replace_program(ROOM);
}

int valid_leave(object me, string dir)

{
        if(dir=="enter"&&present("dragon",environment(me)))
  {

message_vision(HIW"黃金甲龍說:誓死保衛炎龍谷。\n"NOR,me);

return 0;
}
return 1;
}
