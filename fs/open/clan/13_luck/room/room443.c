inherit ROOM;
void create() {
	set( "short", "幻世錄2故事背景1" );
	set( "object", ([
		"amount1"  : 1,
		"amount5"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "owner", "dfyw" );
	set( "build", 10047 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room426",
		"down"      : "/open/clan/13_luck/room/room368.c",
		"west"      : "/open/clan/13_luck/room/room442.c",
		"east"      : "/open/clan/13_luck/room/room441.c",
		"south"     : "/open/clan/13_luck/room/room427.c",
	]) );
	set( "long", @LONG

在遠古天地創造之初的時代，
眾神在這片世界最大的土地上，
同時撒下了五種生命的種子，希望豐富這塊大地，
為使生命得以延續，眾神並同時也給了他們生存的智慧，
使五種生命有了自己的族群，也有了自己的文化，
並且為這塊土地取名為伊伯爾大陸(眾神的祝福之意)，
這五個種族分別為人類、妖精、翼人、獸人及像爬蟲的兩棲類。s

LONG);
	setup();
	replace_program(ROOM);
}
