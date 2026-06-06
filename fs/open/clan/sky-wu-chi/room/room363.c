inherit ROOM;
void create() {
	set( "short", "小武者ㄉ溫暖ㄉ窩" );
	set( "owner", "sblade" );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room257",
	]) );
	set( "item_desc", ([
		"山" : @ITEM
一座粉大ㄉ山
ITEM,
	]) );
	set( "light_up", 1 );
	set( "build", 10257 );
	set( "long", @LONG
    這裡是小武者的門口﹐只見牆上掛著牌子寫著﹕
     
       【 帥哥派第三代掌門 「超級帥哥」小武者之陵寢 】
 
       【 黃 】                               【 一 】
       【 雲 】                               【 生 】
       【 白 】                               【 一 】
       【 髮 】                               【 笑 】
       【 雪 】                               【 莫 】
       【 蒼 】                               【 知 】
       【 蒼 】                               【 愁 】
 
 

LONG);
	setup();
	replace_program(ROOM);
}
