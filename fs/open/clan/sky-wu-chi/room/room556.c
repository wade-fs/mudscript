inherit ROOM;
void create() {
	set( "short", "書籍收藏室" );
	set( "owner", "kew" );
	set( "object", ([
		"file1"    : "/open/mogi/dragon/obj/dragonar",
		"amount4"  : 1,
		"file8"    : "/obj/stone/suipian",
		"amount9"  : 1,
		"file6"    : "/obj/stone/powder",
		"amount10" : 3,
		"amount5"  : 1,
		"file3"    : "/open/mogi/dragon/obj/sunblade",
		"amount3"  : 1,
		"amount6"  : 556,
		"file9"    : "/open/gblade/obj/sa-head",
		"file5"    : "/obj/gift/xisuidan",
		"file4"    : "/open/mogi/dragon/obj/dragon-head",
		"amount2"  : 1,
		"file2"    : "/open/ping/questsfan/obj/diamond_hands",
		"file10"   : "/obj/stone/jiao",
		"file7"    : "/obj/gift/bingtang",
		"amount1"  : 1,
		"amount7"  : 1,
		"amount8"  : 61,
	]) );
	set( "build", 10082 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room555",
	]) );
	set( "long", @LONG
一進到這個房間.你就被堆積如山的書籍所嚇到
為什麼會有這麼多書籍,從哪裡來的.
從書本上你都無從得知.
引起你注意的是,房間中間有一個書架,
看起來是收藏很珍貴的書籍.可是裡面卻沒有書.
你猜想這一本書可能跟這裡的主人研究什麼有很大的關係.
可是這邊的書堆積如山,你找都不想找.
LONG);
	setup();
	replace_program(ROOM);
}
