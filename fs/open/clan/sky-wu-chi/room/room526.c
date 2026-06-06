inherit ROOM;
void create() {
	set( "short", "血痕居-通臂拳" );
	set( "owner", "holeman" );
	set( "build", 14188 );
	set( "exits", ([
		"northeast" : "/open/clan/sky-wu-chi/room/room519",
		"north"     : "/open/clan/sky-wu-chi/room/room520.c",
		"east"      : "/open/clan/sky-wu-chi/room/room514.c",
	]) );
	set( "long", @LONG

通臂拳簡學非難。摔拍穿劈圈與鑽。穿拍摔撢打面額。肘靠撩抓掖肢髖。

開合虛實傳心法。左右前後任意盤。砸釘中拳凶且猛。劈搧展手長又寬。 

掄臂搖根開關節。摔腕抖勁貫指端。曲膝提腿仙鶴步。輾足磨跟蛟龍蟠。

操手推肩活肩骨。屈膝坐馬固下盤。金雞抖翎龍合口。白猿獻果虎闖欄。

彎腰挺膝舒背脊。轉頸擰身健百官。馬奔鷂穿如閃電。鵬展鷹飛類風搏。

空發拳擲鬆透透。呼吸氣運轉團團。青龍探爪取天突。靈貓撲鼠掠人冠。

抖震功能暢血脈。吐衲效求實內丹。螃蟹擺步跟群捉。五鬼鬧判從腿看。 

來去圈引世少有。上下劈拍敵膽寒。步有躥蹦跳躍閃。勁分冷急脆硬彈。

手臂抹搓隱形跡。腳掌震踏響雲干。萬變歸根唯一法。勤練功深自可觀。 



LONG);
	setup();
	replace_program(ROOM);
}
