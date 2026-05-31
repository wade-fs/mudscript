// Room: /d/snow/eroad1.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m過去時空[0m 黃土小徑");
  set ("long", @LONG
這是一條普通的黃土小徑﹐彎彎曲曲往東北一路盤旋上山﹐北邊有
一間城隍廟﹐往西則是雪亭鎮的街道。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"eroad2",
  "west" : __DIR__"sroad1",
  "north" : __DIR__"temple",
]));
  set("outdoors", "snow");

  setup();
}
