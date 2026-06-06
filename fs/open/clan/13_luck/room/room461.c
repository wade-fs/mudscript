inherit ROOM;
void create() {
	set( "short", "『山道一』" );
	set( "owner", "poll" );
	set( "object", ([
		"amount8"  : 1,
		"amount9"  : 1,
		"file6"    : "/open/gblade/obj/sa-head",
		"amount4"  : 1,
		"file9"    : "/daemon/class/fighter/figring",
		"file4"    : "/open/gblade/obj/sa-head",
		"amount7"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/gblade/obj/sa-head",
		"file2"    : "/open/gblade/obj/sa-head",
		"amount6"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/ghost-hole/obj/butterfly",
		"file8"    : "/open/gblade/obj/sa-head",
		"file7"    : "/open/gblade/obj/sa-head",
		"amount5"  : 1,
		"file5"    : "/open/gblade/obj/sa-head",
		"file10"   : "/open/snow/obj/figring",
		"amount10" : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10100 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room462",
		"south"     : "/open/clan/13_luck/room/room460",
	]) );
	set( "long", @LONG

     往北邊的山道走了上來，你所看到的景色就更為寬廣了。距離山頂上面
 的那一棟古色古香的建築物也不遠了。而也可以隱隱約約的見到遠方薄薄的
 積雪。你而如果沒記錯的話，在這座山頂上面是最近新發展的門派，聽說叫
 做「墨子教」的一個門派。想到這裡，不由自主的腳步加快了過去，想要一
 探究竟。

LONG);
	setup();
	replace_program(ROOM);
}
