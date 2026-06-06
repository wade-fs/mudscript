inherit ROOM;
void create() {
	set( "short", "$YEL$黃金甲龍塚$NOR$" );
	set( "owner", "bbsboss" );
	set( "light_up", 1 );
	set( "object", ([
		"amount5"  : 1,
		"file8"    : "/open/ghost-hole/obj/living-water",
		"file10"   : "/open/mon/obj/ghost-legging",
		"file2"    : "/open/dancer/obj/yuawaist",
		"amount9"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"file6"    : "/open/ghost-hole/obj/death-butterfly",
		"amount4"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"amount10" : 1,
		"amount3"  : 1,
		"amount7"  : 1,
	]) );
	set( "build", 10047 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room190",
		"west"      : "/open/clan/ou-cloud-club/room/room188.c",
	]) );
	set( "long", @LONG

     $HIY$黃金甲龍身上的鱗片 ,具有特殊的魔力$NOR$


此乃魔界守護神獸黃金甲龍身上的鱗片...
據說有特殊的魔力...可將人瞬間傳送到魔界..

小馬冒險前往黃金甲龍窟....將其掃蕩一空.....
此處就是從黃金甲龍身上取回的鱗片....
往前一看....小馬也沾沾自喜的把玩著戰利品^_^
LONG);
	setup();
	replace_program(ROOM);
}
