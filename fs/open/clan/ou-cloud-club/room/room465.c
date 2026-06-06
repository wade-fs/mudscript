inherit ROOM;
void create() {
	set( "short", "毒氣室" );
	set( "object", ([
		"file10"   : "/obj/gift/xisuidan",
		"amount2"  : 1,
		"file9"    : "/obj/gift/xisuidan",
		"file5"    : "/obj/gift/xisuidan",
		"amount4"  : 1,
		"amount5"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"amount9"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"file7"    : "/obj/gift/xisuidan",
		"file3"    : "/obj/gift/xisuidan",
		"file8"    : "/obj/gift/xisuidan",
		"amount8"  : 1,
		"file1"    : "/obj/gift/xisuidan",
		"amount1"  : 1,
		"file4"    : "/obj/gift/xisuidan",
		"file2"    : "/obj/gift/xisuidan",
		"file6"    : "/obj/gift/xisuidan",
	]) );
	set( "build", 10074 );
	set( "owner", "ctx" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room469",
	]) );
	set( "long", @LONG
進入這裡前,除非你就是那隻白老鼠,否則千萬別忘了戴防毒
面具, 因為這裡就是不折不扣的一個標準負責在作毒氣的研究室
在這裡從以前的芥子毒氣,到現在VX毒氣以及沙林毒氣等等,這裡
通通都有研究過,如果看某人不爽想要用毒氣毒他的話,有本事的
話就到這個毒氣室來拿吧。

LONG);
	setup();
	replace_program(ROOM);
}
