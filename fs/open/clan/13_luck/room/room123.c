inherit ROOM;
void create() {
	set( "short", "飆車廣場" );
	set( "owner", "woan" );
	set( "object", ([
		"amount8"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/wu/npc/obj/armband",
		"file10"   : "/open/gsword/obj/yuskirt",
		"file9"    : "/open/port/obj/wolf_ring",
		"file3"    : "/open/gsword/obj/yau_glove",
		"file8"    : "/open/wu/npc/obj/armband",
		"amount6"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"file1"    : "/open/love/obj/cloth1",
		"file2"    : "/daemon/class/bonze/puty_pullium",
		"amount9"  : 1,
		"amount1"  : 1,
		"amount4"  : 1,
		"file6"    : "/open/gsword/obj/ring-1",
		"amount7"  : 1,
		"file4"    : "/open/wu/npc/obj/armband",
	]) );
	set( "build", 10134 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room326",
		"south"     : "/open/clan/13_luck/room/room98.c",
	]) );
	set( "long", @LONG
眼見一望無際的路上，只見一台SV在中飆車穿縮，但此路之
長，非一兩個小時可以走完的，但是這台SV在中穿縮，來回卻不
用一分鐘，可知這名飆車騎士的能耐跟這台SV的馬力，而你往前
在走去，看到一堆一堆的冷凍箱，而有個門上面寫著。
  
             傲殘紅多多有限公司
         
         PS.全年無休，1小時內飆車送達

LONG);
	setup();
	replace_program(ROOM);
}
