inherit ROOM;
void create() {
	set( "short", "gk eq-shield" );
	set( "owner", "cong" );
	set( "light_up", 1 );
	set( "object", ([
		"amount4"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file8"    : "/open/magic-manor/obj/fon-sky-sword",
		"file6"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file7"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount8"  : 1,
		"amount3"  : 1,
		"amount7"  : 1,
	]) );
	set( "build", 10191 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room67.c",
		"north"     : "/open/clan/sky-wu-chi/room/room378.c",
		"west"      : "/open/clan/sky-wu-chi/room/room374",
		"south"     : "/open/clan/sky-wu-chi/room/room377.c",
	]) );
	set( "long", @LONG

春花秋月何時了？

往事知多少

小樓昨夜又東風，

故國不堪回首月明中

雕欄玉砌應猶在，

祇是朱顏改

問君能有幾多愁？

恰似一江春水向東流



LONG);
	setup();
	replace_program(ROOM);
}
