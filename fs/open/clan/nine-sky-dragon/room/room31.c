inherit ROOM;
void create() {
	set( "short", "眉飛色舞" );
	set( "owner", "yaoblade" );
	set( "object", ([
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount5"  : 1,
		"amount10" : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount9"  : 1,
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount8"  : 1,
	]) );
	set( "build", 10111 );
	set( "exits", ([
		"east"      : "/open/clan/nine-sky-dragon/room/room26",
	]) );
	set( "long", @LONG
愛的是非對錯已太多　來到眉飛色舞的場合
混合他的衝動　她的寂寞　不計較後果 
理由一百萬個有漏洞　快說破　說破以後最赤裸
事後　愛不愛我　理不理我　關係著結果 
你說　我要　結果　中間不必停留
你說　我要　一轉頭再來過
男的　女的　都不要再等候
自由　自由　現在就要自由 

LONG);
	setup();
	replace_program(ROOM);
}
