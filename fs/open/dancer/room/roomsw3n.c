//room:/open/dancer/room/roomsw3n.c :cgy

inherit ROOM;

void create ()
{
  set ("short","藥房" );
  set ("long", @LONG
這裡是夜夢小築的藥房在這裡你聞到了陣陣的草藥芳香，由於鏡
月島山林草地甚廣，故各種的藥草可說是應有盡有，就算是稀有的藥
草恐怕也不在少數吧！整理有序的藥櫃令人心生舒適之感。

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "south"     :"/open/dancer/room/roomsw3.c",
  
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/dancer/npc/yi.c" : 1,
]));

  setup();

}
