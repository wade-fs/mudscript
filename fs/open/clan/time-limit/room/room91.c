inherit ROOM;
void create() {
	set( "short", "$BRED$時$BGRN$空$BYEL$倉$BBLU$庫$BMAG$之$CYN$聖火$NOR$" );
	set( "object", ([
		"amount5"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/magic-manor/obj/hwa-je-icer",
		"file2"    : "/open/magic-manor/obj/hwa-je-icer",
		"file5"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/obj/hwa-je-icer",
		"file6"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount9"  : 1,
		"amount10" : 1,
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"file7"    : "/open/magic-manor/obj/hwa-je-icer",
		"file8"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount8"  : 1,
		"file1"    : "/open/magic-manor/obj/hwa-je-icer",
		"file3"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount1"  : 1,
	]) );
	set( "build", 10037 );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room90.c",
		"west"      : "/open/clan/time-limit/room/room84",
		"south"     : "/open/clan/time-limit/room/room97.c",
	]) );
	set( "long", @LONG
化劫菱歸真(Hwa-je-icer),寂元子所使用的武器,為一神秘鑄將精心鑄造的
「八色靈器」之一,菱身隱隱透出黑白兩股氣勁,寂元子會在戰鬥一開始就使
出化劫,馬上讓人陷入苦戰,還會用歸真打掉en的skill,是個麻煩的對手,而
化劫菱歸真除了當武器使用外,也是聚靈道裡通行的鑰匙

LONG);
	setup();
	replace_program(ROOM);
}
