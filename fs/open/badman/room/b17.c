// Room: /open/badman/room/b17
inherit ROOM;

void create ()
{
  set ("short", "惡人谷南街");
  set ("long", @LONG
走到這裡你突然發現人群好似越來越少，原來自己離開大鬧街
已有一段距離了。你發覺自己竟不知覺的來到惡人谷南街最偏僻的
地方；而最近更聽說有小混混在此搶錢傷人之事發生，想到這點你
不由得的加快自己的腳步。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/badman/npc/hood1.c" : 1,
]));
  set("outdoors", "/open/badman");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"b18",
  "east" : __DIR__"b16",
]));

  setup();
}
