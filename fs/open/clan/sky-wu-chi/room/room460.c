inherit ROOM;
void create() {
	set( "short", "九層塔一樓" );
	set( "owner", "intel" );
	set( "object", ([
		"amount3"  : 2041,
		"amount4"  : 1783,
		"amount6"  : 1,
		"file4"    : "/obj/poison/rose_poison",
		"file3"    : "/obj/poison/five_poison",
		"file2"    : "/obj/poison/faint_poison",
		"file10"   : "/open/killer/obj/kill_yar_head",
		"amount10" : 1,
		"amount1"  : 2031,
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file1"    : "/obj/poison/dark_poison",
		"file6"    : "/obj/gift/hobowdan",
		"amount2"  : 1353,
	]) );
	set( "build", 31185 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"out"       : "/open/clan/sky-wu-chi/room/room441.c",
		"up"        : "/open/clan/sky-wu-chi/room/room461.c",
	]) );
	set( "long", @LONG
這裡是九曾塔的第一樓，旁邊有各式各樣的模具和模型，但是樣子都很像是
從惡魔化出來的分身，兇神惡煞！當你的眼神跟它正面交鋒時，好像靈魂快被它
吸過去一樣，所以你在這都感到魂身不對正。偏偏這裡到處都是長的一樣，你已
不曉得你身在何方了。
LONG);
	setup();
	replace_program(ROOM);
}
