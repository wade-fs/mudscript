// Room: /open/ping/room/p3
inherit ROOM;

void create ()
{
  set ("short", "長廊");
  set ("long", @LONG
長廊到了這兒有個轉角, 通向一間房間去, 角落處擺設著一瓶花,
連著掛著幾幅詩畫, 一看之下似乎出自名家之手, 頗有一種非凡之勢。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"p6",
  "north" : __DIR__"p4",
  "east" : __DIR__"p2",
]));
  set("light_up", 1);

  setup();
}
