inherit ROOM;
void create() {
	set( "short", "$HIC$【$NOR$大廳$HIC$】$NOR$小新家" );
	set( "owner", "cong" );
	set( "light_up", 1 );
	set( "object", ([
		"amount4"  : 1,
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"file4"    : "/open/gblade/obj/dragon_book",
		"amount5"  : 1,
		"amount3"  : 1,
		"file6"    : "/open/killer/headkill/obj/world_dag",
		"amount9"  : 7406,
		"amount8"  : 1,
		"file10"   : "/obj/gift/bingtang",
		"amount2"  : 1,
		"amount10" : 1,
		"file9"    : "/open/killer/obj/hate_knife",
		"file1"    : "/open/quests/snake/npc/obj/snake-key-2",
		"amount1"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/capital/obj/gold_pill",
		"file2"    : "/open/killer/headkill/obj/world_dag",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount6"  : 1,
		"file5"    : "/open/magic-manor/obj/hwa-je-icer",
	]) );
	set( "build", 10017 );
	set( "exits", ([
		"up"        : "/open/clan/sky-wu-chi/room/room24.c",
		"enter"     : "/open/clan/sky-wu-chi/room/room55.c",
		"out"       : "/open/clan/sky-wu-chi/room/room14.c",
		"east"      : "/open/clan/sky-wu-chi/room/room46.c",
		"west"      : "/open/clan/sky-wu-chi/room/room172.c",
	]) );
	set( "long", @LONG
這裡是小新家的大廳，往上是小新家主要存放東西的地方。平
常沒事的話應該都不會上去，所以如果有事的話都是在這裡詳談，
往下走是小新家唯一沒事做的人，破劍一把的小窩，主要也是放他
專用東西的房間。其他還有小新家的金刀小生小孤寂和魔刀小弟，
平常都可見到許多的人在這聊天，可見小新家的人都有點給他懶。

LONG);
	setup();
	replace_program(ROOM);
}













































































































































































































































































