// Room : /open/clan/ou-cloud-club/room/room9.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "傲雲道" );
	set( "object", ([
		"amount9"  : 1,
		"amount8"  : 1,
		"file10"   : "/open/capital/obj/icer",
		"file2"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file8"    : "/open/magic-manor/obj/evil-kill-claw",
		"file3"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount5"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file4"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount7"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"file5"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount10" : 1,
		"file6"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file1"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount4"  : 1,
	]) );
	set( "build", 17589 );
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
	set( "exits", ([ /* sizeof() == 2 */
		"south"     : "/open/clan/ou-cloud-club/room/hall",
		"north"     : "/open/clan/ou-cloud-club/room/room7.c",
]) );
	set( "clan_room", "傲雲山莊" );
	setup();

	}
