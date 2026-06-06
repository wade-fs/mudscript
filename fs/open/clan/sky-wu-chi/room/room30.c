inherit ROOM;
void create() {
	set( "short", "炎龍殿" );
	set( "owner", "panhermes" );
	set( "light_up", 1 );
	set( "build", 10482 );
	set( "object", ([
		"file2"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file5"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file3"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount1"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount4"  : 1,
		"file6"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file8"    : "/open/magic-manor/obj/hwa-je-icer",
		"file7"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount2"  : 1,
		"amount8"  : 1,
		"amount7"  : 1,
		"file9"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount5"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
	]) );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room158.c",
	]) );
    set("long",@LONG
這裡是幫主得力助手的房間, 具聞她出身地發無人得知
但是她卻有一張可仁的臉, 不少男人迷倒在她眼前, 而她卻
是現世中唯一可以和幫主爭雄的人, 她的名字無人知道, 只
知道她出現的地方必定出血, 後人稱其為 殺   神

LONG);
        set("no_transmit",1);
        set("cmkroom",1);
        setup();
        replace_program(ROOM);
}
