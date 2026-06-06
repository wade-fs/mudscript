inherit ROOM;
void create() {
	set( "short", "hild 之家" );
	set( "owner", "hild" );
	set( "object", ([
		"file2"    : "/open/main/obj/present-f",
		"file1"    : "/open/fire-hole/obj/universe_book",
		"amount1"  : 1,
		"amount2"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10101 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room179.c",
		"south"     : "/open/clan/sky-wu-chi/room/room243.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"east"      : "/open/clan/sky-wu-chi/room/room173.c",
		"rules"     : "/open/clan/sky-wu-chi/room/room434",
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
