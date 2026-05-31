inherit BULLETIN_BOARD;
void create()

{


set_name("內閣版",({ "wizthing board ","board"}));
	set("location","/open/wiz/hall3");

	set("board_id","wiztt_b");
	set("long", "就是人事異動啦,報告啦,考核啦,都要post在這哦");

	setup();
	set("capacity", 100);
	}
