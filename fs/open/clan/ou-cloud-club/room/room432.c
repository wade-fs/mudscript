inherit ROOM;
void create() {
	set( "short", "$HIW$無限城$NOR$--$HIB$南方之劍$NOR$" );
	set( "object", ([
		"amount2"  : 1,
		"amount4"  : 1,
		"file8"    : "/open/magic-manor/obj/evil-kill-claw",
		"file5"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount7"  : 1,
		"file1"    : "/open/capital/obj/icer",
		"file2"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file4"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount8"  : 1,
		"amount1"  : 1,
		"file7"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount5"  : 1,
	]) );
	set( "owner", "del" );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room314",
	]) );
	set( "build", 10026 );
	set( "light_up", 1 );
	set( "long", @LONG
呈現眼前的是一座座緊鄰的兵營，兵營外整齊的放著各
式各樣的兵器，不遠處是一大群毛色光亮體型雄壯戰馬，這
裡是菜刀團右翼突擊隊的大本營，除了正規戰鬥外，他們也
負責各樣如暗殺、設施破壞等特殊任務，盡一切可能剷除敵
人將領，削弱對方勢力。

LONG);
	setup();
	replace_program(ROOM);
}
