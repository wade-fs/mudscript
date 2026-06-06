// Room: /open/main/room/maiu-1.c
inherit ROOM;

void create ()
{
  set ("short", "懸空吊橋");
  set ("long", @LONG
你走在懸空吊橋上,瀾滄江就在你腳下,河面上一團團白霧
罩在滾滾江流之上,陽光照得江水金蛇亂舞,放眼不盡,令人心曠
神怡.
LONG);

  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"maiu-1.c",
  "west" : __DIR__"maiu-3.c",
]));

  setup();
}
