inherit ROOM;
void create() {
	set( "short", "小豬頭的西廂房" );
	set( "owner", "pighead" );
	set( "object", ([
		"file7"    : "/open/capital/obj/blade2",
		"amount10" : 10,
		"file9"    : "/open/killer/memory/static",
		"amount4"  : 1,
		"file1"    : "/open/fire-hole/obj/p-pill",
		"amount1"  : 25,
		"file6"    : "/open/wind-rain/obj/sun_red_cloth",
		"file4"    : "/obj/gift/shenliwan",
		"file5"    : "/open/gsword/obj/may_ring",
		"amount9"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"amount5"  : 1,
		"file10"   : "/open/magic-manor/ghost/obj/trigram-pill",
	]) );
	set( "build", 10296 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room127",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    這裡是可愛小豬頭的西廂房，這邊主要是儲存戰鬥用的武器，例
如騏驎神刀，靈器夜千鳥，厚背紫金刀，等都是在戰鬥中不可缺乏的
武器，如果沒了它們，那是要如何抵抗狂想空間中的變態怪物，所以
這裡的存放的武器都是很珍貴的。

LONG);
	setup();
	replace_program(ROOM);
}
