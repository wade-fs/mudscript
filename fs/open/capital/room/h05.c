// Room: /open/capital/room/h05.c

inherit ROOM;

void create ()
{
  set ("short", "扁鵲胡同");
  set ("long", @LONG
步入扁鵲胡同, 最特別的地方便是地上出奇的乾淨, 兩旁柳樹搖曳
, 但地上卻連一片葉子也沒有, 四處都掃的乾乾淨淨。仔細的嗅一嗅,
空氣中似乎瀰漫著一股濃郁的藥味, 大概是京城裡大部分的藥店都設在
這兒的緣故。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/capital/room/r67",
  "east" : "/open/capital/room/h06",
]));

  set("outdoors", "/open/capital");


  setup();
}
