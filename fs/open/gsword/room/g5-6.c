// Room: /open/gsword/room/gsword5-22.c
inherit ROOM;

void create ()
{
  set ("short", "客房");
  set ("long", @LONG
這是仙劍派用來招待遠客住宿之客房 ,由於仙劍為劍士公會所在 ,兼之
身為武林第一大派 ,因此每天均有很多訪客 ,這裡看起來乾乾淨靜的 ,簡單
淡雅 ,右首一個小茶几 ,一盆蘭花放置其上 ,東邊開了個窗戶 ,和栩的陽光
照射進來 ,十分舒服 .

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : "/open/gsword/room/g5-3.c",
]));

  set("objects",([
	"/open/gsword/npc/guest-1":1,
	]));
  set("light_up", 1);

  setup();
}
