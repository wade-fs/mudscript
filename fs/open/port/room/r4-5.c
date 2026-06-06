// Room: /open/gblade/port/room/p1-8.c
inherit ROOM;

void create()
{
  set ("short", "防具店");
	set( "build", 18 );
  set ("long", @LONG
這是一家販賣防具的商店 , 由於刀客擅長攻擊 , 對於防
守並不那麼注重 , 因此這裡的生意就遠不如武器店了 , 不過
買些東西來保護自己也是好的 , 你可以用 (list) 來得知老
闆賣些什麼東西 .

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
	"north" : "/open/port/room/r4-2",
]));
	set("objects",([
	"/open/port/npc/lee":1,
	]));
  setup();
}
