inherit ROOM;
void create() {
	set( "short", "東偏房" );
	set( "object", ([
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file8"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
	]) );
	set( "build", 10473 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room345",
		"west"      : "/open/clan/13_luck/room/room139.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    黃金甲龍在魔界怪物中是最兇猛也是最殘暴的動物，當它狂暴時
會弒殺附近所有的生物，無一倖免；若自身武功修為未達顛峰，而貿
然前去也只是成為它腹中的食物而已，做好萬全的準備在去挑戰魔獸
，擊敗它後其體內的龍元能增加妳的內力修為。

LONG);
	setup();
	replace_program(ROOM);
}
