inherit ROOM;
void create() {
	set( "short", "$HIC$【內力裝備專櫃】$NOR$" );
	set( "owner", "peiyi" );
	set( "light_up", 1 );
	set( "object", ([
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file2"    : "/open/tendo/obj/chaosbelt",
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"amount3"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"file9"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount4"  : 1,
		"file3"    : "/open/wu/npc/obj/armband",
		"file4"    : "/open/mon/obj/ghost-legging",
		"file10"   : "/daemon/class/fighter/figring",
		"file1"    : "/daemon/class/blademan/obj/shield",
		"amount1"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"amount9"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/mon/obj/ghost-helmet",
		"file7"    : "/open/mogi/castle/obj/lochagem",
	]) );
	set( "build", 11054 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room226",
	]) );
	set( "long", @LONG
    你打開西邊的小櫃子，把頭探了進去看看，裡面是一整套加內力等
級的高級裝備，包括有 :

   ( 1) 混沌腰帶(chaos belt)
   ( 2) 羅剎女飾(gem)
   ( 3) 妖幻頭帶(ghost helmet)
   ( 4) 妖幻護膝(ghost legging)
   ( 5) 妖幻披掮(ghost cloak)
   ( 6) 狂龍翔天破(crazy dragon)
   ( 7) 夕霞紅紗(sun_red_cloth)
   ( 8) 幸運草環(lucky grasslink)
   ( 9) 魔法盾(magic shield)
   (10) 陽炎臂環 (Sun Fire Armband)

這是小佩佩用來增加功力時穿的裝備，是不會輕易借給別人的喔。
LONG);
	setup();
	replace_program(ROOM);
}
