inherit ROOM;
void create() {
	set( "short", "九層塔二樓" );
	set( "owner", "intel" );
	set( "object", ([
		"file10"   : "/open/magic-manor/obj/hwa-je-icer",
		"amount3"  : 1,
		"amount10" : 1,
		"amount5"  : 1,
		"amount4"  : 1,
		"file5"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file3"    : "/open/capital/obj/blade_book",
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"file8"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount8"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/capital/obj/blade_book",
	]) );
	set( "build", 11303 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"down"      : "/open/clan/sky-wu-chi/room/room460.c",
		"out"       : "/open/clan/sky-wu-chi/room/room441.c",
		"up"        : "/open/clan/sky-wu-chi/room/room462.c",
	]) );
	set( "long", @LONG
這裡是九曾塔的第二樓，旁邊有各式各樣的模具和模型，但是樣子都很像是
從惡魔化出來的分身，兇神惡煞！當你的眼神跟它正面交鋒時，好像靈魂快被它
吸過去一樣，所以你在這都感到魂身不對正。偏偏這裡到處都是長的一樣，你已
不曉得你身在何方了。
LONG);
	setup();
	replace_program(ROOM);
}
