// Room : /open/clan/ou-cloud-club/room/room88.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$無限城$NOR$--$CYN$下界$NOR$" );
	set( "owner", "shasword" );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room314.c",
		"north"     : "/open/clan/ou-cloud-club/room/room244",
		"enter"     : "/open/clan/ou-cloud-club/room/room479.c",
		"south"     : "/open/clan/ou-cloud-club/room/room33.c",
		"east"      : "/open/clan/ou-cloud-club/room/room147.c",
	]) );
	set( "object", ([
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount9"  : 1,
		"amount1"  : 46,
		"file2"    : "/obj/gift/unknowdan",
		"amount4"  : 1,
		"file9"    : "/open/mogi/castle/obj/leave",
		"amount8"  : 5,
		"amount3"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"file8"    : "/open/mogi/castle/obj/ninepill",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/fire-hole/obj/b-pill",
		"file3"    : "/open/prayer/obj/dragon-eye",
		"amount7"  : 1,
		"file10"   : "/open/mogi/castle/obj/leave",
		"file6"    : "/open/magic-manor/obj/fon-sky-sword",
		"file1"    : "/open/mon/obj/mon-pill",
		"amount5"  : 8,
	]) );
	set( "light_up", 1 );
	set( "build", 10037 );
	set( "no_clean_up", 0 );
	set( "long", @LONG
無限城下界----一個被遺忘的都市，自從百年戰爭過後
帝國的毀滅，一切的研究及開發也隨之停止，隨著時間洪流
的軌跡，成為狂小晴菜刀團的腹地之一，目前是由菜刀團左
翼指揮官『狂暴菜刀』狂小雨指揮運作。負責物資的運送及
菜刀團一切指揮行動的中繼站。

LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
