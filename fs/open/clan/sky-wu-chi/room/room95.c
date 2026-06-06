inherit ROOM;
void create() {
	set( "short", "gk eq-boots" );
	set( "owner", "cong" );
	set( "object", ([
		"amount5"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount7"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount4"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount2"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-boots",
	]) );
	set( "light_up", 1 );
	set( "build", 10722 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room379.c",
		"west"      : "/open/clan/sky-wu-chi/room/room381",
		"south"     : "/open/clan/sky-wu-chi/room/room375.c",
		"north"     : "/open/clan/sky-wu-chi/room/room67.c",
	]) );
	set( "long", @LONG

花褪殘紅青杏小，

燕子飛時，綠水人家繞。

枝上柳綿吹又少，

天涯何處無芳草？

牆裏鞦韆牆外道，

牆外行人，牆裏佳人笑。

笑漸不聞聲漸悄，

多情卻被無情惱

LONG);
	setup();
	replace_program(ROOM);
}
