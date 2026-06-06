inherit ROOM;
void create() {
	set( "short", "九層塔三樓" );
	set( "owner", "intel" );
	set( "object", ([
		"amount9"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount2"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-helmet",
	]) );
	set( "build", 10951 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"down"      : "/open/clan/sky-wu-chi/room/room461.c",
		"out"       : "/open/clan/sky-wu-chi/room/room441",
		"up"        : "/open/clan/sky-wu-chi/room/room463.c",
	]) );
	set( "long", @LONG
這裡是九曾塔的第三樓，旁邊有各式各樣的模具和模型，但是樣子都很像是
從惡魔化出來的分身，兇神惡煞！當你的眼神跟它正面交鋒時，好像靈魂快被它
吸過去一樣，所以你在這都感到魂身不對正。偏偏這裡到處都是長的一樣，你已
不曉得你身在何方了。
LONG);
	setup();
	replace_program(ROOM);
}
