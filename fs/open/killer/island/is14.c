// Room: /u/u/unfinished/room/is14.c
inherit ROOM;

void create ()
{
  set ("short", "樹林盡頭");
  set ("long", @LONG
一路北行, 終於穿過陰暗的樹林. 來到此地, 你赫然在你的東邊看到一艘擱
淺的船隻, 此船不大, 觀其損毀的程度, 似乎已經擱淺在這裡很久了. 此地北邊
與西邊是海, 看來應該是小島的西北角.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"is10",
  "east" : __DIR__"is15.c",
]));
  set("outdoors", "/u/u");

 setup();
  replace_program(ROOM);
}
