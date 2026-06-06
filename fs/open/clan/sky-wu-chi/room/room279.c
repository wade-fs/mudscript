inherit ROOM;
void create() {
	set( "short", "製毒房" );
	set( "owner", "panhermes" );
	set( "object", ([
		"amount4"  : 22,
		"file4"    : "/open/fire-hole/obj/w-pill",
		"amount2"  : 7,
		"amount6"  : 1,
		"amount1"  : 7,
		"amount5"  : 5,
		"file1"    : "/open/fire-hole/obj/b-pill",
		"file3"    : "/open/fire-hole/obj/r-pill",
		"amount3"  : 7,
		"file6"    : "/open/mogi/castle/obj/seven5-dark-head",
		"file2"    : "/open/fire-hole/obj/k-pill",
		"file5"    : "/open/fire-hole/obj/g-pill",
	]) );
	set( "light_up", 1 );
	set( "build", 10517 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room175",
	]) );
	set( "long", @LONG
這是機器人一號ㄉ秘密製毒場
到處放著機器人一號ㄉ半成品
由於他是天字第一號ㄉ大懶蟲
所以永遠看不到他ㄉ完美成品
不過他ㄉ願望卻是能有所大成
不過他ㄉ願望卻是能有所大成
所以他正在找人幫他完成願望

做出無人能敵ㄉ毒藥完美毒藥
LONG);
	setup();
	replace_program(ROOM);
}
