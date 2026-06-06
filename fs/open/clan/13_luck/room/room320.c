inherit ROOM;
void create() {
	set( "short", "吉祥置物櫃丁" );
	set( "owner", "zmud" );
	set( "object", ([
		"file10"   : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount10" : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount9"  : 1,
		"amount2"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount1"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount3"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount4"  : 1,
	]) );
	set( "build", 10293 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room300",
	]) );
	set( "long", @LONG

    這裡是吉祥置物櫃丁，專門為還沒有房間的新進幫眾所設立的，此
環境優雅舒適，讓新進的幫眾有個可以去的地方跟休息的地方，使他們
快點成為十三吉祥的戰力，一起為幫派的未來而努力，一同打拼，負重
全憑基礎力，儘高端賴棟樑材，希望能為天下第一大幫而邁進。

LONG);
	setup();
	replace_program(ROOM);
}
