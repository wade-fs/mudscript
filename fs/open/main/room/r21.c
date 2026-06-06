// Room: /open/main/room/r21.c

inherit ROOM;

void create()
{
	set("short", "道路");
	set("long", "西邊是凌雲村, 因為京城早就遷往東邊去了, 因此這附近人口
越來越少, 村長為了這問題正大傷惱筋哩, 不過, 就算想幫也無從
幫起. 何況, 你也想早日離開凌雲村去闖蕩一番的. 往東直走就是
驛站, 南邊有座筆架山.
");

  set("exits", ([ /* sizeof() == 4 */
  "west" : "/open/start/room/s14",
  "north" : __DIR__"m8",
  "south" : __DIR__"m14",
  "east" : __DIR__"r22",
]) );

  set("outdoors", "/open/main" );

  setup();
}
