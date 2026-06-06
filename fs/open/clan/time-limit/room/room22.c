inherit ROOM;
void create() {
	set( "short", "$BWHT$電力機房$NOR$" );
	set( "owner", "kerr" );
	set( "exits", ([
		"down"      : "/open/clan/time-limit/room/room77",
	]) );
	set( "long", @LONG
說不出的高溫充滿整個房間, 除了排放整齊的變壓系統, 還有一陣吵雜的聲音原
來是發電機的備機聲音, 還沒啟動就讓人受不了, 如何能想像斷電時啟動的巨響
這間機房可以說是整個廠房的動力來源, 不管再任何角落, 作哪種工作, 沒有穩
定的電力供應, 怎能讓生產順利運作.

LONG);
	setup();
	replace_program(ROOM);
}
