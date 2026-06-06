// Room: /open/badman/room/b15
inherit ROOM;

void create ()
{
  set ("short", "惡人谷南街");
  set ("long", @LONG
惡人谷南街由這兒開始轉成東西向。與其它地方不同的是，你
隱約感覺到街道上有股不尋常的氣息。也不知道為甚麼，你感覺到
在行人熙熙攘攘的此處，竟好像有著絲說不出的壓迫感。
 
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/badman/npc/pauper.c" : 1,
]));
  set("outdoors", "/open/badman");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"b16",
  "north" : __DIR__"b14",
]));

  setup();
}
