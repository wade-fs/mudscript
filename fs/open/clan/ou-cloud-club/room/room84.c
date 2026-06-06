// Room : /open/clan/ou-cloud-club/room/room84.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "四海為家" );
	set( "object", ([
		"amount2"  : 12,
		"file9"    : "/open/fire-hole/obj/g-pill",
		"amount4"  : 607,
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"file2"    : "/open/mogi/castle/obj/sspill",
		"file3"    : "/open/mogi/castle/obj/sspill",
		"file5"    : "/open/magic-manor/obj/master_snake_head",
		"amount7"  : 63,
		"file7"    : "/open/fire-hole/obj/y-pill",
		"amount5"  : 1,
		"amount3"  : 59,
		"amount6"  : 36,
		"file8"    : "/open/fire-hole/obj/g-pill",
		"file6"    : "/open/fire-hole/obj/b-pill",
		"amount9"  : 4,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mon/obj/mon-pill",
		"amount8"  : 10,
		"amount1"  : 156,
		"amount10" : 1,
	]) );
	set( "owner", "pobpob" );
	set( "build", 11901 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room612",
		"north"     : "/open/clan/ou-cloud-club/room/room418.c",
	]) );
	set( "no_clean_up", 0 );
	set( "long", @LONG
藍天為帳,大地為床,利刃為枕,四海為家
睡在刀上,悟入刀中,臥刀,悟刀,悟嗎!
風翼悟刀生
一生一愛一字刀
不問歲月又為何，口口聲聲一字刀
日出日落又一天，生死道中皆聖賢；修繪萬象讀不滅，太虛渡者算萬年。
好漢一生不流淚, 走遍天下為了誰﹖恨深緣盡情未絕, 難忘可敬一仇人
LONG);
	set( "cmkroom", 1 );
	set( "clan_room", "傲雲山莊" );
	set( "no_transmit", 1 );
	setup();

	}
