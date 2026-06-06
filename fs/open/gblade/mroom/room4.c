// Room: /u/m/moner/room/room1.c
inherit ROOM;

void create ()
{
  set ("short", "練武場");
  set ("long", @LONG

正如所謂的百日刀，千日劍，刀的上手容易，加上刀為霸氣之首，故習刀者日眾，
有鑑於此，魔刀內特闢了不少練武場，做為門人相互切搓、拆招進取的地方。兩旁
放置著兵器架，場中以有不少第子在拆招了。
      空中飄著朵朵的彩雲，絲絲的春風吹拂著你....。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room1.c",
  "east" : __DIR__"room3.c",
]));
   set("objects", ([ /* sizeof() == 3 */
"/daemon/class/blademan/npc/trainee2":3,
]));
  set("no_magic", 1);

  setup();
}
