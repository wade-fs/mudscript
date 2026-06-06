inherit ROOM;
void create() {
	set( "short", "PACIFIC BLUE" );
	set( "object", ([
		"file2"    : "/open/killer/obj/hate_knife",
		"file1"    : "/open/killer/obj/hate_knife",
		"amount3"  : 240,
		"file6"    : "/open/doctor/obj/d-mark",
		"amount2"  : 70000,
		"amount5"  : 1,
		"file5"    : "/open/mogi/dragon/obj/key",
		"amount6"  : 1,
		"file3"    : "/open/killer/obj/s_pill",
		"amount4"  : 35,
		"file4"    : "/open/mon/obj/mon-pill",
		"amount1"  : 50000,
	]) );
	set( "owner", "del" );
	set( "build", 10060 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room298",
		"west"      : "/open/clan/ou-cloud-club/room/room251.c",
	]) );
	set( "long", @LONG
      
作曲家喬那斯‧克凡史東與史蒂芬‧舒曼兩人的完美演出，將每一
個浪起潮退起伏，生動紀錄，浪起的澎湃節奏，簇擁著急轉直下的
潮退靜謐；彷彿置身浩瀚大海，隨著鯨航的律動和宛如輕騎的海豚
呼喚，勾勒出蕩漾心房的音樂旋律，帶領心靈回到最原始的境地。
  
LONG);
	setup();
	replace_program(ROOM);
}
