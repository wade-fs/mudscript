// Room: /open/gsword/room/g2-12.c
inherit ROOM;

void create ()
{
  set ("short", "廣場");
  set ("long", @LONG
這是仙劍派眾弟子們平時練劍的場所，你看到數百位仙劍弟子們正揮
汗練劍，整齊一致的呼喝聲，響遍全山。近年來仙劍何以如此興盛，光看
這氣勢，你就明白八九成了。北邊一條長廊通往仙劍內部。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gsword/room");

  set("exits", ([ /* sizeof() == 4 */
  "north" : "/open/gsword/room/g4-1.c",
  "west" : "/open/gsword/room/g2-9.c",
  "south" : "/open/gsword/room/g2-13.c",
  "east" : "/open/gsword/room/g2-7.c",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/open/gsword/npc/spy.c" :1, ]));
  setup();
}
