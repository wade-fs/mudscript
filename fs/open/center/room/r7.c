// Room: /u/l/lotus/girl/r7.c

inherit ROOM;

void create()
{
  set ("short", "練舞房");
  set ("long", @LONG
這是舞孃們平時練習舞蹈的地方, 架子上堆滿了姑娘們跳舞用的
彩帶, 扇子, 棒子等小道具, 還有幾本舞譜. 真不巧姑娘們都上花廳
表演去了, 練舞房空盪盪的沒有人在.
LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"w4",
]));
  set("file_name", __DIR__"r7.c");
  setup();
}
