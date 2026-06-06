inherit ROOM;
void create() {
	set( "short", "血痕居-少林六合拳" );
	set( "owner", "holeman" );
	set( "build", 10510 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room522.c",
		"southwest" : "/open/clan/sky-wu-chi/room/room519",
		"south"     : "/open/clan/sky-wu-chi/room/room521.c",
	]) );
	set( "long", @LONG

六合拳法羅王傳，五子登科四海旋，大虎抱頭觀英姿，三手出掌鎮山川，

雙手推開迎面崖，一足踢開萬重山，轉身飛腳騰九霄，回馬一槍神通顯，

乘勝再使沖天炮，三搖鐵拳全局安，風雲無常黃風卷，左右出拳旋坤乾，

雙手撥開千層浪，跳步尋穴避風關，上下三掌扛手妙，再使兩槍架山巒，

乘機回周側耳炮，見縫插針進雙拳，轉身單叉山臥虎，誘引魔鬼進伏圈，

伸腿一潑掃巨森，鷂子讚林凱歌顏，偶遇虎豹重交戰，銅臂一挑虎背斷，

三戰六合攻守循，渾似金雞鬥鵪鶉，將遇良才勇鬥前，六合拳法冶真金。



LONG);
	setup();
	replace_program(ROOM);
}
