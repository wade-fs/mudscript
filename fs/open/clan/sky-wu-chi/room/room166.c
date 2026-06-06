inherit ROOM;
void create() {
	set( "short", "山間小路" );
	set( "owner", "herononame" );
	set( "object", ([
		"amount4"  : 1,
		"file6"    : "/open/mogi/castle/obj/sspill",
		"amount7"  : 1,
		"amount5"  : 1,
		"file8"    : "/obj/gift/bingtang",
		"amount1"  : 1,
		"file1"    : "/daemon/class/dancer/bee_flute",
		"file5"    : "/obj/gift/xisuidan",
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"file7"    : "/obj/gift/bingtang",
		"amount2"  : 9,
		"amount8"  : 1,
		"amount6"  : 3,
		"file4"    : "/obj/gift/hobowdan",
	]) );
	set( "light_up", 1 );
	set( "build", 10880 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"south"     : "/open/clan/sky-wu-chi/room/room163",
	]) );
	set( "long", @LONG
這裡是翠峰的山腳下，聽附近的居民說這裡不但風景美
麗，據說還有神仙出沒喔，因此你懷著朝聖般的心情來到這
，心中期盼能看到傳說中的神仙，走在山間的小路上，心中
響起了村中孩童所說的話：『上次我在山上看到一位美麗的
大姐姐耶，她跳的舞好好看喔，就像仙女下凡一樣』，想到
這，你不禁加快了腳步，往山上走去。
LONG);
	setup();
	replace_program(ROOM);
}
