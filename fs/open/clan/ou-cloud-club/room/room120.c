// Room : /open/clan/ou-cloud-club/room/room120.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG

$HIM$    　　　　　　　　　║　　║    ║
$HIC$　　　　　　　　  ═╦═╦═╠══╯
$HIW$　　　　　　　　  ║╰╦╯║╰══╮
$HIB$　　　　　  　　　╰═╬═╯╭══╯
$HIG$　　　　　　　　  ╭═╩═╮╠═══
$NOR$　　　　　　　　  ╠═══╣╠═══
$HIR$　　　　　  　　　╠═══╣╠═══
$HIC$　　　　　　　　  ╯  ══╯╰═══
LONG);
	set( "no_clean_up", 0 );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	set( "short", "$HIY$臥$HIR$龍$NOR$房" );
	set( "owner", "long" );
	set( "object", ([
		"amount9"  : 1,
		"file7"    : "/open/killer/obj/atman_pill",
		"amount5"  : 535,
		"file10"   : "/open/magic-manor/ghost/obj/trigram-pill",
		"file2"    : "/open/killer/headkill/obj/world_dag",
		"amount10" : 35,
		"file9"    : "/open/mon/obj/thousand-nectar",
		"amount8"  : 34459,
		"file6"    : "/open/mogi/castle/obj/sspill",
		"file3"    : "/open/killer/headkill/obj/world_dag",
		"file4"    : "/obj/gift/xiandan",
		"amount6"  : 452,
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 3000,
		"amount4"  : 1,
		"amount3"  : 1,
		"amount1"  : 770,
		"file8"    : "/open/mon/obj/mon-pill",
		"amount2"  : 1,
		"file1"    : "/open/ping/obj/poison_pill",
	]) );
	set( "build", 11942 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room142.c",
	]) );
	set( "clan_room", "傲雲山莊" );
	set( "light_up", 1 );
	setup();

	}
