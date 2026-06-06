inherit ROOM;
void create() {
	set( "short", "$HIG$斜角巷$HIM$廣場$NOR$" );
	set( "owner", "soilclaw" );
	set( "object", ([
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"file1"    : "/open/magic-manor/soil/obj/soil-claw",
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount2"  : 1,
		"file6"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount4"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount1"  : 1,
	]) );
	set( "build", 10696 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room44",
		"north"     : "/open/clan/time-limit/room/room47.c",
		"south"     : "/open/clan/time-limit/room/room48.c",
		"east"      : "/open/clan/time-limit/room/room52.c",
	]) );
	set( "long", @LONG
斜角巷中心的廣場上有個噴水池,噴水池中有個女巫的雕像拿著水瓶倒水,
路旁的貓頭鷹商店有著數百隻的貓頭鷹等著出售,書店則是有著一堆學生
前往購買新學期所需的新書,魁地奇商品店則是擠滿圍觀的人群,
等不急要看最新出產的飛天掃帚,旁邊有條小路則是通往夜行巷

LONG);
	setup();
	replace_program(ROOM);
}
