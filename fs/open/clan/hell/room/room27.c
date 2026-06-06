inherit ROOM;
void create() {
	set( "short", "$HIW$六色$HIC$龍元$NOR$之界" );
	set( "owner", "neun" );
	set( "object", ([
		"amount1"  : 74,
		"amount2"  : 47,
		"file1"    : "/open/mogi/dragon/obj/power",
		"file2"    : "/open/fire-hole/obj/k-pill",
	]) );
	set( "light_up", 1 );
	set( "build", 10104 );
	set( "exits", ([
		"WWW"       : "/open/clan/hell/room/room71",
		"BBB"       : "/open/clan/hell/room/room70",
		"YYY"       : "/open/clan/hell/room/room74",
		"east"      : "/open/clan/hell/room/room23.c",
		"RRR"       : "/open/clan/hell/room/room73",
		"GGG"       : "/open/clan/hell/room/room68",
		"PPP"       : "/open/clan/hell/room/room69.c",
		"SSS"       : "/open/clan/hell/room/room72.c",
	]) );
	set( "long", @LONG
相傳打死傳說中的六色火龍,可以得到牠們身上增加大幅能力的精元,為了增加
本幫的戰力,幫主會將收集來的精元存放於此處,用來當做幫中出動的時候,可以增加
幫眾的能力,所以此處的守衛也是相當嚴密的,若是被幫主發現有人擅自拿走這裡的
精元,必將遭到全地府的追殺

LONG);
	setup();
	replace_program(ROOM);
}
