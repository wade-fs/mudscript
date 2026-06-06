inherit ROOM;
void create() {
	set( "short", "$BRED$時$BGRN$空$BYEL$倉$BBLU$庫$BMAG$之$NOR$$MAG$舞者$NOR$" );
	set( "object", ([
		"file5"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file4"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file3"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file6"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file7"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file1"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount9"  : 1,
		"amount1"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount7"  : 1,
		"amount8"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"file9"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file10"   : "/open/magic-manor/obj/fire-color-ribbon",
		"amount2"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"file8"    : "/open/magic-manor/obj/fire-color-ribbon",
	]) );
	set( "build", 10324 );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room91",
		"south"     : "/open/clan/time-limit/room/room85.c",
	]) );
	set( "long", @LONG
雷火彩鳳翔(Fire-color-ribbon),嫵情生所使用的武器,為一神秘鑄將精心鑄造
的「八色靈器」之一,周身不時的泛出七彩的光芒,是最美的武器之一,嫵情生是
聚靈八傑中最難纏的角色,一開始戰鬥就會使用玄冰結界,玄冰結界會將你的攻擊
反彈回來並加倍損失,在氣血剩下一半時會用水月神鏡,水月神鏡會提高數倍的
防禦力,而雷火彩鳳翔除了當武器使用外,也是聚靈道裡通行的鑰匙

LONG);
	setup();
	replace_program(ROOM);
}
