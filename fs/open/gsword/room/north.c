// Room: /open/gsword/room/north
inherit ROOM;

void create ()
{
  set ("short", "長廊");
  set ("long", @LONG
這裡已經算是仙劍派的內部了，一般若非劍派的人只能就此止步，
從這往北是劍士們練劍的場所，往西是用膳及師兄弟們的住處，東
邊則是典藏著武學秘笈的藏經閣。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : "/open/gsword/room/ghouse",
  "west" : "/open/gsword/room/eghouse",
  "north" : "/open/gsword/room/nghouse",
  "east" : "/open/gsword/room/wghouse.c",
]));

  set("light_up", 1);

  setup();
}
