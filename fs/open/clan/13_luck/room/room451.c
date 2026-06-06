inherit ROOM;
void create() {
	set( "short", "『藥堂』" );
	set( "owner", "mill" );
	set( "object", ([
		"file1"    : "/open/killer/headkill/obj/i_dag",
		"amount6"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file9"    : "/open/killer/headkill/obj/i_dag",
		"file3"    : "/open/killer/headkill/obj/i_dag",
		"file8"    : "/open/killer/headkill/obj/i_dag",
		"file6"    : "/open/killer/headkill/obj/i_dag",
		"amount2"  : 1,
		"amount7"  : 1,
		"amount10" : 1,
		"file2"    : "/open/killer/headkill/obj/i_dag",
		"amount5"  : 1,
		"file10"   : "/open/killer/headkill/obj/i_dag",
		"amount9"  : 1,
		"file5"    : "/open/killer/headkill/obj/i_dag",
		"file4"    : "/open/killer/headkill/obj/i_dag",
		"amount8"  : 1,
		"amount1"  : 1,
		"file7"    : "/open/killer/headkill/obj/i_dag",
	]) );
	set( "build", 10082 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room452.c",
	]) );
	set( "long", @LONG

     這裡飄來股股藥草香，尚有幾個藥僮蹲坐在門前屋簷下，一手握著杵，
 一手按緊地上的藥砵，『霍～霍～』地磨著藥材。另一邊三五個教中大漢攙
 扶著受傷的戰友逕往屋裡頭走，而屋裡頭還不時傳來唧唧哼哼的呻吟聲。原
 來是間『藥堂』，專為教中人士提供醫療服務，堂裡左右兩邊架上陳列著各
 種瓶瓶罐罐，底下一格格的小櫃子裡頭都是珍貴藥材。

LONG);
	setup();
	replace_program(ROOM);
}
