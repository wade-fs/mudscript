inherit ROOM;
void create() {
	set( "short", "$HIY$地$HIC$窖$NOR$" );
	set( "exits", ([
		"up"        : "/open/clan/time-limit/room/room63",
	]) );
	set( "long", @LONG
地窖旁的火光搖曳著,照亮一條通往地底的樓梯,底下有陰風吹上來,
讓人不禁豎起雞皮疙瘩,往下走時忽然傳來陣陣的顫音,原來是
差點沒頭的尼克在舉辦死亡宴會,他請了一團幽靈演奏死亡交響曲,
聽起來真是讓人毛骨悚然,宴會上的食物都是些腐敗的魚和爛掉的菜,
對幽靈來說這可是美味的佳餚呢

LONG);
	setup();
	replace_program(ROOM);
}
