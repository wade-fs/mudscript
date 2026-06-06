// Room: /u/g/guetenr/beggar/room/beg2/clr21.c
inherit ROOM;

void create ()
{
  set ("short", "前院");
  set ("long", @LONG
院中不置什物得空靈之境，地面以卵石與側磚排成套八方式樣以疏導積
水，行走於上縱天大雨亦不沾鞋；幾株梧桐紅梅靜立南隅，豔香疏影相得彰
，樹下海棠韻嬌，深紅淡白更交輝；兩側迴廊連接莊園深處院落，北為轎廳
南即大門。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"clr22.c",
  "out" : __DIR__"clr20.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/beggar/room/beg1/npc/lv7beg.c" : 2,
]));

  setup();
}
