inherit ROOM;

void create ()
{
  set ("short", "空地");
  set ("long", @LONG
來到了屋前的空地，遍地所及全都是茶花，品種很多，令人
目不遐給，你看到屋內坐著一個人在看書，應該就是你想要找的
那個人了吧。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"d1",
  "north" : __DIR__"d3",
]));

  set("no_transmit",1);
  setup();
}
