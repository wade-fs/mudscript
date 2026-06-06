inherit ROOM;
void create() {
	set( "short", "$HIG$夢劇場$HIR$Dream Theater$NOR$" );
	set( "owner", "devil" );
	set( "object", ([
		"amount10" : 99999,
		"amount7"  : 1,
		"amount5"  : 97584,
		"amount9"  : 98035,
		"amount1"  : 25,
		"file6"    : "/open/killer/obj/bellstar",
		"amount3"  : 100,
		"file1"    : "/open/fire-hole/obj/b-pill",
		"file2"    : "/open/fire-hole/obj/w-pill",
		"amount6"  : 99999,
		"file7"    : "/obj/gift/hobowdan",
		"file5"    : "/open/killer/obj/bellstar",
		"file4"    : "/open/fire-hole/obj/p-pill",
		"amount2"  : 2,
		"amount4"  : 13,
		"file9"    : "/open/killer/obj/bellstar",
		"file3"    : "/open/fire-hole/obj/r-pill",
		"file10"   : "/open/killer/obj/bellstar",
	]) );
	set( "build", 10074 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room177",
	]) );
	set( "long", @LONG

堪稱是九０年代以來最重要也最具代表性與影響力的前衛金屬樂團
，其92年所發表的專輯 <Images and Words> 為當時的前衛金屬開
出新的表現形式，專輯中高層次的技術展現，使得團員紛紛成為各
方注目的焦點，也使得這張專輯順理成章地成為前衛金屬的經典代
表作之一，也是所有前衛金屬樂迷的必備專輯。 

LONG);
	setup();
	replace_program(ROOM);
}
