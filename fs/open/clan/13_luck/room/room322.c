inherit ROOM;
void create() {
	set( "short", "吉祥置物櫃乙" );
	set( "owner", "amdxp" );
	set( "object", ([
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount2"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount5"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount3"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount1"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount6"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-armband",
	]) );
	set( "build", 10074 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room298",
	]) );
	set( "long", @LONG

    這裡是吉祥置物櫃乙，專門為還沒有房間的新進幫眾所設立的，此
環境優雅舒適，讓新進的幫眾有個可以去的地方跟休息的地方，使他們
快點成為十三吉祥的戰力，一起為幫派的未來而努力，一同打拼，負重
全憑基礎力，儘高端賴棟樑材，希望能為天下第一大幫而邁進。

LONG);
	setup();
	replace_program(ROOM);
}
