inherit ROOM;
void create() {
	set( "short", "丹藥房大門" );
	set( "object", ([
		"file2"    : "/open/fire-hole/obj/p-pill",
		"amount1"  : 91,
		"amount5"  : 75,
		"file4"    : "/open/fire-hole/obj/b-pill",
		"amount8"  : 59,
		"file6"    : "/open/ping/obj/poison_pill",
		"file8"    : "/open/fire-hole/obj/w-pill",
		"file1"    : "/open/fire-hole/obj/k-pill",
		"amount4"  : 127,
		"amount2"  : 242,
		"file5"    : "/open/fire-hole/obj/y-pill",
		"amount6"  : 488,
	]) );
	set( "build", 10110 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room136.c",
		"enter"     : "/open/clan/13_luck/room/room144",
	]) );
	set( "long", @LONG

　　一來到此地，即聞到濃濃的藥味，原來這裡便是十三吉祥的丹藥
房，全為檜木所建造而成，而大門的正上方，懸掛著一塊牌匾，上頭
刻著「　懸　壺　濟　世　」斗大的四個字，兩旁站著的兩位十三吉
祥弟子正在忙著把藥材搬進進裡面，以便煉藥醫人。

LONG);
	setup();
	replace_program(ROOM);
}
