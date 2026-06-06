inherit ROOM;
void create() {
	set( "short", "夢心谷" );
	set( "owner", "poll" );
	set( "object", ([
		"amount2"  : 90000,
		"amount10" : 1,
		"file8"    : "/open/killer/headkill/obj/e_dag",
		"amount7"  : 1,
		"file4"    : "/open/killer/obj/hate_knife",
		"file6"    : "/daemon/class/fighter/armband",
		"amount1"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"amount9"  : 1,
		"file3"    : "/open/killer/obj/bellstar",
		"amount8"  : 1,
		"file9"    : "/open/killer/obj/dagger",
		"file10"   : "/open/sky/obj/lucky_grasslink",
		"file2"    : "/open/killer/obj/hate_knife",
		"amount3"  : 40168,
		"file5"    : "/open/killer/headkill/obj/world_dag",
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"file7"    : "/open/killer/headkill/obj/w_dag",
		"amount4"  : 90000,
	]) );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room105.c",
		"south"     : "/open/clan/13_luck/room/room251",
		"north"     : "/open/clan/13_luck/room/room250.c",
	]) );
	set( "build", 10162 );
	set( "light_up", 1 );
	set( "long", @LONG

    夢心谷是十三吉祥裡的一處人間仙境，谷裡長滿了各式各樣的奇
花異草及飛禽走獸，空氣中更隨處可聞到一股淡淡的芳香氣味，令人
沉醉不已不過自從三年前一代變態～有 逆天魔醫 之稱的小草住進此
處之後一切就都變了!!各式各樣的奇花異草變成毒花毒草，飛禽走獸
則被抓去做著慘無人道的實驗，空氣中的芳香氣味更已被濃厚的血腥
味所取代，突然你聽到一聲悽厲的慘叫聲從谷裡傳出，想必又是那變
態魔醫又在做恐怖的實驗了，想到這，你不由的提起腳跟快步離開此
處，深怕自己成為下一個實驗對象........

LONG);
	setup();
	replace_program(ROOM);
}
