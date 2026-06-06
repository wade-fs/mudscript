// Room : /open/clan/ou-cloud-club/room/room85.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "一生一愛一字刀" );
	set( "object", ([
		"file4"    : "/obj/gift/lingzhi",
		"amount9"  : 31,
		"amount3"  : 156,
		"file8"    : "/open/mogi/castle/obj/ninepill",
		"file5"    : "/obj/stone/powder",
		"file7"    : "/obj/stone/suipian",
		"amount7"  : 4,
		"amount10" : 117,
		"file1"    : "/open/fire-hole/obj/r-pill",
		"file6"    : "/open/mon/obj/mon-pill",
		"amount4"  : 1,
		"file3"    : "/open/fire-hole/obj/w-pill",
		"file10"   : "/open/fire-hole/obj/g-pill",
		"file9"    : "/obj/stone/jiao",
		"amount8"  : 245,
		"amount6"  : 529,
		"file2"    : "/open/mogi/castle/obj/sspill",
		"amount5"  : 4,
		"amount1"  : 109,
		"amount2"  : 20,
	]) );
	set( "owner", "hgf" );
	set( "item_desc", ([
		"hihi" : @ITEM
1234567
ITEM,
	]) );
	set( "build", 10134 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room418",
	]) );
	set( "no_clean_up", 0 );
	set( "long", @LONG
一生一愛一字刀
一生一愛一字刀
一生一愛一字刀
一生一愛一字刀
一生一愛一字刀
一生一愛一字刀
一生一愛一字刀
一生一愛一字刀
一生一愛一字刀
一生一愛一字刀
一生一愛一字刀
一生一愛一字刀
一生一愛一字刀
一生一愛一字刀
LONG);
	set( "cmkroom", 1 );
	set( "clan_room", "傲雲山莊" );
	set( "no_transmit", 1 );
	setup();

	}
