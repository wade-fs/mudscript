inherit ROOM;
void create() {
	set( "short", "$HIW$無限城$NOR$--$HIR$戰神之塔$NOR$" );
	set( "object", ([
		"amount2"  : 1,
		"amount7"  : 1,
		"amount9"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/gsword/obj1/bpball",
		"file3"    : "/open/gsword/obj1/bpball",
		"amount10" : 1,
		"amount8"  : 1,
		"file7"    : "/open/gsword/obj1/bpball",
		"file10"   : "/open/gsword/obj1/bpball",
		"amount5"  : 1,
		"file1"    : "/open/gsword/obj1/bpball",
		"file6"    : "/open/gsword/obj1/bpball",
		"amount4"  : 1,
		"file4"    : "/open/gsword/obj1/bpball",
		"file9"    : "/open/gsword/obj1/bpball",
		"file2"    : "/open/gsword/obj1/bpball",
		"file8"    : "/open/gsword/obj1/bpball",
		"amount3"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10035 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room310.c",
		"up"        : "/open/clan/ou-cloud-club/room/room210.c",
		"down"      : "/open/clan/ou-cloud-club/room/room88.c",
		"east"      : "/open/clan/ou-cloud-club/room/room309.c",
		"north"     : "/open/clan/ou-cloud-club/room/room81.c",
		"south"     : "/open/clan/ou-cloud-club/room/room432",
	]) );
	set( "long", @LONG
前身為古都‧萊姆，百年戰爭擊退來襲的巨龍軍團之，
為了維護三百七十萬居民的安全，大議會決定積極投入工業
及魔法研究，經過數十年的研發與改良，開發出一套系統可
無限輸出城堡所需的各項能源，並將其應用在城堡的防禦系
統上，使城堡本身具有雷擊、火網等自我防禦裝備，大幅降
低了守城所耗用的人力。

LONG);
	setup();
	replace_program(ROOM);
}
