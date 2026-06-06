inherit ROOM;
void create() {
	set( "short", "血痕居-馬房" );
	set( "owner", "holeman" );
	set( "object", ([
		"amount6"  : 1,
		"file10"   : "/open/area/house/npc/obj/snake-stone",
		"amount3"  : 1,
		"file2"    : "/open/gsword/obj1/sadsword",
		"file3"    : "/open/mogi/dragon/obj/thunder-1",
		"amount5"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/capital/obj/blade2",
		"amount7"  : 1,
		"amount10" : 1,
		"file9"    : "/open/killer/obj/dagger",
		"amount4"  : 1,
		"amount9"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/gsword/obj1/blosword",
		"amount1"  : 1,
		"file7"    : "/open/magic-manor/obj/wood-ball",
		"file6"    : "/open/magic-manor/obj/fire-ball",
		"amount8"  : 1,
		"file5"    : "/open/magic-manor/obj/water-ball",
	]) );
	set( "light_up", 1 );
	set( "build", 10034 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room298",
	]) );
	set( "long", @LONG

    在這裡的馬兒每隻都在這個良好的環境中受到完善的照
顧，光是看這馬房整潔的環境以及每隻馬兒良好的健康狀態
就可以知道主人有多用心在照顧這些馬。想不到這裡的主人
不僅在刀法上出類拔萃連飼養馬匹都有他自己獨到的心得。
現在這些雄壯威武的戰馬將會在此等著與他的主人步向下一
個未知的戰場。


LONG);
	setup();
	replace_program(ROOM);
}
