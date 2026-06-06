inherit ROOM;
void create() {
	set( "short", "瑰玫花房" );
	set( "build", 95 );
	set( "owner", "pobka" );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room84",
	]) );
	set( "long", @LONG
人棲石洞不算好，富貴難比一字刀，三更練武十八般，師徒足印三隻半。
飛龍破怒雨而降，金鴒乘殘風而終，天生萬物不同類，何故兩心永相隨。
自嘆刀劍無高人，氣入荒山不出門;狂脈仍流極道中，斷層不見接武林
好漢一生不流淚, 走遍天下為了誰﹖恨深緣盡情未絕, 難忘可敬一仇人
豪氣橫掃三千年，壯志直擘九重天;來往銀河算星斗，非仙非神非聖賢
今生今世傳一徒，為師難入百名簿，十三墳上伴夕陽，春去秋來又幾渡。
黑時猶有骨，紅處便成灰，四處皆幽境，生死讓幾人。
LONG);
	setup();
	replace_program(ROOM);
}
