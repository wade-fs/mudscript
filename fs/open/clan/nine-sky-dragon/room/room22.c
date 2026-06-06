inherit ROOM;
void create() {
	set( "short", "東京鐵塔的幸福" );
	set( "owner", "yaoblade" );
	set( "object", ([
		"amount10" : 1,
		"amount4"  : 1,
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount7"  : 1,
		"amount1"  : 1,
		"amount8"  : 1,
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount6"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
	]) );
	set( "build", 10992 );
	set( "exits", ([
		"north"     : "/open/clan/nine-sky-dragon/room/room20",
	]) );
	set( "long", @LONG
還記得那個有雨的下午　我們用紅筆圈起的東京地圖 
說好一起追逐　偶像劇的旅途　當作這份愛最好的禮物 
如果今天你還在我身邊　你會牽著我在涉谷街頭漫步 
只是愛已結束　你走到了遠處　我看著台北心裡慢慢起霧  
Good-Bye　東京鐵塔的祝福　雖然這份愛只有我沒退出 
你懷裡的溫度　密密把我包住　就算從今後我要自己面對冷酷 
Good-Bye　在我身邊的大樹　我想你忘了說過只給我保護 
我能享受獨處　卻不承認孤獨　靜靜留在昨天　一個人　走兩個人的路 
LONG);
	setup();
	replace_program(ROOM);
}
