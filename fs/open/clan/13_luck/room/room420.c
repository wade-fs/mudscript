inherit ROOM;
void create() {
	set( "short", "吉祥廣場三" );
	set( "object", ([
		"file10"   : "/obj/gift/bingtang",
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"file4"    : "/obj/gift/lingzhi",
		"file3"    : "/obj/gift/shenliwan",
		"file1"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file5"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"file7"    : "/open/fire-hole/obj/w-pill",
		"amount5"  : 1,
		"file6"    : "/open/fire-hole/obj/r-pill",
		"file9"    : "/obj/gift/bingtang",
		"amount9"  : 1,
		"amount6"  : 79,
		"amount3"  : 1,
		"amount8"  : 86,
		"amount2"  : 396,
		"file8"    : "/open/fire-hole/obj/w-pill",
		"amount7"  : 4,
		"amount1"  : 6,
		"amount10" : 1,
		"amount4"  : 1,
	]) );
	set( "owner", "mwf" );
	set( "build", 10122 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room419",
		"south"     : "/open/clan/13_luck/room/room421.c",
	]) );
	set( "long", @LONG

    再往北走去就是十三吉祥的大門了，看起來守衛非常森嚴，南方可以
登上剛才看到的高臺，但是高臺好像也有士兵在防守，畢竟制高點不是可
以讓人那麼容易就上去的，除了南北兩條路以外，左右兩邊都通往吉祥廣
場。

LONG);
	setup();
	replace_program(ROOM);
}
