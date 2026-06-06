#include <ansi.h>
inherit ROOM;
void create()
{
   set("short", HIW"仙劍第一試煉谷"NOR);
   set("long", @LONG
步入此處.和你之前所見的完全不同...此處好比世外桃源.在你進入之後..
你發現在你的前方有一個逐漸成型的人影..看樣子他就是此處的試煉者了.。
(appo 的提醒...迷陣中..所有房間的north 都是通往此處的捷徑..危險時切記)
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
 "north":"/open/gsword/room2/sun1.c",
 "back":"/open/gsword/room/g5-1.c",
      ]));
  set("objects", ([ /* sizeof() == 2 */
  "/open/gsword/npc2/t1" : 1,
]));
        set("light_up",1);
        set("no_fight",1);
        set("no_transmit", 1);
        setup();
}
