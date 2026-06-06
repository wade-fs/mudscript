inherit ROOM;
void create() {
	set( "short", "小白菜的緞帶房" );
	set( "owner", "sski" );
	set( "object", ([
		"amount7"  : 1,
		"file7"    : "/open/killer/weapon/k_torch",
		"file3"    : "/open/mogi/castle/obj/sspill",
		"amount6"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/gsword/obj/ring-1",
		"file6"    : "/open/port/obj/wolf_ring",
		"amount2"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"file8"    : "/open/capital/room/king/obj/dagger1",
		"file5"    : "/open/gsword/obj/ring-1",
		"file2"    : "/open/love/obj/cloth1",
		"amount3"  : 2,
		"amount8"  : 1,
		"file1"    : "/open/gsword/obj/yuskirt",
	]) );
	set( "build", 10116 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room227",
		"east"      : "/open/clan/sky-wu-chi/room/room123.c",
	]) );
	set( "long", @LONG
顧明思議,這裡就是小白菜的放置武器的地方了,而這裡都放些
什麼東西呢,你可以四處來看看,但我八成看你一定想不通這裡怎
麼全都是一些緞帶呢,而這些緞帶為啥會是小白菜的武器呢..你
就不禁的拿起了其中一個緞帶來看,哇賽,不看還好,看了之後你
直呼這真的是好兵器ㄚ..原來這個緞帶就叫做楓之舞(Maple ribbon)

LONG);
	setup();
	replace_program(ROOM);
}
