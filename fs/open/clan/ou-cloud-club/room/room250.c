inherit ROOM;
void create() {
	set( "short", "$HIW$上帝禁區$NOR$" );
	set( "owner", "dking" );
	set( "object", ([
		"amount8"  : 30,
		"file1"    : "/open/gblade/obj/sa-head",
		"file3"    : "/open/fire-hole/obj/r-pill",
		"file10"   : "/obj/gift/xisuidan",
		"amount10" : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/fire-hole/obj/p-pill",
		"file7"    : "/open/ping/obj/poison_pill",
		"amount1"  : 1,
		"file8"    : "/open/killer/obj/atman_pill",
		"amount2"  : 40,
		"file2"    : "/open/fire-hole/obj/g-pill",
		"amount9"  : 1,
		"amount5"  : 50,
		"amount3"  : 37,
		"amount7"  : 19,
	]) );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room565",
		"east"      : "/open/clan/ou-cloud-club/room/room183.c",
	]) );
	set( "light_up", 1 );
	set( "build", 10248 );
	set( "long", @LONG
此地為魔界霸刀‧刀魔  星野殘紅隱居的妖刀界入口，在三百年前，
天界的眾神合力圍剿魔界，在魔界各高手紛紛被擊敗後，天神們終於
找到了隱居多時的星野殘紅，而星野殘紅為了替被殘殺的魔界之人，
在逼不得已之下，他的愛刀【無極】終於再度出鞘，星野殘紅在此地
與天界的一百零八位天神決戰，星野殘紅奮戰了七天七夜後，終於擊
敗了天界派出的一百零八位高手，而星野殘紅復興魔界後，依然在此
地歸隱，他為了避免有無知的人闖入此地，便派了他於神魔大戰後所
收服的一名高手鎮守此地，這裡星野殘紅將之命名為「上帝禁區」。

刀魔護衛  「劍血封喉」 浪翻雲 (Lan-far-un)





LONG);
	setup();
	replace_program(ROOM);
}
