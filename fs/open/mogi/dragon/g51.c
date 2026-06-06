// Room: /u/p/poloer/dragon/g51
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "關卡");
	set( "build", 45 );
  set ("long", @LONG
這是一樓通往二樓的途中。不過面前有位高大的人擋住你的去路，
他拿著把劍，殺氣騰騰的，好有氣勢。
LONG);
  set("evil", 1);
  set("no_auc", 1);
  set("no_transmit", 1);
  set("light_up", -1);
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"g2-1",
  "down" : __DIR__"g5",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/ghostman.c" : 1,
]));

  setup();
}

int valid_leave(object me, string dir)

{
        if(dir=="up"&&present("ghost",environment(me)))
  {

message_vision(HIY"七重冥王怒沖沖說:閒雜人等不得入內。\n"NOR,me);

return 0;
}
return 1;
}
