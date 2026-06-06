inherit ROOM;
void create() {
	set( "short", "小敏練功房" );
	set( "object", ([
		"file10"   : "/open/fire-hole/obj/r-pill",
		"amount5"  : 346,
		"file9"    : "/open/fire-hole/obj/k-pill",
		"file8"    : "/open/mogi/castle/obj/sspill",
		"file5"    : "/open/mon/obj/mon-pill",
		"amount6"  : 88,
		"file4"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount7"  : 296,
		"file1"    : "/open/fire-hole/obj/g-pill",
		"amount8"  : 136,
		"amount2"  : 44,
		"amount1"  : 349,
		"amount9"  : 14,
		"amount10" : 87,
		"amount3"  : 696,
		"file6"    : "/open/fire-hole/obj/w-pill",
		"file3"    : "/open/ping/obj/poison_pill",
		"amount4"  : 1,
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"file2"    : "/open/fire-hole/obj/b-pill",
	]) );
	set( "owner", "dandy" );
	set( "light_up", 1 );
	set( "build", 10054 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room197.c",
		"west"      : "/open/clan/ou-cloud-club/room/room235",
	]) );
	set( "long", @LONG
在未進入房間前，陣陣的寒氣已逼迫讓人透不過氣來，推開
厚重的石門進入房間內，迎面而來的的凜然氣息更是讓武功底子
較差的人猛打哆嗦，不難看出屋子的主人所練的內功乃是走因寒
路線。屋子中什麼都沒有，唯一引人注目的是擺設在屋子中央的
一張特殊的床，一張散發出高熱的床，看來是小敏用來練內功的
法寶。

LONG);
	setup();
	replace_program(ROOM);
}
