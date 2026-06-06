// Room: /u/m/moner/room/room14.c
inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG

這市一條由青石鋪成的羊長小徑, 往前通往後院, 往南是內室, 兩旁
種植著芳草悽樹, 陣陣的香味伴著你前行。
    清風一陣陣的吹拂著你, 不知名的鳥鳴吱吱的傳來。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room20.c",
  "south" : __DIR__"room13.c",
]));
  set("outdoors", "wind");

  setup();
}
