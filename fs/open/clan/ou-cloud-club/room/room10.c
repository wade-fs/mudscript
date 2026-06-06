// Room : /open/clan/ou-cloud-club/room/room10.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$BRED$$HIM$～$HIR$不$HIC$～$HIR$二$HIR$～$HIR$刀$HIG$～$NOR$" );
	set( "owner", "moblade" );
	set( "object", ([
		"amount4"  : 1,
		"amount3"  : 1,
		"file1"    : "/obj/gift/unknowdan",
		"amount1"  : 1,
		"file4"    : "/open/capital/obj/blade2",
		"file3"    : "/open/capital/obj/blade2",
	]) );
	set( "build", 10530 );
	set( "light_up", 1 );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	set( "long", @LONG
通往惡魔城的道路，是傲雲山莊內的主要道路，兩
邊的牆壁是以$HIC$玄離冰$NOR$打造而成的，不時透發出一股清透
涼意，火把更是以火龍幻境內的$HIR$火龍膽$NOR$點燃，據說可以
永不熄滅．而地板則是使用無堅不摧的金剛石所鋪設而
成，一眼望去光芒萬千．
LONG);
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 1 */
		"out"       : "/open/clan/ou-cloud-club/room/room32",
		"up"        : "/open/clan/ou-cloud-club/room/room145",
]) );
	set( "clan_room", "傲雲山莊" );
	setup();

	}
