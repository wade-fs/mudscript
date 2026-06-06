// Room: /u/o/ookami/pkroom/room06.c
inherit ROOM;

void create ()
{
  set ("short", "會場中央");
  set ("long", @LONG
這裡是會場的中央, 舉目望去, 只見一片空曠的平地, 這裡正能讓
眾人發揮平日所學, 在武林大會中一較高下, 你平靜的心裡也生出了緊
張的感覺

LONG);

  set("light_up", 1);
  set("no_auc", 1);
        set("no_transmit", 1);
  set("pkroom", 1);
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"room02.c",
  "west" : __DIR__"room05",
  "south" : __DIR__"room10",
  "east" : __DIR__"room07.c",
]));

  setup();
}
