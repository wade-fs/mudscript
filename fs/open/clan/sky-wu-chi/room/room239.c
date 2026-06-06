inherit ROOM;
void create() {
	set( "short", "$WHT$玄宇宙$NOR$" );
	set( "owner", "cong" );
	set( "object", ([
		"amount5"  : 1,
		"amount9"  : 1,
		"file2"    : "/u/c/cgy/boots1",
		"amount6"  : 1,
		"file1"    : "/open/quests/snake/npc/obj/snake_gem",
		"amount3"  : 1,
		"file7"    : "/open/gblade/mob/lotch",
		"file4"    : "/open/gblade/obj/sa-head",
		"amount10" : 1,
		"amount1"  : 1,
		"amount7"  : 1,
		"amount4"  : 1,
		"file6"    : "/obj/gift/xiandan",
		"amount2"  : 1,
		"file3"    : "/open/gblade/mob/lotch",
		"file10"   : "/open/mogi/dragon/obj/sunblade",
		"file9"    : "/obj/gift/xisuidan",
		"file5"    : "/open/gsword/npc2/sadsword",
	]) );
	set( "item_desc", ([
		"map" : @ITEM
往東是$HIM$東銀河系$NOR$
往西是$HIC$西銀河系$NOR$
往南是$HIB$南銀河系$NOR$
往北是$HIR$北銀河系$NOR$
往上是$HIY$九天外天$NOR$
往下是$HIG$九地黃泉$NOR$
ITEM,
	]) );
	set( "light_up", 1 );
	set( "build", 10070 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room310.c",
		"east"      : "/open/clan/sky-wu-chi/room/room284.c",
		"south"     : "/open/clan/sky-wu-chi/room/room161.c",
		"west"      : "/open/clan/sky-wu-chi/room/room249.c",
	]) );
	set( "long", @LONG
這裡是小星星$HIC$星隕$NOR$平時休息的地方，裡面的擺設極整齊且清樸，只見牆上掛了對刀劍
，顯得極具氣派，相傳這對刀劍乃是雪蒼派開山祖師從一位異人手中得來的，只是可惜雪
蒼派開山祖師鬼影老人不會刀劍，否則傳授於$HIC$星隕$NOR$必能以此刀劍揚名立萬。

  $WHT$玄宇宙地圖$NOR$(map)

LONG);
	setup();
	replace_program(ROOM);
}
