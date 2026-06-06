inherit ROOM;
void create() {
	set( "short", "$HIC$欣$HIR$ソ$HIY$防具所$NOR$" );
	set( "object", ([
		"amount1"  : 694,
		"file4"    : "/open/fire-hole/obj/w-pill",
		"file9"    : "/open/mogi/castle/obj/sspill",
		"amount7"  : 122,
		"file3"    : "/open/fire-hole/obj/b-pill",
		"file8"    : "/open/fire-hole/obj/k-pill",
		"amount9"  : 20,
		"file6"    : "/open/fire-hole/obj/r-pill",
		"amount5"  : 233,
		"file1"    : "/open/fire-hole/obj/g-pill",
		"amount4"  : 126,
		"file5"    : "/open/fire-hole/obj/y-pill",
		"amount3"  : 35,
		"amount6"  : 1343,
		"amount8"  : 94,
		"amount2"  : 87,
		"file2"    : "/open/ping/obj/poison_pill",
		"file7"    : "/open/fire-hole/obj/p-pill",
	]) );
	set( "light_up", 1 );
	set( "build", 10080 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room108",
		"east"      : "/open/clan/sky-wu-chi/room/room187.c",
		"west"      : "/open/clan/sky-wu-chi/room/room72.c",
	]) );
	set( "long", @LONG
    這裡是夜空下的欣的防具所,所有防具都整齊劃一的排列在防具所裡
每個防具都閃亮著他們的光芒,導致整各房間閃閃發亮,你看到裡面所
收藏的妖幻防具..不禁嘖嘖稱其......所有的防具在欣提刀作戰時,則
給了欣一道強勁的防護.....

LONG);
	setup();
	replace_program(ROOM);
}
