inherit ROOM;
void create() {
	set( "short", "$HIY$香蕉週刊$HIM$AV$HIW$編輯部$NOR$ " );
	set( "object", ([
		"file1"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount1"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/magic-manor/obj/lin-cloud-fan",
	]) );
	set( "owner", "blur" );
	set( "build", 10230 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/hell/room/room47.c",
		"east"      : "/open/clan/hell/room/room93.c",
		"south"     : "/open/clan/hell/room/room49.c",
	]) );
	set( "long", @LONG
大飛...kalin的小弟...
目前正跟浩南搶銅鑼灣的扛霸子..
由於致力培植勢力,所以創立了香蕉週刊..
希望可以帶來一些仰慕者...
由於AV部是香蕉週刊的心臟部門..
也是大飛的專長...
所以大飛閒來無事都在這裡研究研究....
看他投入的樣子...正是符合認真的流氓最帥這句話....
LONG);
	setup();
	replace_program(ROOM);
}
