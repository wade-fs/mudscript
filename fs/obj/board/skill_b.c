inherit BULLETIN_BOARD;

void create()
{
	set_name("技能與任務專用版",({"skill & quest board", "board"}));
	set("location","/open/wiz/fund_office");
	set("board_id","skill_b");
	set("long",	"天聽自我民聽，眾巫師有話就留，沒話快滾\n");
	setup();
	set("capacity", 30);
}
