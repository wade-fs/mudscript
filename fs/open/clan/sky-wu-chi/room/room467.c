inherit ROOM;
void create() {
	set( "short", "九層塔八樓" );
	set( "owner", "intel" );
	set( "object", ([
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount7"  : 1,
		"amount9"  : 1,
		"file7"    : "/open/magic-manor/obj/master_snake_head",
		"amount8"  : 1,
		"amount3"  : 1,
		"file8"    : "/open/magic-manor/obj/master_snake_head",
		"file4"    : "/open/gblade/obj/sa-head",
		"amount6"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10219 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"down"      : "/open/clan/sky-wu-chi/room/room466.c",
		"out"       : "/open/clan/sky-wu-chi/room/room441",
		"up"        : "/open/clan/sky-wu-chi/room/room468.c",
	]) );
	set( "long", @LONG
這裡是九曾塔的第八樓，旁邊有各式各樣的模具和模型，但是樣子都很像是
從惡魔化出來的分身，兇神惡煞！當你的眼神跟它正面交鋒時，好像靈魂快被它
吸過去一樣，所以你在這都感到魂身不對正。偏偏這裡到處都是長的一樣，你已
不曉得你身在何方了。
LONG);
	setup();
	replace_program(ROOM);
}
