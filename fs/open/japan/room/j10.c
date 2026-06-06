inherit ROOM;

void create()
{
  set ("short", "通道");
  set ("long", @LONG
狹長的通道左右佈滿狹間，要是在此地搗亂，守軍即可由狹間對
人搗亂者進行攻擊。原來近年來港口經常遭受海賊的攻擊，因此特別
設計成易守難攻的地形。往北是守備隊休息訓練的駐紮地。往西可以
登上石垣。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 3 */
    "east" : __DIR__"j09.c",
    "north" : __DIR__"camp01.c",
    "westup" : __DIR__"j11.c",
  ]));
  setup();
}
