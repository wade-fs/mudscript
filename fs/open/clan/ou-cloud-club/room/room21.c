// Room : /open/clan/ou-cloud-club/room/room21.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
通往惡魔城的道路，是傲雲山莊內的主要道路，兩
邊的牆壁是以$HIC$玄離冰$NOR$打造而成的，不時透發出一股清透
涼意，火把更是以火龍幻境內的$HIR$火龍膽$NOR$點燃，據說可以
永不熄滅．而地板則是使用無堅不摧的金剛石所鋪設而
成，一眼望去光芒萬千．

LONG);
	set( "short", "傲雲道" );
	set( "object", ([
		"amount4"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount5"  : 1,
		"file10"   : "/open/magic-manor/obj/evil-gwe-blade",
		"file4"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount2"  : 1,
		"file5"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount1"  : 1,
		"file6"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount6"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount10" : 1,
		"file7"    : "/open/ghost-hole/obj/death-butterfly",
		"file3"    : "/open/magic-manor/obj/maun-shadow-blade",
	]) );
	set( "build", 11352 );
	set( "exits", ([
  "north" : "/open/clan/ou-cloud-club/room/room22.c",
  "south" : "/open/clan/ou-cloud-club/room/room20",
]) );
	set( "no_transmit", 1 );
	set( "light_up", 1 );
	setup();

	}
