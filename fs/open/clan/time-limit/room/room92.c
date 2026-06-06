inherit ROOM;
void create() {
	set( "short", "$BRED$時$BGRN$空$BYEL$倉$BBLU$庫$BMAG$之$NOR$$YEL$土色靈爪$NOR$" );
	set( "owner", "car" );
	set( "object", ([
		"amount2"  : 1,
		"amount8"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount5"  : 1,
		"file6"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount3"  : 1,
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"file5"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount6"  : 1,
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount4"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/magic-manor/soil/obj/soil-claw",
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
	]) );
	set( "build", 10185 );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room96",
	]) );
	set( "long", @LONG
土色靈爪(soil claw),土爆波所使用的寶爪,土光隱隱發出光芒,令人心神寧靜,
土爆波是可怕的惡人,天魔混殺吼是惡人最恐怖的招式,配合天魔刀,已經讓不少
人喪生在他的手下,土色靈光會帶走你的精和神,而打倒土爆波就可以得到土色靈
爪,據說是開啟聚靈道的重要道具

LONG);
	setup();
	replace_program(ROOM);
}
