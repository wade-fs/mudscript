inherit ROOM;
void create() {
	set( "short", "$HIY$龍爪密室$NOR$" );
	set( "owner", "etcmiko" );
	set( "object", ([
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount5"  : 165,
		"amount6"  : 1,
		"amount2"  : 403,
		"file5"    : "/open/killer/obj/atman_pill",
		"file3"    : "/open/mogi/castle/obj/sspill",
		"amount4"  : 962,
		"file4"    : "/open/mon/obj/mon-pill",
		"amount3"  : 147,
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"file7"    : "/open/mon/obj/thousand-nectar",
		"amount7"  : 9,
		"amount1"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "light_up", 1 );
	set( "build", 12597 );
	set( "exits", ([
		"out"       : "/open/clan/ou-cloud-club/room/room119",
	]) );
	set( "long", @LONG
          $BRED$$HIY$《  $HIC$龍   爪   奧  義　$HIY$－　$HIG$狂　龍　舞　雲　際　$HIY$》$NOR$

$HIC$∵∵∵∵∵∵∵∵∵∵∵∵$HIR$【$HIC$　拿　云　搶　珠　式　$HIR$】$HIC$∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵

$HIY$∵∵∵∵∵∵∵∵∵∵∵∵$HIR$【$HIY$　拿　云　撈　月　式　$HIR$】$HIY$∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵

$HIG$∵∵∵∵∵∵∵∵∵∵∵∵$HIR$【$HIG$　捕　風　捉　影　式　$HIR$】$HIG$∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵

$HIM$∵∵∵∵∵∵∵∵∵∵∵∵$HIR$【$HIM$　撫　琴　撈　月　式　$HIR$】$HIM$∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵

$HIW$∵∵∵∵∵∵∵∵∵∵∵∵$HIR$【$HIR$　雙　龍　搶　珠　式　$HIR$】$HIW$∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵

$HIB$∵∵∵∵∵∵∵∵∵∵∵∵$HIR$【$HIB$  雙　重　虛　搗　式　$HIR$】$HIB$∵∵∵∵∵∵∵∵∵∵∵∵∵∵∵$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
