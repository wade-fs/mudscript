inherit ROOM;
void create() {
	set( "short", "寒霜居-防具庫" );
	set( "owner", "holeman" );
	set( "object", ([
		"file4"    : "/open/mogi/dragon/obj/dragon-head",
		"amount7"  : 1,
		"amount2"  : 1,
		"file7"    : "/open/mogi/dragon/obj/dragon-head",
		"file5"    : "/open/mogi/dragon/obj/dragon-head",
		"amount4"  : 1,
		"amount1"  : 1,
		"file10"   : "/open/mogi/dragon/obj/dragon-head",
		"file6"    : "/open/mogi/dragon/obj/dragon-head",
		"amount3"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
		"file2"    : "/open/gblade/obj/sa-head",
		"file3"    : "/open/gblade/obj/sa-head",
		"file1"    : "/open/gblade/obj/sa-head",
		"amount5"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 11936 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room241",
	]) );
	set( "long", @LONG
在這滿是渾天水晶所建成的房間中，表面看起來與西邊的寒霜
居沒什麼不同。當你準備要離去之時，突然一陣豪光從你背後射來
，速度之迅速令你閃無可閃，原以為是中了暗器，心想完了！但當
你定心一看才發覺一點傷也沒有。好奇心慫恿下，向那道光芒的來
處一看才發覺原來在水晶璧中擺放一套堪稱全狂想防禦力最高的虹
晶裝備，分別為　虹晶頭釵(diamond hairpin)　
　　　　　　　　虹晶雙翼鎧(diamond armor)
　　　　　　　　虹晶識皇披風(diamond cloak)
　　　　　　　　虹晶狂牙手套(diamond hands)
　　　　　　　　虹晶鈗鋮腰帶(diamond belt)
　　　　　　　　虹晶紫裙(diamond skirt)
　　　　　　　　虹晶疾風護膝(diamond legging)
　　　　　　　　虹晶神行靴(diamond boots)
LONG);
	setup();
	replace_program(ROOM);
}
