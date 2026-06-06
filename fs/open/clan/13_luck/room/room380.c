inherit ROOM;
void create() {
	set( "short", "春秋閣" );
	set( "object", ([
		"amount4"  : 1,
		"file2"    : "/open/ghost-hole/obj/living-water",
		"amount2"  : 1,
		"file1"    : "/open/ghost-hole/obj/living-water",
		"amount5"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/ghost-hole/obj/living-water",
		"file5"    : "/obj/gift/shenliwan",
		"file3"    : "/open/ghost-hole/obj/living-water",
		"amount1"  : 1,
	]) );
	set( "owner", "roar" );
	set( "build", 10845 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room383",
	]) );
	set( "long", @LONG

    春秋閣，乃紀念三國時代名將關羽的地方，戰十三這一生最欽佩的人
亦是關羽。所以就把這閣命名為『春秋』，他希望戰堂弟子都能向關羽一
樣大忠大義，成為一個有用的人。而他最得意的門生之一就是四強武者中
的『巨龍愁』，他也因巨龍愁能超過自己的成就，而成武林中的一派宗師
而高興。

LONG);
	setup();
	replace_program(ROOM);
}
