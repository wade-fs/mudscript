inherit ROOM;
void create() {
	set( "short", "冥魔寶室" );
	set( "owner", "matrix" );
	set( "object", ([
		"amount9"  : 3,
		"amount7"  : 1,
		"file3"    : "/daemon/class/blademan/obj/shield",
		"amount4"  : 1,
		"amount10" : 48,
		"file5"    : "/obj/gift/unknowdan",
		"file7"    : "/open/quests/snake/npc/obj/snake-key-1",
		"file9"    : "/open/ping/obj/poison_pill",
		"amount5"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/mogi/castle/obj/leave",
		"amount3"  : 1,
		"file10"   : "/open/fire-hole/obj/p-pill",
		"file1"    : "/obj/gift/unknowdan",
		"file8"    : "/open/quests/snake/npc/obj/snake-key-1",
		"amount8"  : 1,
	]) );
	set( "build", 14287 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room76.c",
		"east"      : "/open/clan/sky-wu-chi/room/room350",
	]) );
	set( "long", @LONG
此密室中, 擺放了幾件光澤奇異成套裝備, 當妳好奇的拿起其中一件仔細端

詳, 在碰觸的剎那之中, 一股暖流循奇經八脈流遍全身, 澎湃的內勁越轉越強

, 一股自信油然而生, 就算十個焚天魔王現身眼前, 妳也確信能像螞艤般的輕意

捏死, 妳把此處裝備一一穿戴上身, 不能控制的邪笑起來, 相信離武林稱雄的日

子當已不遠.
LONG);
	setup();
	replace_program(ROOM);
}
