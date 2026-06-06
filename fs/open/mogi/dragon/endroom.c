// Room: /u/p/poloer/dragon/endroom
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "魔王殿總部");
	set( "build", 18 );
  set ("long", @LONG
一進到這裡，一陣屍臭味就噗鼻而來，讓人非常的噁心。看到四周
全都是死人駭骨，可能是誤闖炎龍谷的人吧。也可以看出谷主是一位殘
暴的人，牆壁還滴著血。前方正有一個人蹲著在啃食人肉。
莫非他是...........

LONG);
        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);

  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"g2-5",
"up" : __DIR__"f-4",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/jen.c" : 1,
]));

  setup();
}     

int valid_leave(object me, string dir)

{
        if(dir=="up"&&present("jen",environment(me)))
  {

message_vision(HIY"鄭雨橋喝道 :「小子，你幹什麼？」\n"NOR,me);

return 0;
}
return 1;
}



