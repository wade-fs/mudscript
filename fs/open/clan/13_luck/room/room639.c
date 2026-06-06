inherit ROOM;
void create() {
	set( "short", "驚雲閣防具室" );
	set( "object", ([
		"amount10" : 1,
		"amount4"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount9"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount1"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-gem",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount6"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount5"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-cloak",
	]) );
	set( "build", 10019 );
	set( "light_up", 1 );
	set( "owner", "soul" );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room640",
	]) );
	set( "long", @LONG

    四周擺滿了各式各樣的防具，都是主人精心收集而來，
並陳列得很整齊。主人常使用這邊的裝備，四處征戰，為了
追求武學的極致。    
    四周擺滿了各式各樣的防具，都是主人精心收集而來，
並陳列得很整齊。主人常使用這邊的裝備，四處征戰，為了
追求武學的極致。

LONG);
	setup();
	replace_program(ROOM);
}
