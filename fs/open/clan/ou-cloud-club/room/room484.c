inherit ROOM;
void create() {
	set( "short", "Autodromo Dino Ferrari" );
	set( "object", ([
		"amount7"  : 1,
		"amount1"  : 1,
		"amount9"  : 1,
		"file2"    : "/obj/gift/shenliwan",
		"file1"    : "/obj/gift/shenliwan",
		"amount4"  : 1,
		"amount5"  : 1,
		"file7"    : "/obj/gift/shenliwan",
		"file9"    : "/obj/gift/shenliwan",
		"amount8"  : 1,
		"file8"    : "/obj/gift/shenliwan",
		"file6"    : "/obj/gift/shenliwan",
		"amount3"  : 1,
		"file5"    : "/obj/gift/shenliwan",
		"amount6"  : 1,
		"file10"   : "/obj/gift/shenliwan",
		"amount2"  : 1,
		"file3"    : "/obj/gift/shenliwan",
		"file4"    : "/obj/gift/shenliwan",
		"amount10" : 1,
	]) );
	set( "build", 13532 );
	set( "owner", "ctx" );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room486",
	]) );
	set( "long", @LONG
聖馬利諾,對,就是Imola,這賽道有名的是她是所有F1賽到中
相當有名的高速賽道,有名的車神洗拿(Senna)1994年就在這個車
道出車禍(Tamburello)去逝, 可以見得高速跑道對車手可真是又
愛又恨阿,這跑道的彎道有,Tamburello彎道,Villeneuve彎道,To
sa彎道,Piratella彎道,Acque Minerali彎道, Variante Alta彎
道,Rivazza彎道Variante Bassa彎道,Traguardo彎道。

LONG);
	setup();
	replace_program(ROOM);
}
