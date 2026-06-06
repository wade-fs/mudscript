// Room: /open/gsword/room/g5-13.c
inherit ROOM;

void create ()
{
  set ("short", "陣法廳");
	set( "build", 12 );
  set ("long", @LONG
這裡是仙劍派門人修行陣法的地方，你可以看到這裡有許多的小人放
在這兒，一群排成北斗七星，一群排成太極的圖案，還有許多的一群跟本
讓你看不出這是什麼圖形,看著看著你發覺你的眼皮越來越重,才知道仙劍
陣法實在博大精深。武林第一果然名不虛傳。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/gsword/room/g5-9.c",
  "east" : "/open/gsword/room/g5-14.c",
]));

  set("objects", ([ /* sizeof() == 1 */
        "/daemon/class/swordsman/shouyau": 1,
]));

  set("light_up", 1);

  setup();
}
