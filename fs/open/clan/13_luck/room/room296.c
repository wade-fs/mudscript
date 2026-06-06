inherit ROOM;
void create() {
	set( "short", "小豬頭的北廂房" );
	set( "object", ([
		"file7"    : "/open/doctor/pill/human_pill",
		"amount2"  : 1,
		"amount10" : 1,
		"file9"    : "/open/killer/headkill/obj/f_dag",
		"file2"    : "/open/tendo/obj/chaosbelt",
		"file6"    : "/open/killer/obj/k_ring",
		"file5"    : "/open/mogi/castle/obj/sspill",
		"amount9"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"amount7"  : 12,
		"amount5"  : 2,
		"file10"   : "/open/mon/obj/ghost-legging",
		"file3"    : "/open/wind-rain/obj/bird-blade",
	]) );
	set( "owner", "pighead" );
	set( "build", 10491 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room127",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    這裡是可愛小豬頭的北廂房，這邊主要是儲存一些重要的藥品，
例如九轉熊蛇丸，六色龍的藥丸，都是在戰鬥中不可缺乏的藥品，如
果沒了它們，那是要如何抵抗狂想空間中的變態怪物，所以這裡的存
放的藥品都是很珍貴的。

LONG);
	setup();
	replace_program(ROOM);
}
