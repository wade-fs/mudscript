inherit ROOM;
void create() {
	set( "short", "Suzuka International Racing Course" );
	set( "object", ([
		"amount10" : 1,
		"amount4"  : 1,
		"file4"    : "/obj/gift/bingtang",
		"file10"   : "/obj/gift/lingzhi",
		"file1"    : "/obj/gift/lingzhi",
		"amount3"  : 1,
		"file8"    : "/obj/gift/bingtang",
		"file5"    : "/obj/gift/lingzhi",
		"file3"    : "/obj/gift/bingtang",
		"amount8"  : 1,
		"file6"    : "/obj/gift/bingtang",
		"amount2"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file9"    : "/obj/gift/bingtang",
		"amount9"  : 1,
		"file2"    : "/obj/gift/bingtang",
		"file7"    : "/obj/gift/bingtang",
		"amount5"  : 1,
		"amount1"  : 1,
	]) );
	set( "build", 11233 );
	set( "owner", "ctx" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room486",
	]) );
	set( "long", @LONG
鈴鹿賽道,位於日本,為少數幾個在亞洲比賽的F1賽道 ,通常
本站都排在整個賽季季末,所以一般來說,本站的排位競爭都是相
當激烈的,因為事關車手和車隊積分,這對整年度的排名影響很大
這站的彎道有,S彎道,Degner彎道,Spoon彎道,Hairpin彎道,Tria
ngle彎道。

LONG);
	setup();
	replace_program(ROOM);
}
