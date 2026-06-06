// Room: /open/bonze/npc//room/s18.c
inherit ROOM;

void create ()
{
  set ("short", "羅漢堂走廊");
  set ("long", @LONG

踏進這邊發現這裡的少林弟子都在努力的鍛練著自己的體態,
深怕一個不小心就被比下去.個個弟子都赤著上身流著汗,看來
少林最陽氣之處即為此地.

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"s17.c",
  "west" : __DIR__"s19.c",
]));
  set("outdoors", "/open/bonze/npc//room");
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/bonze/npc/L_trainee" : 3,
]));
  

  setup();
}
