inherit ROOM;
void create() {
	set( "short", "菩提袈裟房" );
	set( "owner", "amdxp" );
	set( "object", ([
		"file7"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount10" : 1,
		"amount4"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount1"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount9"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount5"  : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-cloak",
	]) );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room279",
		"south"     : "/open/clan/13_luck/room/room299.c",
	]) );
	set( "build", 10068 );
	set( "light_up", 1 );
	set( "long", @LONG

    菩提本無樹，明鏡亦非台，本來無一物，何處惹塵埃，傳說中的防
具，菩薩袈裟，在天下武功出少林的，少林掌門人手上，還有必免殺氣
過高而檔在路口的空聞，是個好防具，也是少林開放的一天，就是菩提
袈裟缺貨的一天。

LONG);
	setup();
	replace_program(ROOM);
}
