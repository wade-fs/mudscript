inherit ROOM;

void create()
{
  set ("short", "晒衣場");
  set ("long", @LONG
一堆洗乾淨的衣服，正飄蕩在晒衣場上。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 2 */
    "south" : __DIR__"camp05.c",
    "west" : __DIR__"camp04.c",
  ]));
  setup();
}
