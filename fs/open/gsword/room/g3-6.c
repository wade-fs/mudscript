// Room: /open/gsword/room/eghouse1.c
inherit ROOM;

void create ()
{
  set ("short", "小廣場");
  set ("long", @LONG
這是仙劍派劍士們用膳的地方，廣場中間數十張桌椅有條不紊的排列著，
東邊是大廚們開伙的工作房，直往西走，通往仙劍派眾師兄弟們的寢室。北邊
有個樓梯 ,可通往掌門人及仙劍七俠的寢居 .

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"g3-4.c",
  "west" : __DIR__"g3-7.c",
  "east" : __DIR__"g3-5.c",
]));
set("objects",([
"/open/gblade/npc/yuan" : 1,
]));
  set("light_up", 1);

  setup();
}
