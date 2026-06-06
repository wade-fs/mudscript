inherit ROOM;
void create() {
	set( "short", "還是要說再見" );
	set( "owner", "yaoblade" );
	set( "object", ([
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount8"  : 1,
		"amount9"  : 1,
		"amount7"  : 1,
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount10" : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount6"  : 1,
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10704 );
	set( "exits", ([
		"north"     : "/open/clan/nine-sky-dragon/room/room26",
	]) );
	set( "long", @LONG
還是要說再見 就算不情願 今天會因離別更珍貴 
我從不懷疑 有一天再見面 聽你說你的夢想都實現 
你今天的眼睛快讓我多看幾眼 在我寂寞的時候 能懷念 
可是別擔心我 勇敢向前 因為你的祝福 會陪在我身邊 
你發現的世界 我看得見 喔~ Repeat 
不必太多的行李 需要的只是信念 每個陌生得邀請 都感謝 
我不害怕說出 真的感覺 因為答應過你 永遠純真不變 
我走過的世界 你會看見 喔~ Repeat 
LONG);
	setup();
	replace_program(ROOM);
}
