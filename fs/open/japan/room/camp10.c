inherit ROOM;

void create()
{
  set ("short", "小庭院");
  set ("long", @LONG
眼前一個簡單的日本造景，庭院中種著一棵櫻花樹。小石頭鋪成
的道路，正是分別指向三位守備隊最重要人員的房間。往北走是隊長
石田的房間。往東是副隊長秋本的房間。往西是副隊長藤原的房間。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 4 */
    "north" : __DIR__"camp11.c",
    "east" : __DIR__"camp12.c",
    "west" : __DIR__"camp13.c",
    "south" : __DIR__"camp09.c",
  ]));
  setup();
}
