// Room: /u/u/unfinished/room/is7.c
inherit ROOM;

void create ()
{
  set ("short", "沙灘");
  set ("long", @LONG
這裡的地上躺著許多大岩石, 跟四周的環境很不協調. 看起來類似石陣之類
的, 但是並找不到什麼其他不尋常的地方, 看來是自己太多心了吧.
LONG);

  set("outdoors", "/u/u");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"is12.c",
  "east" : __DIR__"is8.c",
  "south" : __DIR__"is4",
]));

  setup();
}
