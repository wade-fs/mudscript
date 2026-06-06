inherit ROOM;
void create() {
	set( "short", "$MAG$神$YEL$蠶$GRN$宮$NOR$" );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room203",
	]) );
	set( "long", @LONG
神蠶宮跟十三聖殿是北域的兩大勢力,但是神蠶宮卻和十三聖殿不同,整座宮殿只有女性,
神蠶宮的主人是百朝武后通瑤池,與金陽聖帝齊名,但是行事低調,與武林的接觸不多
加上有隻巨蠶顧守門前,早已無人敢上門了,但這並不表示神蠶宮完全沒野心,事實上神蠶宮
刻意隱藏實力,為的是能一舉拿下中原武林

LONG);
	setup();
	replace_program(ROOM);
}
