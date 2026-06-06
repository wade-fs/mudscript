// Room : /open/clan/ou-cloud-club/room/room119.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG

            $HIM$╬╬══╬╔╮╚═╮╚═╩═╯╔═══╮
            ║║    ║╔╮    ║╔╩═╩╗║══╬║
            ║║    ║╚╗╠═╝║╔╬╮║║╔╮║║
            ║╚══╯╚╯║  ╮║║║║║║╚╝╬║
            ╰═══╝╚╚╰═╝╯╝╝╰╝╚╚╯╩╯$NOR$

LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "clan_room", "傲雲山莊" );
	set( "exits", ([ /* sizeof() == 3 */
		"west"      : "/open/clan/ou-cloud-club/room/room4.c",
		"long"      : "/open/clan/ou-cloud-club/room/room142",
		"east"      : "/open/clan/ou-cloud-club/room/room13.c",
		"down"      : "/open/clan/ou-cloud-club/room/room479.c",
		"up"        : "/open/clan/ou-cloud-club/room/room132.c",
		"daimon"    : "/open/clan/ou-cloud-club/room/room252",
]) );
	set( "light_up", 1 );
	set( "short", "$HIC$俠$HIM$魂$HIR$義$HIB$魄$NOR$" );
	set( "object", ([
		"amount2"  : 1,
		"file7"    : "/open/killer/headkill/obj/world_dag",
		"file2"    : "/open/killer/headkill/obj/i_dag",
		"file5"    : "/open/killer/headkill/obj/e_dag",
		"amount9"  : 900,
		"file1"    : "/open/killer/headkill/obj/world_dag",
		"amount1"  : 1,
		"file8"    : "/open/killer/headkill/obj/world_dag",
		"file6"    : "/open/killer/headkill/obj/w_dag",
		"amount4"  : 1,
		"file3"    : "/open/killer/headkill/obj/world_dag",
		"amount8"  : 1,
		"file4"    : "/open/killer/headkill/obj/f_dag",
		"amount5"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"file9"    : "/open/mogi/castle/obj/ninepill",
		"amount6"  : 1,
	]) );
	set( "build", 11136 );
	set( "cmkroom", 1 );
	setup();

	}
