inherit ROOM;
void create() {
	set( "short", "血痕居-炎熱地獄" );
	set( "owner", "holeman" );
	set( "build", 15897 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room529.c",
		"southwest" : "/open/clan/sky-wu-chi/room/room528",
		"south"     : "/open/clan/sky-wu-chi/room/room531",
	]) );
	set( "long", @LONG

    一個像三千大千世界那麼大的大鍋中，充滿著沸騰的銅漿鐵汁
，眾生在裡面受著烹煮的煎熬劇苦。這就像人把鍋中的油熱了以後
，將活生生的海鮮放在鍋中，認為這樣比較新鮮好吃。有時看到有
些活魚因為痛苦而跳起來，還會用鏟子把它壓一壓。地獄的眾生也
是被這種方式壓著烹煮。

    這個地獄眾生的壽命是：人間一千六百年是他化自在天的一天
，他化自在天的一萬六千年等於是炎熱地獄的一天，他們要在此受
一萬六千年。


LONG);
	setup();
	replace_program(ROOM);
}
