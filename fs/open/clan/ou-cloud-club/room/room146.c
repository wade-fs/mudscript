inherit ROOM;
void create() {
	set( "short", "十二$HIR$恨$NOR$室" );
	set( "object", ([
		"file4"    : "/obj/gift/xiandan",
		"amount4"  : 1,
		"file3"    : "/open/killer/headkill/obj/world_dag",
		"amount7"  : 1,
		"file7"    : "/obj/gift/unknowdan",
		"file6"    : "/open/gsword/obj1/blosword",
		"file10"   : "/obj/gift/xiandan",
		"file1"    : "/obj/gift/xisuidan",
		"file5"    : "/open/fire-hole/obj/w-pill",
		"amount1"  : 1,
		"file2"    : "/obj/gift/xiandan",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
		"file8"    : "/obj/gift/xiandan",
		"amount5"  : 5,
	]) );
	set( "owner", "enter" );
	set( "build", 11054 );
	set( "light_up", 1 );
	set( "exits", ([
		"ghost"     : "/open/clan/ou-cloud-club/room/room332",
		"out"       : "/open/clan/ou-cloud-club/room/room145.c",
	]) );
	set( "long", @LONG
   
$HIY$┌───────────────────────────┐
│  $HIR$一恨   $HIC$才人無行   $HIR$二恨   $HIC$紅顏薄命   $HIR$三恨   $HIC$江浪不息 $HIY$│
│  $HIR$四恨   $HIC$世態炎冷   $HIR$五恨   $HIC$月臺易露   $HIR$六恨   $HIC$蘭葉多焦 $HIY$│
│  $HIR$七恨   $HIC$河豚甚毒   $HIR$八恨   $HIC$架花生刺   $HIR$九恨   $HIC$夏夜有蚊 $HIY$│
│  $HIR$十恨   $HIC$薜蘿藏虺   $HIR$十一恨 $HIC$未食敗果   $HIR$十二恨 天下無敵$NOR$ $HIY$│
└───────────────────────────┘$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
