inherit ROOM;

void create()
{
  set ("short", "通道");
  set ("long", @LONG
狹長的通道左右佈滿狹間，要是在此地搗亂，守軍即可由狹間對
人搗亂者進行攻擊。原來近年來港口經常遭受海賊的攻擊，因此特別
設計成易守難攻的地形。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 2 */
    "east" : __DIR__"j07.c",
    "west" : __DIR__"j10.c",
  ]));
  setup();
}
