inherit ROOM;
void create() {
	set( "short", "天晴的小窩" );
	set( "owner", "skyppitt" );
	set( "object", ([
		"file6"    : "/open/fire-hole/obj/r-pill",
		"amount8"  : 26,
		"file9"    : "/open/mon/obj/mon-pill",
		"file3"    : "/open/fire-hole/obj/w-pill",
		"amount1"  : 33,
		"file5"    : "/obj/stone/powder",
		"file2"    : "/open/mogi/castle/obj/sspill",
		"amount4"  : 51,
		"file1"    : "/open/fire-hole/obj/b-pill",
		"amount5"  : 37,
		"amount3"  : 75,
		"amount2"  : 90,
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"amount9"  : 60,
		"amount10" : 1,
		"file4"    : "/open/fire-hole/obj/g-pill",
		"amount7"  : 380,
		"file10"   : "/open/gsword/obj1/blosword",
		"file8"    : "/open/fire-hole/obj/y-pill",
		"amount6"  : 87,
	]) );
	set( "build", 10471 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room670",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    這裡是天晴的小窩，四周堆滿著實驗的儀器，其實他是個苦命的研
究生，原本他來這裡只是想要回憶一下以前mud 的感覺，沒想到又跳入
這個火坑了，雖然玩過了其他的online game，但是看來他還是覺得mud
比較好玩，或許這種追逐數字的遊戲對他比較有吸引力吧!!

LONG);
	setup();
	replace_program(ROOM);
}
