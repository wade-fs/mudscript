inherit ROOM;
void create() {
	set( "short", "$HIC$齊雲峰$NOR$" );
	set( "owner", "vatsu" );
	set( "object", ([
		"amount4"  : 1,
		"file6"    : "/open/gsword/obj1/bbladeball",
		"file2"    : "/open/gsword/obj1/bbladeball",
		"amount3"  : 1,
		"file10"   : "/open/gsword/obj1/bbladeball",
		"file5"    : "/open/gsword/obj1/bbladeball",
		"amount9"  : 1,
		"file9"    : "/open/gsword/obj1/bbladeball",
		"file3"    : "/open/gsword/obj1/bbladeball",
		"amount2"  : 1,
		"file4"    : "/open/gsword/obj1/bbladeball",
		"amount6"  : 1,
		"file8"    : "/open/gsword/obj1/bbladeball",
		"amount10" : 1,
		"amount5"  : 1,
		"amount8"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/gsword/obj1/bbladeball",
	]) );
	set( "build", 10104 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room99",
		"west"      : "/open/clan/hell/room/room97",
	]) );
	set( "long", @LONG
當你醒來只見自己正在一棵突出於山崖旁的老樹上,
只聽見樹幹吱吱的響著，像是要斷裂般, 此時你看到樹旁
有幾條老藤上面不知通往何處, 你想你或許可以試著爬上
去, 還是你想繼續往下跳呢??
  「少帥」寇仲(Master kal)
  「邪王」石之軒(Shen)

LONG);
	setup();
	replace_program(ROOM);
}
