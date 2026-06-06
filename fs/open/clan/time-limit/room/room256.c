inherit ROOM;
void create() {
	set( "short", "$HIB$巨$HIR$書$HIC$岩$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/ping/obj/liu-head",
		"file6"    : "/open/ping/obj/liu-head",
		"file2"    : "/open/ping/obj/liu-head",
		"file3"    : "/open/ping/obj/liu-head",
		"file8"    : "/open/ping/obj/liu-head",
		"amount4"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/ping/obj/liu-head",
		"file9"    : "/open/ping/obj/liu-head",
		"amount8"  : 1,
		"file10"   : "/open/ping/obj/liu-head",
		"amount5"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"amount2"  : 1,
		"file5"    : "/open/ping/obj/liu-head",
		"amount3"  : 1,
		"file7"    : "/open/ping/obj/liu-head",
		"amount7"  : 1,
	]) );
	set( "owner", "auo" );
	set( "build", 10476 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room257",
	]) );
	set( "long", @LONG
巨書顧名思義就是巨大的書,是由石頭做作成的書,每一頁的書都有10萬斤的重量,而且
每掀一頁重量就會累加上去,實力不夠的人將會被巨書壓得喘不過氣,巨書裡所紀載的是
古今神器十八種,也就是說巨書總共有十八頁,當掀開巨書時,只要撐住書的重量,太黃君
就會為你解說此頁神兵的歷史由來及特色,不過聽說巨書岩底部另有玄機,只是沒有人能
掀起十八頁的巨書,也就無從證實起

LONG);
	setup();
	replace_program(ROOM);
}
