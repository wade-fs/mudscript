inherit BULLETIN_BOARD;

void create()
{
	set_name("區域討論版", ({ "area board", "board" }) );
	set("location", "/open/wiz/area");
	set("board_id", "area_b");
	set("long", @LONG
這是專門提供巫師們申請新區域或者有人口流動的紀錄用的
例如, 有誰想負責某一區域? 有誰想卸任? 有誰想加入某一區域?
有誰退出某一區域? 或者甲區域想弄個任務, 請求乙區域支援..
LONG);
	setup();
	set("capacity", 50);
}
