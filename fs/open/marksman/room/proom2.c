// Room: /open/marksman/room/proom2.c
inherit ROOM;

void create ()
{
  set ("short", "小茅房內");
  set ("long", @LONG
你看看四周, 似乎沒有什麼特別的東西, 很一般
的家具, 不過看起來似乎已經很舊了, 似乎已經沒有人在
這邊居住。外面有一個小門不知道通道哪去....
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"proom3.c",
  "out" : __DIR__"proom1.c",
]));

  setup();
}
