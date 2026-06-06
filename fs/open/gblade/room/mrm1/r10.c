// Room: /u/m/moner/water/mblade/r9.c
inherit ROOM;

void create ()
{
  set ("short", "牢房");
  set ("long", @LONG

這是一間黑牢，暗無天日的室內囚禁著一個人，地上滿怖著水澤，
室內僅有一座石床。

LONG);

  set("exits", ([ /* sizeof() == 1 */
"north":"/open/gblade/room/room19.c",
]));
set("objects",([
"/daemon/class/blademan/npc/gman":1,
]));
set("no_transmit", 1);
  setup();
}
