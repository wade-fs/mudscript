inherit ROOM;
void create() {
	set( "short", "十強舞者語思" );
	set( "owner", "ananba" );
	set( "light_up", 1 );
	set( "item_desc", ([
		"四面全身大鏡" : @ITEM
ITEM,
	]) );
	set( "object", ([
		"amount4"  : 20,
		"file7"    : "/open/fire-hole/obj/r-pill",
		"file6"    : "/obj/stone/jiao",
		"file1"    : "/obj/stone/powder",
		"amount7"  : 87,
		"amount1"  : 155,
		"amount2"  : 115,
		"amount8"  : 16,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mon/obj/mon-pill",
		"amount6"  : 4,
		"amount3"  : 20,
		"file3"    : "/open/ping/obj/poison_pill",
		"amount5"  : 1,
		"file10"   : "/open/mogi/castle/obj/lochagem",
		"file4"    : "/obj/stone/suipian",
		"file8"    : "/open/mogi/castle/obj/ninepill",
		"amount10" : 1,
		"amount9"  : 1,
		"file9"    : "/open/snow/obj/stone",
	]) );
	set( "build", 10014 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room728",
	]) );
	set( "long", @LONG
    舞  舞不停  舞不執  舞眾生  邀您共舞
  我醉君且舞  是第一支舞  也是最後一支舞
帥哥和美女  不想獨舞想雙舞  舞走寂寞舞歡樂
  舞出真心  舞出真我  雲飛起舞揮灑眾生舞
    我在生活  我在舞蹈  舞我兩忘
隨緣起舞  隨心起舞  隨喜起舞  隨她起舞
 舞者如風  舞者如林  舞者如火  舞者如山
  在有星星的晚上跳舞
                      白天的日子才會燦爛
  舞天舞地舞在樂音裡  舞你舞我舞情舞愛
    來時舞  去時舞  想雙舞  卻獨舞
 紅塵來去  轉眼成空  流轉盡情  皆因愛舞
舞在秋季舞向冬  舞人舞身舞心  舞來又舞去
        愛  沒有明天  舞  只有當前
        舞起舞落  舞不回  狂舞  舞
LONG);
	setup();
	replace_program(ROOM);
}
