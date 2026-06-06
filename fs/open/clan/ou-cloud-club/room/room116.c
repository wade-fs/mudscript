// Room : /open/clan/ou-cloud-club/room/room116.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIY$天山$NOR$山峰" );
	set( "owner", "miles" );
	set( "object", ([
		"file9"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount1"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount6"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount2"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount10" : 1,
		"amount4"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount8"  : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gloves",
	]) );
	set( "build", 10122 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 1 */
  "eastdown" : "/open/clan/ou-cloud-club/room/room79",
]) );
	set( "long", @LONG

$HIY$    ╭═══╦═══╯             ║               ║   ╠═══╦
            ║                     ║             ║║║ ╯═╭═╯
    ╭═══╬═══╯     ║      ║      ║     ║║║ ╭═╯═╮
          ╭╯╮           ║      ║      ║     ║║║ ╯═╬═╰
        ╭╯  ╰╮         ║      ║      ║     ╰╩╯   ═╬═
    ╰═╯      ╰═╯     ╰═══╩═══╯            ══╬══$NOR$

LONG);
	set( "clan_room", "傲雲山莊" );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
