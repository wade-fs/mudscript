inherit ROOM;
void create() {
	set( "short", "$HIC$微笑$HIY$絕世匕首$HIW$收藏室$NOR$" );
	set( "owner", "salicili" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/killer/headkill/obj/world_dag",
		"amount2"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room370",
	]) );
	set( "build", 10323 );
	set( "long", @LONG

ㄅㄆㄇㄈㄉㄊㄋㄌㄍㄎㄏ　ㄅㄆㄇㄈㄉㄊㄋㄌㄍㄎㄏㄐ;迷迷濛濛　你給的夢　出現裂縫　隱隱作痛;怎麼溝通　你都沒空　說我不懂　說了沒用;他的笑容　有何不同　在你心中　我不再受寵;我的天空　是雨是風　還是彩虹　你在操縱;;恨自己真的沒用　情緒激動;一顆心到現在還在抽痛;還為分手前那句抱歉　在感動;;穿梭時間的畫面的鐘　從反方向　開始移動;回到當初愛你的時空　停格內容　不忠;;所有回憶對著我進攻　我的傷口　被你拆封;誓言太沉重淚被縱容　臉上洶湧　失控;;RAP~ 城市霓虹　不安跳動　染紅夜空;過去種種　像一場夢　不敢去碰　一想就痛;心碎內容　每一秒鐘　都有不同　你不懂;連一句珍重　也有苦衷　也不想送;;寒風中　廢墟煙囪　停止轉動　一切落空;在人海中　盲目跟從　別人的夢　全面放縱;恨沒有用　療傷止痛　不再感動　沒有夢;痛不知輕重　淚水鮮紅　全面放縱

LONG);
	setup();
	replace_program(ROOM);
}
