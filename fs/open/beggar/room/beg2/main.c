// Room: /u/g/guetenr/beggar/room/beg2/main.c
inherit ROOM;
#include <ansi.h>
#include <room.h>


void create ()
{
  set ("short", "翔龍大廳");
  set ("long", @LONG

    一進此室，只見在一條紅色地毯的末端，坐著一個相貌堂堂的乞
丐，他手裡拿著一根通體而綠的棒子，任誰見了都知道他是中原第一
大幫丐幫的幫主。
    

  左邊壁上掛著一幅『肚痛帖』，充滿了丐幫中人不拘小節的豪氣。
  右邊掛著一幅明末的『流民圖』，表示丐幫對現今朝政的積弱不
  振感到沮喪同時也為世人落難的遭遇滿懷同情，不知如何。



面對丐幫幫主，你感到一股強大的氣勢壓迫著你，連大氣都無法喘
一口。


LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"clr22.c",
]));
  set("valid_startroom", 1);
  set("objects", ([ /* sizeof() == 2 */
  "/daemon/class/beggar/master_su.c" : 1,
  "/open/beggar/room/beg1/npc/leader_wen.c" : 1,
  "/open/beggar/room/beg1/npc/leader_wang.c" : 1,

]));
  set("light_up", 1);

  setup();
  call_other("obj/board/beggar_b.c","???");
}
