inherit ROOM;
void create() {
	set( "short", "寒霜居-武器庫" );
	set( "owner", "poisoner" );
	set( "object", ([
		"amount3"  : 1,
		"amount9"  : 1,
		"amount2"  : 7,
		"amount7"  : 10000,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/doctor/pill/gnd_pill",
		"amount4"  : 468,
		"file8"    : "/open/mogi/dragon/obj/dragon-head",
		"file5"    : "/obj/poison/rose_poison",
		"file6"    : "/obj/poison/dark_poison",
		"amount5"  : 10925,
		"file7"    : "/obj/poison/five_poison",
		"file4"    : "/obj/poison/faint_poison",
		"amount6"  : 8600,
		"file3"    : "/open/mogi/dragon/obj/dragon-head",
		"file1"    : "/open/ghost-hole/obj/light-spirit",
		"amount1"  : 1,
		"amount8"  : 1,
	]) );
	set( "build", 10355 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room241.c",
	]) );
	set( "long", @LONG
在這滿是渾天水晶所建成的房間中，表面看起來與東邊的寒霜
居沒什麼不同。當你準備要離去之時，突然一陣豪光從你背後射來
，速度之迅速令你閃無可閃，原以為是中了暗器，心想完了！但當
你定心一看才發覺一點傷也沒有。好奇心慫恿下，向那道光芒的來
處一看才發覺原來在水晶璧中擺放著八隻各具異能的絕世兵器  

殺手─閻匕影螫魂　　惡人─魔爪混天殺　　聖火─化劫菱歸真　
魔刀─刀斬邪元歸　　金刀─幔羅刀無影　　仙劍─楓映天蓮劍
段家─凌微雲扇飄　　舞者─雷火彩鳳翔

LONG);
	setup();
	replace_program(ROOM);
}
