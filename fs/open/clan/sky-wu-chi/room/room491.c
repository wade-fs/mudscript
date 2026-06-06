inherit ROOM;
void create() {
	set( "short", "刀塚" );
	set( "owner", "piccolo" );
	set( "object", ([
		"amount5"  : 8,
		"amount9"  : 7,
		"file2"    : "/obj/gift/xisuidan",
		"amount10" : 1,
		"file6"    : "/open/fire-hole/obj/p-pill",
		"file5"    : "/open/fire-hole/obj/b-pill",
		"amount6"  : 26,
		"amount2"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 9,
		"amount1"  : 1,
		"file7"    : "/open/fire-hole/obj/k-pill",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/gsword/obj/may_ring",
		"file10"   : "/obj/gift/xiandan",
		"file9"    : "/open/fire-hole/obj/g-pill",
		"amount4"  : 13,
		"amount3"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/fire-hole/obj/w-pill",
	]) );
	set( "build", 10264 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room479",
	]) );
	set( "long", @LONG
一走進這裡你就看到遍地的刀，不過每把都是斷掉或是缺口的，天魔刀王皮克洛一生中
所用的刀都被放置在這裡，作為紀念！仔細觀看每把刀上面，都還隱約殘留著一股
濃烈的殺氣，看來這些刀都帶有十分重大的殺業啊！
待在這裡太久讓你有一種非常不舒服的感覺，還是趕緊離開吧！
LONG);
	setup();
	replace_program(ROOM);
}
