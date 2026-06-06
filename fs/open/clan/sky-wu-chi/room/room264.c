inherit ROOM;
void create() {
	set( "short", "$HIW$【$HIC$蘭刀$HIR$隱閣$HIW$】$NOR$" );
	set( "owner", "hild" );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "light_up", 1 );
	set( "build", 862 );
	set( "item_desc", ([
		"檀香正在爐中冉冉地燒著" : @ITEM
檀香正在爐中冉冉地燒著
ITEM,
	]) );
	set( "long", @LONG
房內此刻燈火正光明萬鑽蘭刀放在尾端一張紫檀方桌上。故老相傳，這萬鑽蘭刀
乃是元世祖忽必烈汗底定中原後，命宮中匠人以碧玉雕葉、蒼玉為瓣、碧璽刻成刀
型，嵌在一座黑釉瓷擬成的土基上，做成一朵蘭花的模樣，不知為何竟在此出現。
接著映入你眼簾的是排列整齊的各式刀劍，隱隱散發出嗜血的魔氣，令你不禁運氣
調息，避免心緒大受干擾，如此邪氣逼迫你不得不放棄待在此處的念頭。

LONG);
	setup();
	replace_program(ROOM);
}
