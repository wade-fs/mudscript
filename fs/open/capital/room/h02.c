// Room: /open/capital/room/h02.c

inherit ROOM;

void create ()
{
  set ("short", "文來胡同");
  set ("long", @LONG
這兒賣的東西仍然是一些文房四寶, 不過看起來的品質似乎剛剛所
看到的還要好, 果然是「貨比三家不吃虧」。這裡的商家聲音也喊的更
大聲的, 吆喝聲此起彼落, 你不禁也被吸引過去看個究竟。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/capital/room/h01",
  "east" : "/open/capital/room/h03",
]));

  set("outdoors", "/open/capital");


  setup();
}
