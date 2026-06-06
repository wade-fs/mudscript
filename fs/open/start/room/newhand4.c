#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","新手練功\區");
  set ("long", @LONG
這個地方是受到天神祝福的區域，來到這裡你，看到一堆和你一樣的狂想菜鳥
正拿著武器拼命的與這裡的練功獸練習。看來你是來對地方了，趕快拿出你的武器
跟這些練功獸一起練功吧！希望你早日成為狂想空間裡的一代大俠。
                                                          狂想巫師群敬上
LONG);

  set("objects", ([ /* sizeof() == 2 */
     "/open/start/npc/eagle1" : 2,
     "/open/start/npc/kbird" : 1,
]));
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"newhand7.c",
  "north" : __DIR__"newhand1.c",
  "east" : __DIR__"newhand5.c",
  
]));
  set("no_transmit", 1);
  set("light_up", 1); 
  set("no_magic", 1);
  setup();
}
