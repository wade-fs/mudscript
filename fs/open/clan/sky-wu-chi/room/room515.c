inherit ROOM;
void create() {
	set( "short", "血痕居-五毒" );
	set( "owner", "holeman" );
	set( "build", 10355 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room518.c",
	]) );
	set( "long", @LONG

    偏安一隅太平鄉，不甘沒落出苗疆。
    奇花異草心最愛，天下美景無心賞。
    毒砂迷霧成晚霞，冰藍玄晶作海浪。
    血手毒殺神難救，雜難藥經毒草香。
    雷動九天鎮山嶽，幽冥骷髏笑穹蒼。
    無形毒蠱是奇寶，赤炎蝕天日無光。
    穿心毒刺滅閻羅，萬蠱蝕心誰能防。
    天罡地煞揚威風，朱蛤青冥無人擋。
    移花接玉向天齊，五毒奇經胸中藏。
    武林浩蕩無盡處，江湖深遠任翱翔。



LONG);
	setup();
	replace_program(ROOM);
}
