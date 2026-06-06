inherit ROOM;
void create() {
	set( "short", "前輩高人元之居所--" );
	set( "owner", "matrix" );
	set( "light_up", 1 );
	set( "object", ([
		"file8"    : "/open/prayer/obj/boris-cloth",
		"amount7"  : 1,
		"file7"    : "/daemon/class/blademan/obj/shield",
		"amount8"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mon/obj/ghost-legging",
		"file9"    : "/open/prayer/obj/kylin-belt",
		"file5"    : "/daemon/class/fighter/figring",
		"amount9"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10078 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"east"      : "/open/clan/sky-wu-chi/room/room367",
		"up"        : "/open/clan/sky-wu-chi/room/room10.c",
	]) );
	set( "long", @LONG
在你眼前的, 是絕代高人元的居所, 據聞前輩乃已故聖火教主之
得意弟子, 然其修為遠遠超於其師, 據江湖中人口耳相傳, 其人三
載之間, 十大門派已俱敗於其下; 若非當年教難之時其人遠遊,
聖火亦至覆滅; 今眼前所見, 乃其縱橫近百年後隱遁之居所,軒
上書有三字  靈隱居  ; 你偷眼望於居所, 前輩似乎遠遊未歸
,觀其陳設簡僕高雅, 四周籣香與檜木令你視覺與嗅覺有著自然
的感受; 思維前輩雖縱橫江湖近百載, 然其生活簡僕若此, 不好
名利, 可惜今番緣慳一面未能得遇, 便不由主的感嘆起來.
LONG);
	setup();
	replace_program(ROOM);
}
