inherit ROOM;

void create()
{
  set ("short", "通道");
  set ("long", @LONG
高聳的築地牆正擋在前方以及通道兩邊，狹長的通道左右佈滿狹
間，要是在此地搗亂，守軍即可由狹間對人搗亂者進行攻擊。原來近
年來港口經常遭受海賊的攻擊，因此特別設計成易守難攻的地形。往
北隱約可看見一個櫓。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"j07.c",
    "west" : __DIR__"j04.c",
  ]));
  setup();
}
