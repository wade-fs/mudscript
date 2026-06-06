inherit ROOM;
void create() {
	set( "short", "$BRED$時$BGRN$空$BYEL$倉$BBLU$庫$BMAG$之$NOR$$GRN$金刀$NOR$ " );
	set( "object", ([
		"amount5"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/magic-manor/obj/maun-shadow-blade",
		"file2"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file5"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file6"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount9"  : 1,
		"amount10" : 1,
		"file4"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file7"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file8"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount8"  : 1,
		"file3"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file1"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount1"  : 1,
	]) );
	set( "build", 10542 );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room88",
		"west"      : "/open/clan/time-limit/room/room86",
		"north"     : "/open/clan/time-limit/room/room97",
	]) );
	set( "long", @LONG
幔羅刀無影(Maun-shadow-blade),香靈吟所使用的武器,為一神秘鑄將精心鑄造
的「八色靈器」之一,刀身精緻小巧,卻具有強大殺傷力,香靈吟不但會使用聚葉
成刀術,無影狂刀斬更是把你定死死的,還有破邪驚天斬,是個相當難纏的對手,
而幔羅刀無影除了當武器使用外,也是聚靈道裡通行的鑰匙

LONG);
	setup();
	replace_program(ROOM);
}
