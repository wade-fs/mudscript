inherit ROOM;

void create()
{
  set ("short", "通道");
  set ("long", @LONG
狹長的通道左右佈滿狹間，要是在此地搗亂，守軍即可由狹間對
搗亂者進行攻擊。原來近年來港口經常遭受海賊的攻擊，因此特別設
計成易守難攻的地形。往北看見一個櫓。往西可通往石垣上方。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"j08.c",
    "west" : __DIR__"j09.c",
    "south" : __DIR__"j06.c",
  ]));
  setup();
}
