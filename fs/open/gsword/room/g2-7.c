// Room: /open/gsword/room/g2-12.c
inherit ROOM;

void create ()
{
  set ("short", "廣場");
  set ("long", @LONG
這是仙劍派眾弟子們平時練劍的場所 ,你看到數百位仙劍弟子們正揮汗練劍 ,
整齊一致的呼喝聲 ,響遍全山 ,近年來仙劍何以如此興盛 ,光看這氣勢 ,你就
明白八九成了 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gsword/room");

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/gsword/room/g2-8.c",
  "south" : "/open/gsword/room/g2-6.c",
]));

   set("objects",([
    "/open/gsword/npc/trainee-6.c":1,
   ]));

  setup();
}
