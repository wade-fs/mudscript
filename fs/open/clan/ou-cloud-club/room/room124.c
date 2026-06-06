// Room : /open/clan/ou-cloud-club/room/room124.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
你終於來到山莊的正門口，哇......好..大..的牌樓喔！
迫不及待的好奇心，驅使著你往裡面走了進去。


$HIR$    ╭╯═╬═  ●      ═══╦═══         ║         ═══╬══╬══
$YEL$  ╭╯  ═╬═  ╠══╭═══╬═══╮        ║              ╜    ╜
$HIY$  ╯║══╬═╰╯  ║║  ●  ║  ●  ║        ║         ║    ║    ║
$HIG$    ║  ╭╯╗║    ║    ═════    ║      ║      ● ╚══╣══╬══
$HIC$    ║╭╯  ║╰╮╭╯  ═══╦═══  ║      ║      ║ ╔══╣    ║
$HIB$    ║╯    ║  ╰╮    ╭══╯        ║      ║      ║ ║    ║    ║
$MAG$    ║    ═╯╭╯╰●  ╰═════╮  ╰═══╩═══╣ ●    ║══╩══
$NOR$

LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "light_up", 1 );
	set( "exits", ([ /* sizeof() == 1 */
		"south"     : "/open/clan/ou-cloud-club/room/room245",
		"enter"     : "/open/clan/ou-cloud-club/room/room126.c",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "cmkroom", 1 );
	set( "short", "$HIC$山莊$HIM$正門$NOR$" );
	set( "object", ([
		"file10"   : "/open/magic-manor/obj/wood-ball",
		"file2"    : "/open/magic-manor/obj/soil-ball",
		"amount7"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"amount1"  : 1,
		"amount10" : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/magic-manor/obj/water-ball",
		"file4"    : "/open/magic-manor/obj/water-ball",
		"file5"    : "/open/magic-manor/obj/water-ball",
		"file7"    : "/open/magic-manor/obj/soil-ball",
		"amount9"  : 1,
		"file3"    : "/open/magic-manor/obj/wood-ball",
		"file9"    : "/open/magic-manor/obj/wood-ball",
		"file8"    : "/open/magic-manor/obj/wood-ball",
		"file1"    : "/open/magic-manor/obj/water-ball",
	]) );
	set( "build", 10357 );
	set("objects", ([ /* sizeof() == 1 */
		"/open/clan/ou-cloud-club/npc/npc7" : 1,
		"/open/clan/ou-cloud-club/npc/npc10" : 1,
		"/open/clan/ou-cloud-club/npc/npc13" : 1,
]) );

	}
