inherit ROOM;
void create() {
	set( "short", "綠茶園" );
	set( "owner", "biog" );
	set( "object", ([
		"file5"    : "/open/scholar/obj/iron",
		"amount3"  : 1,
		"file2"    : "/open/killer/obj/dagger",
		"amount4"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/killer/obj/hate_knife",
		"file3"    : "/open/scholar/obj/iron",
		"amount1"  : 46000,
		"amount2"  : 1,
		"file4"    : "/open/scholar/obj/iron",
	]) );
	set( "build", 12006 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room90.c",
		"enter"     : "/open/clan/13_luck/room/room92",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

千  此  人  不  轉  何  高  我  不  明  蘇
里  事  有  應  朱  似  處  欲  知  月  軾
共  古  悲  有  閣  在  不  乘  天  幾  
嬋  難  歡  恨      人  勝  風  上  時  水
娟  全  離      低  間  寒  歸  宮  有  調
        合  何  綺          去  闕      歌
    但      事  戶      起          把  頭
    願  月  長          舞  又  今  酒
    人  有  向  照      弄  恐  夕  問
    長  陰  別  無      清  瓊  是  青
    久  晴  時  眠      影  樓  何  天
        圓  圓              玉  年
        缺                  宇

LONG);
	setup();
	replace_program(ROOM);
}
