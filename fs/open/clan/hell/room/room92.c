inherit ROOM;
void create() {
	set( "short", "$HIC$『武天至聖』$NOR$獨孤嵊人頭放置所" );
	set( "owner", "blur" );
	set( "object", ([
		"file6"    : "/open/gblade/obj/sa-head",
		"file5"    : "/open/gblade/obj/sa-head",
		"amount2"  : 1,
		"amount10" : 1,
		"amount5"  : 1,
		"file9"    : "/open/gblade/obj/sa-head",
		"file7"    : "/open/gblade/obj/sa-head",
		"amount6"  : 1,
		"file1"    : "/open/gblade/obj/sa-head",
		"amount7"  : 1,
		"amount1"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"file10"   : "/open/gblade/obj/sa-head",
		"file4"    : "/open/gblade/obj/sa-head",
		"file2"    : "/open/gblade/obj/sa-head",
		"amount3"  : 1,
		"file8"    : "/open/gblade/obj/sa-head",
		"amount4"  : 1,
		"file3"    : "/open/gblade/obj/sa-head",
	]) );
	set( "light_up", 1 );
	set( "build", 11340 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room23",
	]) );
	set( "long", @LONG
這裡是專門放置『武天至聖』獨孤嵊的人頭的地方
由於陰曹地府裡的閻羅王和所多手下們擁有超強的實力
所以當然這有超強實力的對手也是甘拜下風，想到這就
想到以前，當我還是個新手時，連這可怕的敵人都還沒
打過，就這樣的離去時，真是另人覺的可惜。不過現在
和各位好朋友們竟能這樣如此容易得到他的人頭，現在
想想也是值得的:D。

LONG);
	setup();
	replace_program(ROOM);
}
