// inn_2f.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m過去時空[0m 飲風客棧二樓");
  set ("long", @LONG
你現在來到了飲風客棧的二樓﹐這家客棧有個很奇怪的規矩﹐就是只留宿
名頭夠大的客人﹐如果你只是一個無名小卒﹐不論出再多銀兩都租不到一間空
房﹐牆邊有一道樓梯通往一樓的茶座。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"inn",
]));

  setup();
}
