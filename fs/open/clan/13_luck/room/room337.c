inherit ROOM;
void create() {
	set( "short", "比武道" );
	set( "owner", "smalloo" );
	set( "object", ([
		"file4"    : "/open/killer/headkill/obj/w_dag",
		"file6"    : "/open/killer/headkill/obj/f_dag",
		"amount2"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/killer/headkill/obj/i_dag",
		"amount4"  : 1,
		"amount10" : 1,
		"file7"    : "/open/killer/obj/dagger",
		"amount7"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/killer/headkill/obj/f_dag",
		"file8"    : "/open/magic-manor/obj/water-ball",
		"file9"    : "/open/killer/obj/dagger",
		"amount9"  : 1,
		"file10"   : "/obj/gift/unknowdan",
		"file2"    : "/obj/gift/lingzhi",
		"file3"    : "/open/killer/headkill/obj/e_dag",
		"amount8"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 10206 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room336",
		"north"     : "/open/clan/13_luck/room/room338",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    你又轉了幾個彎，三株大松樹衝天而起，地下又有硫磺，煤炭等
礦藏，地氣特暖，百花齊開。你行出數步，隱隱聽得樹林中傳來兵刃
相交之聲你有些焦急是前去看，原來是神風堂和飛雲堂的門徒在互相
切磋武藝，你看到眾多高手在切磋，引起了你好戰的心裡，你也忍不
住想去一起比試一下。


LONG);
	setup();
	replace_program(ROOM);
}
