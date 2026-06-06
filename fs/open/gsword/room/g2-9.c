// Room: /open/gsword/room/g2-12.c
inherit ROOM;

void create ()
{
  set ("short", "廣場");
  set ("long", @LONG
這是仙劍派眾弟子們平時練劍的場所 ,你看到數百位仙劍弟子們正揮汗練劍 ,
整齊一致的呼喝聲 ,響遍全山 ,近年來仙劍何以如此興盛 ,光看這氣勢 ,你就
明白八九成了 .西北一條小徑連往仙劍後花園 .

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/npc/trainee2" : 1,
]));

  set("light_up", 1);
  set("outdoors", "/open/gsword/room");

  set("exits", ([ /* sizeof() == 3 */
  "south" : "/open/gsword/room/g2-10.c",
  "east" : "/open/gsword/room/g2-8.c",
  "northwest" : "/open/gsword/room/g4-7.c",
]));

  setup();
}
