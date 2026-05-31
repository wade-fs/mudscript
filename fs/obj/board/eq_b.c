inherit BULLETIN_BOARD;
								
void create()
{
	set_name("ＥＱ事務板",({"EQ stuff board", "board"}));
	set("location","/open/wiz/eq");
	set("board_id","eq_b");
	set("long",	"有關EQ報備申請討論專用。\n");
	setup();
	set("capacity", 30);
	// replace_program(BULLETIN_BOARD);
}
							
