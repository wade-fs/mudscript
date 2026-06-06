inherit ROOM;
void create() {
	set( "short", "EMC 華亞營區" );
	set( "owner", "adeyzit" );
	set( "object", ([
		"file1"    : "/daemon/class/blademan/obj/iceblade",
		"amount1"  : 1,
	]) );
	set( "build", 10224 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room75",
		"north"     : "/open/clan/13_luck/room/room111.c",
		"west"      : "/open/clan/13_luck/room/room110.c",
		"east"      : "/open/clan/13_luck/room/room112.c",
		"south"     : "/open/clan/13_luck/room/room109",
	]) );
	set( "long", @LONG
一進營區,看到一區區隔開的營辦公室,旁邊還有營長室,餐廳,作戰室跟會客室
另一邊有一區是軍械室跟雜物庫房,大門旁有繩索下去,放著悍馬跟大卡的地方
在營辦旁邊有著RE-3000公尺跑步場地,CE-單槓場地,令一邊有著RS-五百障礙場
CS-射擊靶場,另一區更有ESD炸彈試爆場地,EFT 震撼教育場,等等個式場地
LONG);
	setup();
	replace_program(ROOM);
}
