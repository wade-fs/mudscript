inherit ROOM;
void create() {
	set( "short", "寒霜居-歸真之間" );
	set( "owner", "poisoner" );
	set( "object", ([
		"amount1"  : 1,
		"file4"    : "/open/tendo/obj/chaosbelt",
		"amount10" : 1,
		"amount8"  : 1,
		"file5"    : "/open/capital/obj/4-1",
		"amount9"  : 1,
		"file3"    : "/open/mon/obj/thousand-nectar",
		"amount4"  : 1,
		"amount3"  : 15,
		"file8"    : "/daemon/class/blademan/obj/shield",
		"amount5"  : 1,
		"file9"    : "/obj/gift/shenliwan",
		"file1"    : "/open/mogi/castle/obj/lochagem",
		"file10"   : "/open/magic-manor/obj/master_snake_head",
		"file6"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount6"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10431 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room358",
	]) );
	set( "long", @LONG
　　原本以為在這個藏經閣中會有失傳的武學典籍，但實際看看也不
過就只有一些比較常看見的書籍，當你慢慢的向裡面走去的時候，你
突然發覺在這房間的頂端好像有一座小閣樓，你馬上施展輕功向那座
閣樓躍去。原來這座閣樓才是收藏真正武學典籍的地方，在這裡有天
子手中才有的神秘書籍，以及被收藏在魔龍塔中的狂龍刀譜，甚至還
有記載可以使人暴升兩倍防禦力的極火金身的極火真經。
LONG);
	setup();
	replace_program(ROOM);
}
