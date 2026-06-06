// Room: /open/gblade/port/room/p2-9.c
inherit ROOM;

void create()
{
  set ("short", "波蘿麵包店");
  set ("long", @LONG
一進門就被一股膿膿的麵包香所包圍 , 你看到一個肚子禿禿的
麵包師正揮汗做著麵包 , 奇怪的是 , 整間店面只有一種麵包 ---
波蘿麵包 , 這個麵包師難不成只會做這種麵包 ?

LONG);

  set("light_up", 1);
	set("objects",([
	"/open/gblade/port/npc/breader":1,
	]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"p2-3",
]));
  setup();
}
