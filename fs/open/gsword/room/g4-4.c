// Room: /open/gsword/room/g4-4.c
inherit ROOM;

void create ()
{
  set ("short", "鐘樓底樓");
  set ("long", @LONG
這裡是仙劍派的鐘樓，一個青銅大鐘在你的正上方，西邊有個小樓梯
可上頂樓，每當仙劍派晨起，用餐，練武等時候，青銅巨鐘的聲響，不但
傳遍全山，就連遠方的蜀中城，也能清楚的聽到鐘聲。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : "/open/gsword/room/g4-5.c",
  "north" : "/open/gsword/room/g5-10",
]));

  set("light_up", 1);

  setup();
}
