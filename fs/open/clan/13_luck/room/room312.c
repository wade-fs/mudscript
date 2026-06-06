inherit ROOM;
void create() {
	set( "short", "寒雪針室" );
	set( "object", ([
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount7"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 11556 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room272",
	]) );
	set( "long", @LONG

    冰雪寒絲針乃是醫者之師傅華佗的隨身武器，光是聽到華佗二字就
嚇的一身冷汗，除了一身針法還有那變態的後三招式，外加狂定人的金
針渡穴令人防不勝防，只好跟他速戰速決，身上又帶有人靈丹，所以你
經驗值不多，可別拿自己生命開玩笑。

LONG);
	setup();
	replace_program(ROOM);
}
