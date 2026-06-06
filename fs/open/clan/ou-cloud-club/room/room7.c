// Room : /open/clan/ou-cloud-club/room/room7.c
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
		"amount10" : 1,
		"amount8"  : 1,
		"amount5"  : 1,
		"amount7"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount3"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/killer/headkill/obj/bluekill",
		"file6"    : "/open/magic-manor/obj/hwa-je-icer",
		"file2"    : "/open/magic-manor/obj/fon-sky-sword",
		"file7"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount6"  : 1,
		"file5"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file4"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount2"  : 1,
		"amount4"  : 1,
		"file9"    : "/open/magic-manor/obj/fon-sky-sword",
		"file10"   : "/open/magic-manor/obj/lin-cloud-fan",
		"file3"    : "/open/magic-manor/obj/maun-shadow-blade",
	]) );
	set( "build", 12974 );
	set( "clan_room", "傲雲山莊" );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
		"south"     : "/open/clan/ou-cloud-club/room/room9",
		"north"     : "/open/clan/ou-cloud-club/room/room8.c",
]) );
	set( "no_transmit", 1 );
	set( "light_up", 1 );
	setup();

	}
