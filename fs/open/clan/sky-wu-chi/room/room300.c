inherit ROOM;
void create() {
	set( "short", "血痕居-練刀房" );
	set( "owner", "holeman" );
	set( "object", ([
		"amount1"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"file7"    : "/open/capital/obj/sword_book",
		"file10"   : "/open/doctor/obj/feather",
		"amount8"  : 1,
		"file9"    : "/open/mogi/castle/obj/fire_book",
		"amount6"  : 1,
		"file8"    : "/open/capital/obj/fist_book",
		"amount4"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/capital/obj/blade_book",
		"amount10" : 1,
		"amount5"  : 1,
		"file5"    : "/open/capital/obj/force_book",
		"file4"    : "/open/capital/obj/steps_book",
		"file1"    : "/open/gblade/obj/dragon_book",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/capital/obj/book",
		"amount7"  : 1,
	]) );
	set( "build", 11703 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room305",
	]) );
	set( "long", @LONG

    處在這房間令你渾身不自在，因為這房間完全沒有擺設，取
而代之的是四面由鋼鐵所打造成的牆壁，而這些堅硬的牆壁上卻
被刻上無數的刀痕。當你碰觸其中一道刀痕時，沒想到在腦海中
突然浮現出一個人向你演練一式刀招，原來這些刀痕上都殘留著
每一式刀招的刀意。但沒想到這些刀招卻太博大精深，不管你怎
麼練都無法抓到其中的精髓，看來這些刀招的主人一定是位在世
高人啊。


LONG);
	setup();
	replace_program(ROOM);
}
