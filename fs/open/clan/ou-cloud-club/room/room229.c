inherit ROOM;
void create() {
	set( "short", "修‧羅‧道" );
	set( "owner", "del" );
	set( "object", ([
		"file7"    : "/open/killer/headkill/obj/world_dag",
		"file10"   : "/open/wu/obj/figring",
		"amount3"  : 1,
		"file4"    : "/daemon/class/blademan/obj/ublade",
		"amount7"  : 1,
		"file9"    : "/daemon/class/blademan/obj/shield",
		"amount9"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/capital/obj/blade2",
		"amount4"  : 1,
		"file2"    : "/open/main/obj/shiblade",
		"file8"    : "/open/killer/headkill/obj/world_dag",
		"file3"    : "/daemon/class/blademan/obj/iceblade",
		"amount10" : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10036 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room33.c",
	]) );
	set( "long", @LONG
沿著小徑緩緩前進，來到了一間空無一物的石室，光線
是從較為上層的石壁透光而來，仔細端詳才發現四周圍的牆
上，地面，甚至是天花板都有著密密麻麻、深淺不一的刀痕
，看來像是歷經多次刀意的淬煉才會如此。在石室右側的牆
上刻著血紅的幾行字：
  
  修善難，為魔易；千年修道，不及一夜成魔
  
突然間一股冷風從你背後掃過，你不禁打了一個冷顫。
LONG);
	setup();
	replace_program(ROOM);
}
