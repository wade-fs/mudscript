inherit ROOM;
void create() {
	set( "short", "『玄天伏魔陣』" );
	set( "owner", "poll" );
	set( "object", ([
		"amount6"  : 1,
		"amount10" : 1,
		"file5"    : "/open/killer/headkill/obj/w_dag",
		"amount8"  : 1,
		"file4"    : "/open/killer/headkill/obj/w_dag",
		"file8"    : "/open/killer/headkill/obj/w_dag",
		"file6"    : "/open/killer/headkill/obj/w_dag",
		"amount5"  : 1,
		"file9"    : "/open/killer/headkill/obj/w_dag",
		"amount9"  : 1,
		"file10"   : "/open/killer/headkill/obj/w_dag",
		"amount7"  : 1,
		"file2"    : "/open/killer/headkill/obj/w_dag",
		"amount4"  : 1,
		"file7"    : "/open/killer/headkill/obj/w_dag",
		"file1"    : "/open/killer/headkill/obj/w_dag",
		"amount1"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10063 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room454",
		"south"     : "/open/clan/13_luck/room/room452",
	]) );
	set( "long", @LONG

     糟了！！！你突然發現你被包圍了，這裡是墨教所布的玄天伏魔陣，
 在這裡再頑強的敵人，也素手無策，而這個陣除了防止敵人的入侵之外，
 當你學成時也可以來這試試身手，總教頭會依照你的武功給於你應有的職
 位喔，但是在你還沒有自信之前，可千萬不要輕易嘗試，說不定會送了你
 一條小命。

LONG);
	setup();
	replace_program(ROOM);
}
