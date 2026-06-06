inherit ROOM;
void create() {
	set( "short", "九層塔四樓" );
	set( "owner", "intel" );
	set( "object", ([
		"amount8"  : 1,
		"file7"    : "/open/magic-manor/obj/master_snake_head",
		"file2"    : "/open/magic-manor/obj/master_snake_head",
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/obj/master_snake_head",
		"amount3"  : 1,
		"file8"    : "/open/gblade/obj/sa-head",
		"amount2"  : 1,
		"file3"    : "/open/gblade/obj/sa-head",
		"amount7"  : 1,
	]) );
	set( "build", 10702 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"down"      : "/open/clan/sky-wu-chi/room/room462.c",
		"out"       : "/open/clan/sky-wu-chi/room/room441",
		"up"        : "/open/clan/sky-wu-chi/room/room464.c",
	]) );
	set( "long", @LONG
這裡是九曾塔的第四樓，旁邊有各式各樣的模具和模型，但是樣子都很像是
從惡魔化出來的分身，兇神惡煞！當你的眼神跟它正面交鋒時，好像靈魂快被它
吸過去一樣，所以你在這都感到魂身不對正。偏偏這裡到處都是長的一樣，你已
不曉得你身在何方了。
LONG);
	setup();
	replace_program(ROOM);
}
