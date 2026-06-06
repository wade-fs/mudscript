// Room: /open/gsword/room/g2-12.c
inherit ROOM;

void create ()
{
  set ("short", "廣場");
  set ("long", @LONG
這是仙劍派眾弟子們平時練劍的場所 ,你看到數百位仙劍弟子們正揮汗練劍 ,
整齊一致的呼喝聲 ,響遍全山 ,近年來仙劍何以如此興盛 ,光看這氣勢 ,你就
明白八九成了 .西邊一條長廊連往流雲軒 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gsword/room");

  set("exits", ([ /* sizeof() == 4 */
  "west" : "/open/gsword/room/g2-14.c",
  "south" : "/open/gsword/room/g2-11.c",
  "north" : "/open/gsword/room/g2-9.c",
  "east" : "/open/gsword/room/g2-13.c",
]));

  setup();
}
