inherit ROOM;

void create()
{
  set ("short", "南町南大路");
  set ("long", @LONG
寬闊平坦的路面，來來往往盡是衣著華利的商人，道路兩旁店家
內的夥計正忙著替貨架上面捕貨，而老闆也正忙著跟客人寒喧結算。
人們也在挑選著許多來自不同國家的異國商品。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"j19.c",
    "south" : __DIR__"j17.c",
  ]));
  setup();
}
