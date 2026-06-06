inherit ROOM;
void create() {
	set( "short", "$BRED$時$BGRN$空$BYEL$倉$BBLU$庫$BMAG$之$NOR$$RED$殺手$NOR$" );
	set( "object", ([
		"amount5"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/magic-manor/obj/dark-soul-dagger",
		"file2"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file5"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file6"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount9"  : 1,
		"amount10" : 1,
		"file4"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file8"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file7"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount8"  : 1,
		"file3"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file1"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount1"  : 1,
	]) );
	set( "build", 10109 );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room97",
		"north"     : "/open/clan/time-limit/room/room84",
		"south"     : "/open/clan/time-limit/room/room86",
	]) );
	set( "long", @LONG
閻匕影螫魂(Dark-soul-dagger),柔媚生所使用的武器,為一神秘鑄將精心鑄造
的「八色靈器」之一,匕身散出陣陣白霧,煞是好看,柔媚生是位傳說中的殺手,
魔氣殺配合殺意魔戒可以讓你動彈不得,清風術可以讓柔媚生身法增加數倍以閃
避你的攻擊,而閻匕影螫魂除了當武器使用外,也是聚靈道裡通行的鑰匙

LONG);
	setup();
	replace_program(ROOM);
}
