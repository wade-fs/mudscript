// Room : /open/clan/ou-cloud-club/room/room108.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "邪神居" );
	set( "owner", "sula" );
	set( "object", ([
		"amount4"  : 81,
		"amount8"  : 1,
		"amount1"  : 556,
		"file9"    : "/open/magic-manor/obj/soil-ball",
		"file5"    : "/open/mogi/dragon/obj/dragon-head",
		"file2"    : "/open/capital/obj/force_book",
		"amount3"  : 1,
		"amount5"  : 1,
		"amount10" : 1,
		"file4"    : "/open/mogi/castle/obj/sspill",
		"amount9"  : 1,
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"file6"    : "/open/magic-manor/obj/master_snake_head",
		"amount2"  : 1,
		"file7"    : "/open/magic-manor/obj/water-ball",
		"file10"   : "/open/magic-manor/obj/golden-ball",
		"amount6"  : 1,
		"amount7"  : 1,
		"file8"    : "/open/magic-manor/obj/fire-ball",
		"file1"    : "/open/mogi/castle/obj/ninepill",
	]) );
	set( "build", 10038 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room135",
	]) );
	set( "cmkroom", 1 );
	set( "long", @LONG
順著傲雲山莊的二樓走道，你來到一間透著陰暗氣息的廂房，定神
環顧四週，媽媽咪呀，兩旁的橫樑下吊著一顆顆的人頭。大部分的都已
經逐漸風乾，有的則還偶而會從切口處滴下幾滴鮮血。這些都是復活邪
神行走江湖時的戰利品，因為他以狂想空間永遠的卒仔自居，所以當他
看到有人比他還卒仔時，便會痛下殺手取下他的人頭以示警惕。

LONG);
	set( "no_clean_up", 0 );
	set( "no_transmit", 1 );
	set( "clan_room", "傲雲山莊" );
	setup();

	}
