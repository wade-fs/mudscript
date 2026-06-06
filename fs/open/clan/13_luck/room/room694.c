inherit ROOM;
void create() {
	set( "short", "豆沙屋" );
	set( "owner", "biok" );
	set( "exits", ([
		"moon"      : "/open/clan/13_luck/room/hall",
		"north"     : "/open/clan/13_luck/room/room592",
		"east"      : "/open/clan/13_luck/room/room56",
	]) );
	set( "object", ([
		"amount9"  : 1,
		"file9"    : "/open/killer/obj/dagger",
		"file6"    : "/open/killer/obj/kill_yar_head",
		"file8"    : "/open/fire-hole/obj/g-pill",
		"file10"   : "/open/mogi/castle/obj/sspill",
		"file3"    : "/open/killer/obj/black",
		"amount10" : 22,
		"file4"    : "/open/killer/headkill/obj/bluekill",
		"amount6"  : 1,
		"amount7"  : 210,
		"amount1"  : 1,
		"amount3"  : 15,
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"amount8"  : 456,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/fire-hole/obj/r-pill",
		"amount4"  : 1,
		"file2"    : "/open/fire-hole/obj/w-pill",
		"amount5"  : 379,
		"amount2"  : 415,
	]) );
	set( "build", 10004 );
	set( "light_up", 1 );
	set( "long", @LONG
這裡是歹勇仔儲存裝備的地方, 只見各式各樣的裝備
擺滿了整個房間, 其中有長白山上妖幻空間內千年樹妖--
舞風揚的妖幻系列, 有瀧山掌門任正晴的陽炎臂環, 郭襄
的幸運草環, 諸如寒冰, 菩提袈裟, 夕陽紅紗, 魔法盾,
羅剎女飾, 混沌腰帶, 等等增加功力的裝備, 皆在收藏之
列.也許你可以跟他要一付來穿....
LONG);
	setup();
	replace_program(ROOM);
}
