inherit ROOM;
void create() {
	set( "short", "百藥祠" );
	set( "object", ([
		"amount6"  : 4,
		"file4"    : "/open/ping/obj/poison_pill",
		"file1"    : "/open/mon/obj/mon-pill",
		"file3"    : "/open/fire-hole/obj/w-pill",
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"file2"    : "/open/fire-hole/obj/r-pill",
		"amount3"  : 80,
		"file6"    : "/open/mogi/castle/obj/sspill",
		"amount5"  : 177,
		"amount4"  : 66,
		"amount2"  : 72,
		"amount1"  : 164,
	]) );
	set( "owner", "kitty" );
	set( "build", 10160 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room354.c",
	]) );
	set( "long", @LONG

    你發現這間房間有一股濃濃的藥草氣息,注意一看原來房間中間有一個冒這渺渺白煙的煉
丹爐,房間四周擺滿了各式的藥草櫃,不管哪一種藥材都是當今世上罕見的珍貴藥材,而還有更
加有價值的是一各擺滿瓶子的櫃子,上面都是花了長久時間提煉出來的藥丸,吃了就算功力大大
提昇也不是不可能.

LONG);
	setup();
	replace_program(ROOM);
}
